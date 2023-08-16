#include "types.h"
#include "stat.h"
#include "user.h"

char *buf;

void
head(int fd, int n)
{
  int k;

  while((k = read(fd, buf, 1)) > 0 && n!=0) {
    if (write(1, buf, 1) != 1) {
      printf(1, "cat: write error\n");
      exit();
    }
    if ( *buf == '\n') n--;
  }
  if(k < 0){
    printf(1, "cat: read error\n");
    exit();
  }
}

int
main(int argc, char *argv[])
{
  int fd, i;

  if(argc <= 2){
    //cat(0);
    exit();
  }
  int n = atoi(argv[1]);
  for(i = 2; i < argc; i++){
    if((fd = open(argv[i], 0)) < 0){
      printf(1, "cat: cannot open %s\n", argv[i]);
      exit();
    }
    printf(1, "-----%s-----\n", argv[i]);
    head(fd,n);
    close(fd);
  }
  exit();
}
