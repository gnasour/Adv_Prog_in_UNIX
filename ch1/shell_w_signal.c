#include "../include/apue.h"
#include <sys/wait.h>

static void sig_int(int);

int
main(void)
{
  char buf[MAXLINE];
  pid_t pid;
  int status;

  if(signal(SIGINT, sig_int) == SIG_ERR)
    err_sys("Signal Error");

  printf("%% ");
  while(fgets(buf, MAXLINE, stdin) != NULL) {
    if(buf[strlen(buf) - 1] == '\n')
      buf[strlen(buf) - 1] = 0;

    if((pid = fork()) < 0) {
      err_sys("Fork Error");
    } else if (pid == 0) {
      execlp(buf, buf, (char *)0);
      err_ret("Couldn't execute: %s", buf);
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0)
      err_sys("waitpid error");
    printf("%% ");
  }
  exit(0);
}

void
sig_int(int signo)
{
  printf("INT\n%% ");
}
