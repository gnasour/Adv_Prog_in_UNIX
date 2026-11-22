#include <sys/time.h>
#include <stdio.h>

int
main(void)
{
  struct timeval tbuf;

  gettimeofday(&tbuf, NULL);
  printf("tv_sec: %zd\n", tbuf.tv_sec);
  printf("tv_usec: %zd\n", tbuf.tv_usec);
  size_t min = tbuf.tv_sec / 60;
  size_t hours = min / 60;
  size_t days = hours / 24;

  printf("min: %zu, hours: %zu, days: %zu\n", min, hours, days);
  return 0;

}
