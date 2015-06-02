#include "ui_meta.h"
#include <vorbis/codec.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lgmk_ogg.h"

Ui_meta::Ui_meta(const char *path)
{
	fprintf(stderr, " IN: ui_meta.cpp -> Ui_meta\n");

	playing = true;
	
	markIndex = 0;
	subMarkIndex = 0;
	level = 1;
	
	duration = 9580548;

	 /*wave = Wave::load(path);
	
	 vector<Chunk *> subchunks = wave->subchunks();
	
	 for(vector<Chunk *>::iterator it = subchunks.begin(); it != subchunks.end(); it++)
	 {
	 	lgmk = dynamic_cast<Lgmk *>(*it);
		
	 	if(lgmk != 0)
	 		break;
	 }
	
	 for(vector<Chunk *>::iterator it = subchunks.begin(); it != subchunks.end(); it++)
	 {
	 	Generic *data = dynamic_cast<Generic *>(*it);
		
	 	if(data != 0 && data->id() == "data")
	 	{
	 		duration = data->size();
	 		break;
	 	}
			
	 }
	
	 for(vector<Chunk *>::iterator it = subchunks.begin(); it != subchunks.end(); it++)
	 {
	 	format = dynamic_cast<Format *>(*it);
		
	 	if(format != 0)
	 		break;
	 }
    */
    //format = new Format();
    //Data *data = new Data();
    //format->decode(*data, 0);


	 //duration /= (format->sampleRate() * format->numChannels());
	 //duration /= (format->bitsPerSample()/8);
	 
	
    //if(lgmk == 0)
	 //{		
	/*lgmk = new Lgmk;
		
	lgmk->add_mark(0);
	lgmk->add_markName("NONE");
		
	lgmk->add_mark(duration);
	lgmk->add_markName("NONE");
		
	lgmk->add_subMark(0);
	lgmk->add_subMarkName("NONE");
		
	lgmk->add_subMark(duration);
	lgmk->add_subMarkName("NONE");
	 //}
	
	m_marks = lgmk->marks();
	m_marksNames = lgmk->marksNames();
	
	m_subMarks = lgmk->subMarks();
	m_subMarksNames = lgmk->subMarksNames();*/

	fprintf(stderr, " OUT: ui_meta.cpp -> Ui_meta\n");
}

