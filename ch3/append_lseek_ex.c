#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int
main(void)
{
  int temp_fd = open("temp.txt", O_RDWR | O_APPEND | O_CREAT, 0666);

  write(temp_fd, "Hello, World!\n", 15);

  lseek(temp_fd, 0, SEEK_SET);

  char buf[20];
  read(temp_fd, buf, 5);
  
  off_t test_pos = lseek(temp_fd, 0, SEEK_CUR);
  printf("curr offset after reading %ld\n", test_pos);
  
  write(temp_fd, "Test", 4);
  test_pos = lseek(temp_fd, 0, SEEK_CUR);
  printf("offset after second write: %ld\n", test_pos);
  
  lseek(temp_fd, 5, SEEK_SET);

  read(temp_fd, buf+5, 4);

  buf[9] = '\0';

  printf("resulting string: %s\n", buf);

}
  
