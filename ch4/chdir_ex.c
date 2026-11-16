#include "../include/apue.h"
#include <limits.h>

int
main(void)
{
  if(chdir("/tmp") < 0)
    err_sys("chdir failed");
  // printf("chdir to /tmp succeeded\n");

  char cwd[PATH_MAX];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working directory: %s\n", cwd);
  } else {
    perror("getcwd() error");
    return 1;
  }

  exit(0);

}
