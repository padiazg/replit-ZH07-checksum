#include <stdio.h>

// Assumes little endian
void printBits(size_t const size, void const * const ptr)
{
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;
  
  for (i = size-1; i >= 0; i--) {
    for (j = 7; j >= 0; j--) {
      byte = (b[i] >> j) & 1;
      printf("%u", byte);
    }
  }
  puts("");
}

unsigned char FucCheckSum(unsigned char *i, unsigned char ln) {
  unsigned char j,tempq=0;
  i+=1;
  for(j=0;j<(ln-2);j++) {
    tempq+=*i;
    i++;
    printf("tempq=%02x (sum) => %04x\n", *i, tempq);
  }
  printBits(sizeof(tempq), &tempq);
  tempq=(~tempq);
  printf("tempq (invert) => %04x\n", tempq);
  printBits(sizeof(tempq), &tempq);
  tempq++;
  printf("tempq (+1)     => %04x\n", tempq);

  return(tempq);
}

int main(void) {
  unsigned char myArray[] = {0xFF, 0x86, 0x00, 0x47, 0x00, 0xC7,0x03, 0x0F, 0x5A};

  printf("checksum => %02x\n", FucCheckSum(myArray, sizeof(myArray)));
  return 0;
}