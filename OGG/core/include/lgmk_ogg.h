#ifndef LGMK_OGG_H
#define LGMK_OGG_H

#include <ogg/ogg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct lgmk{
  char **user_lgmks;
  int   *lgmk_lengths;
  int    lgmks;
  char  *vendor;

} lgmk;

/*class LgmkOgg {
public:

    LgmkOgg();
    //~LgmkOgg();
};*/

extern void     lgmk_init(lgmk *lm);
extern void     lgmk_add(lgmk *lm, const char *landmark);
extern void     lgmk_add_tag(lgmk *lm, const char *tag, const char *contents);
extern void     lgmk_clear(lgmk *lm);
extern int 		lgmkheader_out(lgmk *lm, ogg_packet *op);
extern int 		lgmk_synthesis_headerin(lgmk *lm,ogg_packet *op);

#endif
