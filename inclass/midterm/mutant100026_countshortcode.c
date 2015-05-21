#include "shortcount.h"

unsigned char bits1short(unsigned short c)
{
  unsigned int i = (unsigned int) c;
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
 /* MUTANT (rep_const) */  return (unsigned short)((((i + (i >> -1)) & 0x0F0F0F0F) * 0x01010101) >> 24);
}
