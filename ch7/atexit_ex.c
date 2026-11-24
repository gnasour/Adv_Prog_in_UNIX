#include <stdio.h>
#include <stdlib.h>


int
main(void)
{
  void hello_exit(void);

  atexit(hello_exit);

  return 0;
}


void hello_exit(void)
{
  printf("Hello, World @ exit\n");
}
