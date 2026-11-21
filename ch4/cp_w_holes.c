#include <unistd.h>
#include <fcntl.h>


int
main(int argc, char *argv[])
{

  if (argc != 3) {
    printf("usage: cpwh oldfile newfile\n");
    exit(1);
  }

  int old_fd = open(argv[1], O_RDONLY);
  int new_fd = open(argv[2], O_WRONLY);

  //Find the size of the file
  struct stat holey_file;
  fstat(old_fd, &holey_file);
  
  int n_bytes;
  char *buf[4096];
  while((n_bytes = read(old_fd, buf, 4096)) > 0){
    

}

  
