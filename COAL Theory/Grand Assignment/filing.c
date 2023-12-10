#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv){  
  uint32_t counter = 4;
  char buffer[16] = {0}; 
  FILE * fptOut = 0;

  /* ... code to open your file goes here ... */

  sprintf(buffer, "%d", counter);
  fputs(buffer, fptOut);

  return 0;
}