void 
Ui_meta::setMetaLabels(const char *path)
{
	fprintf(stderr, " IN: ui_meta.cpp -> setMetaLabels\n");
	/*vector<Chunk *> subchunks = wave->subchunks();
	
	for(vector<Chunk *>::iterator it = subchunks.begin(); it != subchunks.end(); it++)
	{
		meta = dynamic_cast<Meta *>(*it);
		
		if(meta != 0)
			break;
	}
	
	if(meta == 0)
	{
		meta = new Meta;
	}*/
	
	//QString title = QString::fromStdString(meta->title());
	//QString author = QString::fromStdString(meta->author());
	//QString language = QString::fromStdString(meta->language());
	//QString publisher = QString::fromStdString(meta->publisher());
	//QString year = QString::fromStdString(meta->year());
	//QString address = QString::fromStdString(meta->address());
	//QString pages = QString::fromStdString(meta->pages());

    /* 
     * GET META OGG
     */

    ogg_sync_state   oy; /* sync and verify incoming physical bitstream */
    ogg_stream_state os; /* take physical pages, weld into a logical
                          stream of packets */
    ogg_page         og; /* one Ogg bitstream page.  Vorbis packets are inside */
    ogg_packet       op; /* one raw packet of data for decode */
  
    vorbis_info      vi; /* struct that stores all the static vorbis bitstream
                          settings */ 
    vorbis_comment   vc; /* struct that stores all the bitstream user comments */
    lgmk lm;
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
  
        /*Get the serial number and set up the rest of decode. */
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
 
            int result=ogg_stream_packetout(&os, &op);

            if(result == 0) break;
            result=lgmk_synthesis_headerin(&lm, &op);
            if(result<0)
            {
                fprintf(stderr,"Corrupt lgmk header.  Exiting.\n");
                exit(1);
            }

            ogg_sync_wrote(&oy,bytes);
        }
    
        {
            //metas
            char **ptr=vc.user_comments;
            vector <char *>fields;
            int index;
            while(*ptr){
                char *t = strchr(*ptr, '=');
                index = (int)(t - *ptr);
                string s = *ptr;
                s.erase(0, index+1);
                fields.push_back(strdup(s.c_str()));
                ++ptr;
            }
            int k=0;
            QString title = QString::fromStdString(fields[k]);
            ++k;
	        QString author = QString::fromStdString(fields[k]);
	        ++k;
            QString language = QString::fromStdString(fields[k]);
	        ++k;
            QString publisher = QString::fromStdString(fields[k]);
	        ++k;
            QString address = QString::fromStdString(fields[k]);
	        ++k;
            QString pages = QString::fromStdString(fields[k]);
	        ++k;
            QString year = QString::fromStdString(fields[k]);

	        titleLabel->setText(title);
	        authorLabel->setText(author);
	        languageLabel->setText(language);
	        publisherLabel->setText(publisher); 
	        addressLabel->setText(address);
	        pagesLabel->setText(pages);
            yearLabel->setText(year);

            fprintf(stderr, "HEREEEEE");
            
            //marks
            char **ptr_lgmk=lm.user_lgmks;
            while(*ptr_lgmk)
            {
                fprintf(stderr, "%s\n", *ptr_lgmk);
                ++ptr_lgmk;
            }

            lgmk_wav = new Lgmk;
		
	        lgmk_wav->add_mark(0);
	        lgmk_wav->add_markName("INIT");
		    lgmk_wav->add_mark(10);
	        lgmk_wav->add_markName("TEN");
	        lgmk_wav->add_mark(duration);
	        lgmk_wav->add_markName("END");
	        
            lgmk_wav->add_subMark(0);
	        lgmk_wav->add_subMarkName("NONE");
		
	        lgmk_wav->add_subMark(duration);
	        lgmk_wav->add_subMarkName("NONE");
	
	        m_marks = lgmk_wav->marks();
	        m_marksNames = lgmk_wav->marksNames();
	
	        m_subMarks = lgmk_wav->subMarks();
	        m_subMarksNames = lgmk_wav->subMarksNames();
            
        }
        
        /* OK, got and parsed all three headers. Initialize the Vorbis
            packet->PCM decoder. */
        vorbis_synthesis_init(&vd,&vi); /* central decode state */
        vorbis_block_init(&vd,&vb);     /* local state for most of the decode
                                       so multiple block decodes can
                                       proceed in parallel.  We could init
                                       multiple vorbis_block structures
                                       for vd here */
        int convsize = 4096/vi.channels;

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
                                samples = (samples<convsize?samples:convsize);

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
        //clean
        ogg_stream_clear(&os);
        vorbis_block_clear(&vb);
        vorbis_dsp_clear(&vd);
        vorbis_comment_clear(&vc);
        vorbis_info_clear(&vi);
    }

    ogg_sync_clear(&oy);

    fprintf(stderr, " OUT: ui_meta.cpp -> setMetaLabels\n");
}

void 
Ui_meta::setMarksLabels()
{
	QString firstMark = QString::fromStdString(m_marksNames[0]);
	markLabel->setText(firstMark);
	markLabel->setAlignment(Qt::AlignCenter);
	
	QString firstSubMark  = QString::fromStdString(m_subMarksNames[0]);
	subMarkLabel->setText(firstSubMark);
	subMarkLabel->setAlignment(Qt::AlignCenter);
	
	QString level = QString::fromStdString("Level 1");
	levelLabel->setText(level);
	levelLabel->setAlignment(Qt::AlignCenter);
}

void 
Ui_meta::initLCDDisplay()
{
	lcdNumber->setNumDigits(7);
	lcdNumber->setPalette(Qt::black);
	lcdNumber->display(QString::fromStdString("0.00:00"));	
}

void 
Ui_meta::initSlider()
{
	songSlider->setRange(0, duration);
}

void
Ui_meta::connections()
{
	connect(playOrPauseButton, SIGNAL(clicked()), this, SLOT(playOrPause()));
	
	connect(forwardButton,SIGNAL(clicked()), this, SLOT(next()));
	connect(rewindButton, SIGNAL(clicked()), this, SLOT(prev()));
	
	connect(upLevelButton, SIGNAL(clicked()), this, SLOT(levelUp()));
	connect(downLevelButton, SIGNAL(clicked()), this, SLOT(levelDown()));
	
	connect(fastforwardButton, SIGNAL(pressed()), this, SLOT(fastForward()));
	
	connect(fastrewindButton, SIGNAL(pressed()) , this, SLOT(fastRewind()));
	
	connect(songSlider, SIGNAL(valueChanged(int)) , this, SLOT(updateClock(int)));
	connect(songSlider, SIGNAL(valueChanged(int)) , this, SLOT(change_song_position(int)));
}

