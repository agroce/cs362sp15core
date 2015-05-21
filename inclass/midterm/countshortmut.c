#include <stdio.h>
#include "shortcount.h"

unsigned char ref_bits1short(unsigned short c) {
  unsigned char ones = 0;
  unsigned int bit;
  while (c > 0) {
    bit = (unsigned int)c & (unsigned int)1;
    ones += bit;
    c = c >> 1;
  }
  return ones;
}

int main () {
  unsigned short c;
  for (c = 0; c < 65535; c++) {
    unsigned char v1 = bits1short(c);
    unsigned char v2 = ref_bits1short(c);
    if (v1 != v2) {
      printf ("MISMATCH: bits1short(%u) = %u, ref = %u\n", c, v1, v2);
    }
  }
  unsigned char v1 = bits1short(c);
  unsigned char v2 = ref_bits1short(c);
  if (v1 != v2) {
    printf ("MISMATCH: bits1short(%u) = %u, ref = %u\n", c, v1, v2);
  }  
}
