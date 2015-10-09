#include <stdio.h>
#include <unistd.h>

void yzshell(){
	char commandline[150];
	char *argv[50];
	int i=0,j=0,processid;

	printf("Input your command:" );
	gets (commandline);/*gets the command*/

	for (; i < 150; i++)
	{
		argv[j++]=commandline+i;
		while (commandline[i]!=' ' && commandline[i]!='\0'){
			i++;
		}
		if (commandline[i]=='\0'){
			break;
		}
		commandline[i]='\0';
	}
	argv[j]=NULL;

	processid=fork();/*This function creates a child process and executes the commands*/
	if (processid==0)/*for the child process*/
	{
		execvp (argv[0], argv); /*execute command*/
		printf("Cannot found this command!\n");/*if execvp returns -1*/
	}
	else if (processid>0)
	{
		wait(NULL);/*parent process waits for child process termination*/
	}
}

int main()
{
	while(1){
		yzshell();
	}
	return 0;
}