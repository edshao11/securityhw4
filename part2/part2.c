#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define AMOUNT_OF_STUFF 10

// Uhh what...
void easteregg(){
  system("/bin/echo EasterEgg");
}


void vuln(){
  char * stuff = (char *)mmap(NULL, AMOUNT_OF_STUFF, PROT_EXEC|PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
  if(stuff == MAP_FAILED){
    printf("Failed to get space. Try again in a few seconds. Otherwise post on Piazza\n");
    exit(0);
  }
  printf("Give me %d bytes:\n", AMOUNT_OF_STUFF);
  fflush(stdout);
  int len = read(STDIN_FILENO, stuff, AMOUNT_OF_STUFF);
  if(len == 0){
    printf("You didn't give enough :(\n");
    exit(0);
  }

  printf("What did I get?\n");
  for (int i = 0; i < AMOUNT_OF_STUFF; i++)
    printf("0x%x ", (unsigned char)stuff[i]);
  printf("\n\n");
  fflush(stdout);

  void (*func)() = (void (*)())stuff;
  func();
}

int main(int argc, char*argv[]){
  printf("My mother told me to never accept things from strangers\n");
  printf("How bad could it be though?\n");
  fflush(stdout);
  vuln();
  return 0;
}

void test() {
  easteregg();
}