void
Ui_meta::playOrPause()
{
	fprintf(stderr, " IN: ui_meta.cpp -> playOrPause\n");

   	if(playing)
	{
		icon.addFile(QString::fromUtf8(":/images/pause.png"), QSize(), QIcon::Normal, QIcon::Off);

		emit pauseSound();
	}
	else
	{
		icon.addFile(QString::fromUtf8(":/images/start.png"), QSize(), QIcon::Normal, QIcon::Off);

		emit playSound();
	}

	playOrPauseButton->setIcon(icon);
	playing = !playing; 

	fprintf(stderr, " OUT: ui_meta.cpp -> playOrPause\n");
}

void 
Ui_meta::resetMarkLabels()
{
	markIndex = 0;
	subMarkIndex = 0;
	
	QString firstMark = QString::fromStdString(m_marksNames[0]);
	markLabel->setText(firstMark);
	markLabel->setAlignment(Qt::AlignCenter);
	
	QString firstSubMark  = QString::fromStdString(m_subMarksNames[0]);
	
	subMarkLabel->setText(firstSubMark);
	subMarkLabel->setAlignment(Qt::AlignCenter);
}

void 
Ui_meta::resetClockAndSlider()
{
	songSlider->setValue(0);
	lcdNumber->setPalette(Qt::black);
	lcdNumber->display(QString::fromStdString("0.00:00"));
}

void 
Ui_meta::levelUp()
{
	level = 1;
	
	QString nivelLabel = QString::fromStdString("Level 1");
	levelLabel->setText(nivelLabel);
}

void 
Ui_meta::levelDown()
{
	level = 2;
	
	QString nivelLabel = QString::fromStdString("Level 2");
	levelLabel->setText(nivelLabel);
	
	//cout << "NIVEL "<< level << endl;
}


void
Ui_meta::fastForward()
{
	//cout << "FAST FORWARD" << endl;
		
	emit forwardTime(format);
}


void
Ui_meta::fastRewind()
{
	//cout << "FAST REWIND" << endl;
	
	emit rewindTime(format);
}

void
Ui_meta::next()
{
	//cout << "NIVEL "<< level << endl;
	if(level == 1)
	{
		forward();
	}else if(level == 2)
	{
		forwardSubMark();
	}
	
	synchronizeMarks();
}

void
Ui_meta::prev()
{
	//cout << "NIVEL "<< level << endl;
	if(level == 1)
	{
		rewind();
	}else if(level == 2)
	{
		rewindSubMark();
	}
		
	synchronizeMarks();
}

void
Ui_meta::forward()
{
	markIndex++;
	//cout << "(forward) markIndex: " << markIndex <<endl;
	
	if(markIndex >= (int) m_marks.size())
	{
		resetMarkLabels();
		
		emit nextMark(duration, format);
		
	}else
	{
		emit nextMark(m_marks[markIndex], format);
	}
}

void
Ui_meta::rewind()
{
	markIndex--;
	//cout << "(rewind) markIndex: " << markIndex <<endl;
	
	QString mark;
	
	if(markIndex < 0)
	{
		markIndex = 0;
		subMarkIndex = 0;
		
		emit prevMark(0, format);
	}else
	{
		emit prevMark(m_marks[markIndex], format);
	}
}

void
Ui_meta::forwardSubMark()
{
	subMarkIndex++;
	//cout << "(forward SubMark) subMarkIndex: " << subMarkIndex <<endl;
	
	if(subMarkIndex >= (int) m_subMarks.size())
	{
		resetMarkLabels();

		emit nextMark(duration, format);
		
	}else
	{
		emit nextMark(m_subMarks[subMarkIndex], format);
	}
}

void
Ui_meta::rewindSubMark()
{
	subMarkIndex--;
	//cout << "(rewind SubMark) subMarkIndex: " << subMarkIndex <<endl;
	
	QString subMark;
	
	if(subMarkIndex < 0)
	{
		markIndex = 0;
		subMarkIndex = 0;
	    
		emit prevMark(0, format);
		
	}else
	{
		emit prevMark(m_subMarks[subMarkIndex], format);
	}
}


