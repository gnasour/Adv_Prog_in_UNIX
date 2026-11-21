#include <stdio.h>


int
main(void)
{
  
  char buf[1024];
  FILE *fp;
  buf[18] = '\0';
  fp = fopen("tmp", "w+");
  setbuf(fp, buf);

  fputs("Hello", fp);
  printf("%s\n", buf);
  fputs("Hello", fp);
   printf("%s\n", buf);
  fflush(fp);
  printf("%s\n", buf);
  fputs("bbbye", fp);
  printf("%s\n", buf);
  

  return 0;
}
