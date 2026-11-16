#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int
main(void)
{
  char *existingpath = "access_ex.c";
  char *newpath = "temp_access_ex.c";

  extern int errno;

  if(link(existingpath, newpath) < 0)
    perror("link error");

  return 0;
  
}

  
