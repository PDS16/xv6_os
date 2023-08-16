#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

// TODO: YOUR CODE HERE
// INITIALIZE DATA STRUCTURE TO STORE PIDS OF PROCESSES TO KILL LATER

/* Splits the string by space and returns the array of tokens
 *
 */
char **tokenize(char *line)
{

	// tokenizer variables
	char **tokens = (char **)malloc(MAX_NUM_TOKENS * sizeof(char *));
	char *token = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
	int i, tokenIndex = 0, tokenNo = 0;

	// loop on length of line
	for (i = 0; i < strlen(line); i++)
	{

		char readChar = line[i];

		// tokenize on any kind of space
		if (readChar == ' ' || readChar == '\n' || readChar == '\t')
		{
			token[tokenIndex] = '\0';
			if (tokenIndex != 0)
			{
				tokens[tokenNo] = (char *)malloc(MAX_TOKEN_SIZE * sizeof(char));
				strcpy(tokens[tokenNo++], token);
				tokenIndex = 0;
			}
		}
		else
		{
			token[tokenIndex++] = readChar;
		}
	}

	free(token);
	tokens[tokenNo] = NULL;
	return tokens;
}

// TODO
// MAKE FUNCTIONS AS REQUIRED TO AVOID REPETITIVE WORK

void execute_call(char *argv[])
{
	if(strcmp(argv[0],"cd") == 0)
		{
			if(argv[2] != NULL)
			{
				printf("TOO MANY ARGUMENTS GIVEN\n");
			}
			else
			{
				if ( argv[1] == NULL)
				{
					printf("TOO FEW ARGUMENTS GIVEN\n");
				}
				else
				{
					if(chdir(argv[1]) == -1)
					{
						printf("NO SUCH FILE OR DIRECTORY EXISTS\n");
					}
				}
			}
		}
		else
		{
			if (fork() == 0)
				execvp(argv[0], argv); // child: call execv with the path and the args
			else
				wait(NULL);
		}
}

int main(int argc, char *argv[])
{

	char line[MAX_INPUT_SIZE];
	char **tokens;

	// TODO: YOUR CODE HERE
	// INITIALIZE GLOBAL DATA STRUCTURE OF PIDS TO SOME DEFAULT VALUE
	// INITIALIZE OTHER VARIABLES AS NEEDED

	while (1)
	{

		/* BEGIN: TAKING INPUT */
		bzero(line, sizeof(line));
		printf("$ ");
		scanf("%[^\n]", line);
		getchar();
		/* END: TAKING INPUT */

		line[strlen(line)] = '\n'; // terminate with new line
		tokens = tokenize(line);

		// You can maintain boolean variables to check which type of command is given by user and then
		// conditionally execute depending on them

		// TODO: YOUR CODE HERE
		//
		// TODO: YOUR CODE HERE


		if (strcmp(tokens[0],"exit") == 0)
		{
			for (int i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}

			free(tokens);

			// for (int i = 0; i<MAX_INPUT_SIZE; i++)
			// {
			// 	free(line[i]);
			// }

			// free(line);
			exit(0);
		}

		int triple_and = 0;

		int command_start[64];
		command_start[0] = 0;
		int finish = 0;
		int index = 1;
		for (int i = 0; tokens[i] != NULL; i++)
		{
			if ( strcmp(tokens[i],"&&") == 0) 
			{
				tokens[i] = NULL;
				command_start[index] = i+1;
				finish = index;
				index++;
			}
			else if ( strcmp(tokens[i],"&&&") == 0)
			{
				triple_and = 1;
				tokens[i] = NULL;
				command_start[index] = i+1;
				finish = index;
				index++;
			}
		}

		if ( triple_and == 0)
		{
			for (size_t i = 0; i < 64; i++)
			{
				execute_call(&tokens[command_start[i]]);
				if ( i == finish) break;
			}
		}
		else
		{

			for(int i=0;i<finish+1;i++) // loop will run n times (n=5)
			{
				char **argv = &tokens[command_start[i]];
				if(strcmp(argv[0],"cd") == 0)
				{
					if(argv[2] != NULL)
					{
						printf("TOO MANY ARGUMENTS GIVEN\n");
					}
					else
					{
						if ( argv[1] == NULL)
						{
							printf("TOO FEW ARGUMENTS GIVEN\n");
						}
						else
						{
							if(chdir(argv[1]) == -1)
							{
								printf("NO SUCH FILE OR DIRECTORY EXISTS\n");
							}
						}
					}
				}
				else
				{
					if (fork() == 0)
					{
						execvp(argv[0], argv); // child: call execv with the path and the args
						exit(0);
					}
				}
			}
			for(int i=0;i<finish+1;i++) // loop will run n times (n=5)
			wait(NULL);

		}

		
		

		
		// freeing the memory
		for (int i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}

		free(tokens);
	}
	return 0;
}
