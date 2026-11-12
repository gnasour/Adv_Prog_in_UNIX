

int
dup2(int old_fd, int new_fd)
{
  
  if(old_fd == new_fd)
    return old_fd;

  
