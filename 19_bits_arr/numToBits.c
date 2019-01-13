#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int getNthBit(uint32_t number, int bit) {
  if (bit <0 || bit >= 32) {
    printf("Bit %d is invalid\n", bit);
    exit (EXIT_FAILURE);
  }
  return (number & (1<<bit)) != 0;
}

// if nBits is larger than nNUms*32 then what would be remaining elements ?
void numToBits(uint32_t * nums, int nNums, int * bits, int nBits) {
  if (nBits < nNums*32)
    {
      printf("Invalid call to numToBits! nBits is %d, nNums is %d\n", nBits, nNums);
      return;
    }

  uint32_t bit = 0;
  for (int i=0; i<nNums; ++i)
    {
      uint32_t num = nums[i];
      for (int j=31; j>=0; j--) // iterate each bit from MSB to LSB
	{
	  bits[bit++] = getNthBit(num, j);
	}
    }
}

void doTest(uint32_t * nums, int n) {
  int bits[n *32];
  numToBits(nums, n, bits, n*32);
  for (int i =0; i < n; i++) {
    printf(" %9d (%8X) => ", nums[i], nums[i]);
    for (int j = 0; j < 32; j++) {
      printf("%d", bits[i*32 + j]);
    }
    printf("\n");
  }
}

int main(void) {
  uint32_t array1[] = { 1, 2, 3, 4, 5, 15, 109};
  uint32_t array2[] = { 123456789, 987654321 };
  int bits[7*32-1];
  doTest (array1, 7);
  doTest (array2, 2);
  numToBits(array1,7, bits , 7*32-1);
  return EXIT_SUCCESS;
}
