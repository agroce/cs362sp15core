#include <stdio.h>

unsigned char bits1long(unsigned long c)
{
  unsigned long i = (unsigned long) c;
  i = i - ((i >> 1) & 0x55555555);
  i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
  return (unsigned long)((((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24);
}

unsigned char ref_bits1long(unsigned long c) {
  unsigned char ones = 0;
  unsigned int bit;
  while (c > 0) {
    bit = (unsigned long)c & (unsigned long)1;
    ones += bit;
    c = c >> 1;
  }
  return ones;
}

unsigned long nondet_ulong();

int main () {
  unsigned long c = nondet_ulong();
  unsigned char v1 = bits1long(c);
  unsigned char v2 = ref_bits1long(c);
  printf ("LOG Comparing: bits1long(%lu) = %u, ref = %u\n", c, v1, v2);
  assert (v1 == v2);
}