void
Ui_meta::synchronizeMarks()
{
	uint32_t position;
	QString mark;
	QString subMark;
	
	if(level == 1)
	{
		// << "SINCRONIZACÃO NIVEL 1!!!!" << endl;
		
		position = m_marks[markIndex];
		
		for(uint32_t i = 0; i < m_subMarks.size(); i++)
		{
			if(position == 0)
			{
				subMarkIndex = 0;
				break;
			}else if(m_subMarks[i] == position)
			{
				subMarkIndex = i;
		
				break;
			}else if(m_subMarks[i] > position)
			{
				subMarkIndex = i - 1;
				break;
			}
		}
		
		//cout << "\tmarkIndex: " << markIndex << endl;
		//cout << "\tsubMarkIndex: " << subMarkIndex << endl;
				
		//cout << "\tmarks: " << m_marks[markIndex] << endl;
		//cout << "\tsubMarks: " << m_subMarks[subMarkIndex] << endl;
		
		mark  = QString::fromStdString(m_marksNames[markIndex]);
		subMark = QString::fromStdString(m_subMarksNames[subMarkIndex]);
		
		markLabel->setText(mark);
		subMarkLabel->setText(subMark);
		
	}else if(level == 2)
	{
		//cout << "SINCRONIZACÃO NIVEL 2!!!!" << endl;
		
		position = m_subMarks[subMarkIndex];
		
		for(uint32_t i = 0; i < m_marks.size(); i++)
		{
			if(position == 0)
			{
				markIndex = 0;
				break;
				
			}else if(m_marks[i] > position)
			{
				markIndex = i - 1;
				
		
				break;
			}else if(m_marks[i] == position )
			{
				markIndex = i;
				break;
			}
		}
		
		//cout << "\tmarkIndex: " << markIndex << endl;
		//cout << "\tsubMarkIndex: " << subMarkIndex << endl;
		
		//cout << "\tmarks: " << m_marks[markIndex] << endl;
		////cout << "\tsubMarks: " << m_subMarks[subMarkIndex] << endl;
		
		mark  = QString::fromStdString(m_marksNames[markIndex]);
		subMark = QString::fromStdString(m_subMarksNames[subMarkIndex]);
		
		markLabel->setText(mark);
		subMarkLabel->setText(subMark);
	}
}

int 
Ui_meta::MarkIndex() const
{
	return markIndex;
}
	
int 
Ui_meta::SubMarkIndex() const
{
	return subMarkIndex;
}
	
void 
Ui_meta::setMarkIndex(int newMarkIndex)
{
	if(markIndex != newMarkIndex)
		markIndex = newMarkIndex;
}
	
void 
Ui_meta::setSubMarkIndex(int newSubMarkIndex)
{
	if(subMarkIndex != newSubMarkIndex)
		subMarkIndex = newSubMarkIndex;
}
	
Lgmk *
Ui_meta::getLgmk() const
{
	return lgmk_wav;
}

Format *
Ui_meta::getFormat() const
{
	return format;
}

vector<uint32_t> 
Ui_meta::marks() const
{
	return m_marks;
}

vector<uint32_t> 
Ui_meta::subMarks() const
{
	return m_subMarks;
}

void 
Ui_meta::changeMarksLabels()
{	
	QString mark;
	QString subMark;
	
	mark  = QString::fromStdString(m_marksNames[markIndex]);
	subMark = QString::fromStdString(m_subMarksNames[subMarkIndex]);
	
	markLabel->setText(mark);
	subMarkLabel->setText(subMark);	
}

void 
Ui_meta::updateClock(int time)
{
	int hours = time/3600;
	int minutes = time/60 - 60*hours;
	int seconds = time - 60*minutes - 3600*hours;
	
	string_stream << hours + '\0' << ".";
	
	if(minutes < 10)
	{
		string_stream << "0" << minutes + '\0' << ":";
	} else
	{
		string_stream << minutes + '\0' << ":";
	}
	
	if(seconds < 10)
	{
		string_stream << "0" << seconds + '\0';
	} else
	{
		string_stream << seconds + '\0';
	}
		
	lcdNumber->display(QString::fromStdString(string_stream.str()));
	songSlider->setValue(time);
}


void 
Ui_meta::change_song_position(int time)
{
	//cout << "ANDEI pelo slider"<< endl;
	emit update_m_position((uint32_t) time, format);
}

void Ui_meta::setFormat(Format *f)
{
    format = f;
    duration /= (format->sampleRate() * format->numChannels());
	duration /= (format->bitsPerSample()/8);
    format->print(cout);
}
