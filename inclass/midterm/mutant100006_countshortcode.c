#include "shortcount.h"

unsigned char bits1short(unsigned short c)
{
  unsigned int i = (unsigned int) c;
 /* MUTANT (rep_const) */  i = i - ((i >> 1) & -1x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (unsigned short)((((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24);
}
