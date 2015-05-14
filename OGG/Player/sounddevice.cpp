#include "sounddevice.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <vorbis/codec.h>

SDL_AudioSpec 
SoundDevice::desired() const
{
	return m_desired;
}

SDL_AudioSpec 
SoundDevice::obtained() const
{
	return m_obtained;
}

SDL_AudioSpec 
SoundDevice::wavSpec() const
{
	return m_wavSpec;
}

uint32_t 
SoundDevice::wavLen() const
{
	return m_wavLen;
}

uint8_t *
SoundDevice::wavBuffer() const
{
	return m_wavBuffer;
}
	
void 
SoundDevice::open(Sound *sound)
{
  fprintf(stderr, " IN: sounddevice.cpp -> open\n");

	int rc = SDL_Init(SDL_INIT_AUDIO);
	
	if (rc != 0) {
		cerr << "Erro na inicializacao do modulo de audio: " <<
			SDL_GetError() << endl;
		return;
	}
	
	m_desired.freq = 44100;
	m_desired.format = AUDIO_S16;
	m_desired.channels = 2;
	m_desired.samples = 4096;
	m_desired.callback = SoundCTRL::callback;
	m_desired.userdata = (void *) sound;
	
	rc = SDL_OpenAudio(&m_desired, &m_obtained);

	if (rc != 0)
	{
		cerr << "Erro na abertura do dispositivo de audio: " <<
			SDL_GetError() << endl;
		SDL_Quit();
		return;
	}
	
  fprintf(stderr, " OUT: sounddevice.cpp -> open\n");
}

