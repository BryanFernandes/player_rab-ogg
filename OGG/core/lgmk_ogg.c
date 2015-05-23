#include <ogg/ogg.h>
#include "lgmk_ogg.h"
#include <stdio.h>

#define ENCODE_VENDOR_STRING "Bryan Fernandes"

 void
 lgmk_init(lgmk *lm)
 {
   memset(lm,0,sizeof(*lm));
 }

 void
 lgmk_add(lgmk *lm,const char *landmark)
 {
  lm->user_lgmks=_ogg_realloc(lm->user_lgmks,
                            (lm->lgmks+2)*sizeof(*lm->user_lgmks));
  lm->lgmk_lengths=_ogg_realloc(lm->lgmk_lengths,
                                  (lm->lgmks+2)*sizeof(*lm->lgmk_lengths));
  lm->lgmk_lengths[lm->lgmks]=strlen(landmark);
  lm->user_lgmks[lm->lgmks]=_ogg_malloc(lm->lgmk_lengths[lm->lgmks]+1);
  strcpy(lm->user_lgmks[lm->lgmks], landmark);
  lm->lgmks++;
  lm->user_lgmks[lm->lgmks]=NULL;
}

void
lgmk_add_tag(lgmk *lm, const char *tag, const char *contents)
{
  char *landmark=alloca(strlen(tag)+strlen(contents)+2); /* +2 for : and \0 */
  strcpy(landmark, tag);
  strcat(landmark, ":");
  strcat(landmark, contents);
  lgmk_add(lm, landmark);
}

static int
tagcompare(const char *s1, const char *s2, int n)
{
  int c=0;
  while(c < n){
    if(toupper(s1[c]) != toupper(s2[c]))
      return !0;
    c++;
  }
  return 0;
}

void
lgmk_clear(lgmk *lm)
{
  if(lm){
    long i;
    if(lm->user_lgmks){
      for(i=0;i<lm->lgmks;i++)
        if(lm->user_lgmks[i])_ogg_free(lm->user_lgmks[i]);
      _ogg_free(lm->user_lgmks);
    }
    if(lm->lgmk_lengths)_ogg_free(lm->lgmk_lengths);
    if(lm->vendor)_ogg_free(lm->vendor);
    memset(lm,0,sizeof(*lm));
  }
}

static void
_v_writestring(oggpack_buffer *o,const char *s, int bytes)
{
  while(bytes--)
  {
    oggpack_write(o,*s++,8);
  }
}

static void
_v_readstring(oggpack_buffer *o,char *buf,int bytes)
{
  while(bytes--)
  {
    *buf++=oggpack_read(o,8);
  }
}

static int
_unpack_lgmk(lgmk *lm,oggpack_buffer *opb)
{
  int i;
  int vendorlen=oggpack_read(opb,32);
  if(vendorlen<0)goto err_out;
  if(vendorlen>opb->storage-8)goto err_out;
  lm->vendor=_ogg_calloc(vendorlen+1,1);
  _v_readstring(opb,lm->vendor,vendorlen);
  i=oggpack_read(opb,32);
  if(i<0)goto err_out;
  if(i>((opb->storage-oggpack_bytes(opb))>>2))goto err_out;
  lm->lgmks=i;
  lm->user_lgmks=_ogg_calloc(lm->lgmks+1,sizeof(*lm->user_lgmks));
  lm->lgmk_lengths=_ogg_calloc(lm->lgmks+1, sizeof(*lm->lgmk_lengths));

  for(i=0;i<lm->lgmks;i++){
    int len=oggpack_read(opb,32);
    if(len<0)goto err_out;
    if(len>opb->storage-oggpack_bytes(opb))goto err_out;
    lm->lgmk_lengths[i]=len;
    lm->user_lgmks[i]=_ogg_calloc(len+1,1);
    _v_readstring(opb,lm->user_lgmks[i],len);
  }
  if(oggpack_read(opb,1)!=1)goto err_out; /* EOP check */

  return(0);
 err_out:
  lgmk_clear(lm);
  return(-1);
}

static int
_pack_lgmk(oggpack_buffer *opb,lgmk *lm)
{
  int bytes = strlen(ENCODE_VENDOR_STRING);

  /* preamble */
  oggpack_write(opb,0x07,8);
  _v_writestring(opb,"lgmks", 5);

  /* vendor */
  oggpack_write(opb,bytes,32);
  _v_writestring(opb,ENCODE_VENDOR_STRING, bytes);

  /* landmark */
  oggpack_write(opb,lm->lgmks,32);
  if(lm->lgmks){
    int i;
    for(i=0;i<lm->lgmks;i++){
      if(lm->user_lgmks[i]){
        oggpack_write(opb,lm->lgmk_lengths[i],32);
        _v_writestring(opb,lm->user_lgmks[i], lm->lgmk_lengths[i]);
      }else{
        oggpack_write(opb,0,32);
      }
    }
  }
  oggpack_write(opb,1,1);

  return(0);
}

int
lgmkheader_out(lgmk *lm, ogg_packet *op)
{

  oggpack_buffer opb;

  oggpack_writeinit(&opb);
  if(_pack_lgmk(&opb,lm)) return -1;

  op->packet = _ogg_malloc(oggpack_bytes(&opb));
  memcpy(op->packet, opb.buffer, oggpack_bytes(&opb));

  op->bytes=oggpack_bytes(&opb);
  op->b_o_s=0;
  op->e_o_s=0;
  op->granulepos=0;
  op->packetno=3;

  return 0;
}

int lgmk_synthesis_headerin(lgmk *lm,ogg_packet *op){
  oggpack_buffer opb;

  if(op){
    oggpack_readinit(&opb,op->packet,op->bytes);

    {
      char buffer[5];
      int packtype=oggpack_read(&opb,8);
      memset(buffer,0,5);
      _v_readstring(&opb,buffer,5);
      if(memcmp(buffer,"lgmks",5)){
        /* not a lgmk header */
         //fprintf(stderr,"packet: %s\n", buffer);
        return(-1);
      }

      return(_unpack_lgmk(lm,&opb));
    }
  }
  return(-1);
}
