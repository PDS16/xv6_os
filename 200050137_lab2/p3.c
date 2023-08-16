#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
	char file[51];
	printf(">>> ");
	scanf("%s",file);
	int pid = fork();
	
	if (pid== 0){
		char *args[]={file,NULL};
        	execv(args[0],args);
        	return 0;
  	}
    else
    {		
    		wait(NULL);
    		while(true)
    		{
	    		char file[51];
	    		printf(">>> ");
			scanf("%s",file);
			
			int pid = fork();
	
			if (pid== 0){
				char *args[]={file,NULL};
				execv(args[0],args);
				return 0;
		  	}
		    else
		    {	
		    	wait(NULL);
		    }
		}
		
		
    }
	return 0;
}