uint8_t* oggdec(char* path, SDL_AudioSpec *spec, uint8_t **m_wavBuffer, uint32_t *m_wavLen){
  ogg_sync_state   oy; /* sync and verify incoming physical bitstream */
  ogg_stream_state os; /* take physical pages, weld into a logical
                          stream of packets */
  ogg_page         og; /* one Ogg bitstream page.  Vorbis packets are inside */
  ogg_packet       op; /* one raw packet of data for decode */
  
  vorbis_info      vi; /* struct that stores all the static vorbis bitstream
                          settings */
  vorbis_comment   vc; /* struct that stores all the bitstream user comments */
  vorbis_dsp_state vd; /* central working state for the packet->PCM decoder */
  vorbis_block     vb; /* local working space for packet->PCM decode */
  
  char *buffer;
  int  bytes;

  FILE * pFile;
  pFile = fopen (path,"r");

  if (pFile==NULL)
  {
    fprintf(stderr, "Erro: not open ogg file!");
  }

  /********** Decode setup ************/

  ogg_sync_init(&oy); /* Now we can read pages */
  
  while(1){ /* we repeat if the bitstream is chained */
    int eos=0;
    int i;

    /* grab some data at the head of the stream.  We want the first page
       (which is guaranteed to be small and only contain the Vorbis
       stream initial header) We need the first page to get the stream
       serialno. */

    /* submit a 4k block to libvorbis' Ogg layer */
    buffer=ogg_sync_buffer(&oy,4096);
    bytes=fread(buffer,1,4096,pFile);
    ogg_sync_wrote(&oy,bytes);
    
    /* Get the first page. */
    if(ogg_sync_pageout(&oy,&og)!=1){
      /* have we simply run out of data?  If so, we're done. */
      if(bytes<4096)break;
      
      /* error case.  Must not be Vorbis data */
      fprintf(stderr,"Input does not appear to be an Ogg bitstream.\n");
      exit(1);
    }
  
    /* Get the serial number and set up the rest of decode. */
    /* serialno first; use it to set up a logical stream */
    ogg_stream_init(&os,ogg_page_serialno(&og));
    
    /* extract the initial header from the first page and verify that the
       Ogg bitstream is in fact Vorbis data */
    
    /* I handle the initial header first instead of just having the code
       read all three Vorbis headers at once because reading the initial
       header is an easy way to identify a Vorbis bitstream and it's
       useful to see that functionality seperated out. */
    
    vorbis_info_init(&vi);
    vorbis_comment_init(&vc);
    if(ogg_stream_pagein(&os,&og)<0){ 
      /* error; stream version mismatch perhaps */
      fprintf(stderr,"Error reading first page of Ogg bitstream data.\n");
      exit(1);
    }
    
    if(ogg_stream_packetout(&os,&op)!=1){ 
      /* no page? must not be vorbis */
      fprintf(stderr,"Error reading initial header packet.\n");
      exit(1);
    }
    
    if(vorbis_synthesis_headerin(&vi,&vc,&op)<0){ 
      /* error case; not a vorbis header */
      fprintf(stderr,"This Ogg bitstream does not contain Vorbis "
              "audio data.\n");
      exit(1);
    }
    
    /* At this point, we're sure we're Vorbis.  We've set up the logical
       (Ogg) bitstream decoder.  Get the comment and codebook headers and
       set up the Vorbis decoder */
    
    /* The next two packets in order are the comment and codebook headers.
       They're likely large and may span multiple pages.  Thus we reead
       and submit data until we get our two pacakets, watching that no
       pages are missing.  If a page is missing, error out; losing a
       header page is the only place where missing data is fatal. */
    
    i=0;
    while(i<2){
      while(i<2){
        int result=ogg_sync_pageout(&oy,&og);
        if(result==0)break; /* Need more data */
        /* Don't complain about missing or corrupt data yet.  We'll
           catch it at the packet output phase */
        if(result==1){
          ogg_stream_pagein(&os,&og); /* we can ignore any errors here
                                         as they'll also become apparent
                                         at packetout */
          while(i<2){
            result=ogg_stream_packetout(&os,&op);
            if(result==0)break;
            if(result<0){
              /* Uh oh; data at some point was corrupted or missing!
                 We can't tolerate that in a header.  Die. */
              fprintf(stderr,"Corrupt secondary header.  Exiting.\n");
              exit(1);
            }
            vorbis_synthesis_headerin(&vi,&vc,&op);
            i++;
          }
        }
      }
      /* no harm in not checking before adding more */
      buffer=ogg_sync_buffer(&oy,4096);
      bytes=fread(buffer,1,4096,pFile);
      if(bytes==0 && i<2){
        fprintf(stderr,"End of file before finding all Vorbis headers!\n");
        exit(1);
      }
      ogg_sync_wrote(&oy,bytes);
    }
    
    /* Throw the comments plus a few lines about the bitstream we're
       decoding */
    {
      char **ptr=vc.user_comments;
      while(*ptr){
        fprintf(stderr,"%s\n",*ptr);
        ++ptr;
      }
      fprintf(stderr,"\nBitstream is %d channel, %ldHz\n",vi.channels,vi.rate);
      fprintf(stderr,"Encoded by: %s\n\n",vc.vendor);

      spec->freq = vi.rate;
		  spec->format = AUDIO_S16;
		  spec->channels = vi.channels;
		  spec->silence = 0;
		  spec->samples = 4096;
		  spec->callback = NULL;
		  spec->userdata = NULL;

      fprintf(stderr, " sounddevice.cpp VARIABLE VALUE: spec->freq: %d\n", spec->freq);
      fprintf(stderr, " sounddevice.cpp VARIABLE VALUE: spec->channels: %hhu\n", spec->channels);
    }
    
    /* OK, got and parsed all three headers. Initialize the Vorbis
       packet->PCM decoder. */
    vorbis_synthesis_init(&vd,&vi); /* central decode state */
    vorbis_block_init(&vd,&vb);     /* local state for most of the decode
                                       so multiple block decodes can
                                       proceed in parallel.  We could init
                                       multiple vorbis_block structures
                                       for vd here */
    vector < pair<short *, int32_t> >buffers;
    spec->size = 0;


    /* The rest is just a straight decode loop until end of stream */
    while(!eos){
      while(!eos){
        int result=ogg_sync_pageout(&oy,&og);
        if(result==0)break; /* need more data */
        if(result<0){ /* missing or corrupt data at this page position */
          fprintf(stderr,"Corrupt or missing data in bitstream; "
                  "continuing...\n");
        }else{
          ogg_stream_pagein(&os,&og); /* can safely ignore errors at
                 
                                         this point */
          while(1){
            result=ogg_stream_packetout(&os,&op);

            if(result==0)break; /* need more data */
            if(result<0){ /* missing or corrupt data at this page position */
              /* no reason to complain; already complained above */
            }else{
              float **pcm;
              int samples;
              if(vorbis_synthesis(&vb,&op)==0) /* test for success! */
                vorbis_synthesis_blockin(&vd,&vb);
              while((samples=vorbis_synthesis_pcmout(&vd,&pcm))>0){
              	spec->size += samples;

              	//-------

              	short *bf = new short[samples];
              	memset(bf, 0, samples*sizeof(short));
              	

              	for (int i = 0; i < vi.channels; ++i)
              	{
              		for (int j = 0; j < samples; ++j)
              		{
              			int s = pcm[i][j] * 32767.0 + 0.5;

              			if (s > 32767)
              			{
              				s = 32767;
              			} 

              			if (s < -32768)
              			{
              				s = -32768;
              			}

              			bf[j] += s;
              		}
              	}

              	buffers.push_back(make_pair(bf, samples));
              	//--------

                //output(pcm, samples, &vi);
                vorbis_synthesis_read(&vd,samples); /* tell libvorbis how
                                                   many samples we
                                                   actually consumed */
              }     
            }
          }
          if(ogg_page_eos(&og))eos=1;
        }
      }

      if(!eos){
        buffer=ogg_sync_buffer(&oy,4096);
        bytes=fread(buffer,1,4096,pFile);
        ogg_sync_wrote(&oy,bytes);
        if(bytes==0)eos=1;
      }
    }
    
	  *m_wavLen = spec->size;
    *m_wavBuffer = new uint8_t[spec->size];
    uint32_t count = 0;

    fprintf(stderr, "\n sounddevice.cpp VARIABLE SIZE: buffers: %lu", buffers.size());

    for (int i = 0; i < buffers.size(); ++i)
    {
  	 	memcpy(*m_wavBuffer+count, buffers[i].first, buffers[i].second*sizeof(short));
    	count += buffers[i].second;
    }

    /* clean up this logical bitstream; before exit we see if we're
       followed by another [chained] */

    ogg_stream_clear(&os);
  
    /* ogg_page and ogg_packet structs always point to storage in
       libvorbis.  They're never freed or manipulated directly */
    
    vorbis_block_clear(&vb);
    vorbis_dsp_clear(&vd);
    vorbis_comment_clear(&vc);
    vorbis_info_clear(&vi);  /* must be called last */
  }

  /* OK, clean up the framer */
  ogg_sync_clear(&oy);
  
  fprintf(stderr,"\nDone.\n");

  return *m_wavBuffer;
}

