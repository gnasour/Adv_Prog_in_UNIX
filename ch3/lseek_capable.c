#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int
main(void)
{
  off_t currpos;
  if((currpos=lseek(STDIN_FILENO, 0, SEEK_CUR)) == -1)
    printf("cannot seek\n");
  else {
    printf("seek OK\n");
    printf("Current offset: %ld\n", currpos);
  }
  
  exit(0);
}
