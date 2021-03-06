#include <stdio.h>

unsigned char bits1char(unsigned char c)
{
  unsigned int i = (unsigned int) c;
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (unsigned char)((((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24);
}

unsigned char ref_bits1char(unsigned char c) {
  unsigned char ones = 0;
  unsigned int bit;
  while (c > 0) {
    bit = (unsigned int)c & (unsigned int)1;
    ones += bit;
    c = c >> 1;
  }
  return ones;
}

unsigned char nondet_uchar();

int main () {
  unsigned char c = nondet_uchar();
  unsigned char v1 = bits1char(c);
  unsigned char v2 = ref_bits1char(c);
  printf ("LOG Comparing: bits1char(%u) = %u, ref = %u\n", c, v1, v2);
  assert(v1==v2);
}
