#include <sys/time.h>
#include <time.h>
#include <stdio.h>


int
main(void)
{
  struct timeval tbuf;

  gettimeofday(&tbuf, NULL);

  struct tm *tm_buf = localtime(&tbuf.tv_sec);
  int maxsize = 1024;
  char buf[maxsize];
 
  strftime(buf, maxsize, "%a %b %d %T %Z %Y", tm_buf);

  printf("%s\n", buf);
  return 0;

}