void
SoundDevice::openWAV(char *path)
{
	fprintf(stderr, " IN: sounddevice.cpp -> openWAV\n\n");

										
	if (oggdec(path, &m_wavSpec, &m_wavBuffer, &m_wavLen) == NULL)
	{
    fprintf(stderr, " IN: sounddevice.cpp -> openWAV : error\n\n");    
		cout << "Falha! " << SDL_GetError() << endl;
		SDL_CloseAudio();
		SDL_Quit();
		return;
	}

  fprintf(stderr, "\n OUT: sounddevice.cpp -> openWAV\n");
	
	//cout << "SDL_LoadWAV: Ok!" << endl;
}

void 
SoundDevice::audioConverter()
{
  fprintf(stderr, " IN: sounddevice.cpp -> audioConverter\n");

  fprintf(stderr, " sounddevice.cpp VARIABLE VALUE: m_obtained.format: %hu\n", m_obtained.format);
  fprintf(stderr, " sounddevice.cpp VARIABLE VALUE: m_obtained.freq: %d\n", m_obtained.freq);
  fprintf(stderr, " sounddevice.cpp VARIABLE VALUE: m_obtained.channels: %hhu\n", m_obtained.channels);

	int rc = SDL_BuildAudioCVT(&m_cvt, m_wavSpec.format, m_wavSpec.channels, m_wavSpec.freq,
			m_obtained.format, m_obtained.channels, m_obtained.freq);

	if (rc != 0)
	{

		cout << "audioConverter(): Falha! " << SDL_GetError() << endl;
		SDL_FreeWAV(m_wavBuffer);
		SDL_Quit();

		return;
	}
	
	m_cvt.len = m_wavLen;
	uint8_t *wavNewBuf = (uint8_t *) malloc(m_cvt.len * m_cvt.len_mult);

	if (wavNewBuf == NULL)
	{
		cerr << "audioConverter(): Sem memoria para um novo buffer!" << endl;
		SDL_FreeWAV(m_wavBuffer);
		SDL_CloseAudio();
		SDL_Quit();

		return;
	}
	
	memcpy(wavNewBuf, m_wavBuffer, m_wavLen);
	m_cvt.buf = wavNewBuf;
	
	rc = SDL_ConvertAudio(&m_cvt);

	if (rc != 0)
	{
		cerr << "audioConverter(): Erro na conversao do audio!" << endl;
		SDL_FreeWAV(m_wavBuffer);
		free(wavNewBuf);
		SDL_CloseAudio();
		SDL_Quit();

		return;
	}
	
	SDL_FreeWAV(m_wavBuffer);

  fprintf(stderr, " OUT: sounddevice.cpp -> audioConverter\n");

	//cout << "audioConverter(): Ok!" << endl;
}

void 
SoundDevice::setSound(Sound *sound)
{
  fprintf(stderr, " IN: sounddevice.cpp -> setSound\n");

	SDL_LockAudio();

	sound->m_position = 0;
	sound->setBuffer(m_cvt.buf);
	sound->setSize(m_cvt.len * m_cvt.len_mult);
	
	SDL_UnlockAudio();
  
  fprintf(stderr, " OUT: sounddevice.cpp -> setSound\n");	
	//cout << "setSound: Ok!" << endl;
}












