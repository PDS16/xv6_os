#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc, char *argv[])
{

  if(argc <= 1){
    //cat(0);
    exit();
  }

  int childpid = fork();

  if ( childpid == 0){
    exec(argv[1],&argv[1]);
  }
  else{
    wait();
  }
  
  exit();
}
