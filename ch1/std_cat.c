#include "../include/apue.h"

int
main(void)
{
  int c;

  while((c=getc(stdin)) != EOF)
    if(putc(c,stdout) == EOF)
      err_sys("Output Error");

  if(ferror(stdin))
    err_sys("Input Error");

  exit(0);
}
