#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  int secret = 0xdeadbeef;
  char name[100] = {0};

  printf("Hello can you guess my secret?\n");
  read(0, name, 0x100);

  printf("secret = 0x%02X\n", secret);
  if (secret == 0xFEEDC0DE) {
    printf("How did you even get here?!?!\n");
    return 0;
  } else {
    printf("Try again!\n");
    return -1;
  }
}
