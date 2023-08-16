#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h> 
int main()
{
	char file1[50];
	char file2[50];
	char ch;
	int fsize_1 = 0;
	int fsize_2 = 0;
	while(read(STDIN_FILENO, &ch, 1) > 0)
	{
		if(ch == '\n') break;
	 	file1[fsize_1] = ch;
	 	fsize_1++;
	}
	while(read(STDIN_FILENO, &ch, 1) > 0)
	{
		if(ch == '\n') break;
	 	file2[fsize_2] = ch;
	 	fsize_2++;
	}
	file1[fsize_1] = '\0';
	file2[fsize_2] ='\0';
	
	int f1 = open(file1,O_RDONLY);
	int f2 = open(file2,O_WRONLY | O_CREAT | O_RDWR | O_TRUNC);
	
	while(read(f1, &ch, 1) > 0)
	{
	 	write(f2,ch,1);
	}
	close(f1);
	close(f2);
	return 0;
}

