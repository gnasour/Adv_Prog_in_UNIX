#include <unistd.h>
#include <stdio.h>
#include <limits.h>


int
main(void)
{
  char name[HOST_NAME_MAX];

  if (gethostname(name, HOST_NAME_MAX) < 0){
    printf("gethostname error\n");
    return -1;
  }

  printf("%s\n", name);


  return 0;

}
  
