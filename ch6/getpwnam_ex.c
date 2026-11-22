#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

struct passwd *
getpwnam_s(const char *name)
{
  struct passwd *ptr;

  setpwent();
  while ((ptr = getpwent()) != NULL)
    if(strcmp(name, ptr->pw_name) == 0)
      break;
  endpwent();
  return ptr;
}

struct passwd *
getpwnam_uid(uid_t user_id)
{
  struct passwd *ptr;

  setpwent();
  while((ptr = getpwent()) != NULL)
    if(user_id == ptr->pw_uid)
      break;
  endpwent();
  return ptr;
}
      
      

int
main(int argc, char *argv[])
{
  struct passwd *sbuf;
  char *name = NULL;

  // Add code so that it searches for the current user's name
  // based on uid
  if (argc == 1){
    sbuf = getpwnam_uid(getuid());
    printf("User: %s\n", sbuf->pw_name);
    
  } else if (argc == 2){
    name = argv[1];
    sbuf = getpwnam_s(name);
    printf("%d\n", sbuf->pw_uid);
  } else {
    printf("Usage: getpwnam_ex [username]\n");
  }
  
  return 0;
}
