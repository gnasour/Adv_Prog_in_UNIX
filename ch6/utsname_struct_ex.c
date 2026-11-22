#include <sys/utsname.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
  struct utsname sbuf;

  if (uname(&sbuf) < 0){
    printf("uname error\n");
    return -1;
  }

  // Minimally defined fields by POSIX.1 of struct utsname 
  printf("char sysname[]: %s\n", sbuf.sysname);
  printf("char nodename[]: %s\n", sbuf.nodename);
  printf("char release[]: %s\n", sbuf.release);
  printf("char version[]: %s\n", sbuf.version);
  printf("char machine[]: %s\n", sbuf.machine);


  return 0;
}

  
