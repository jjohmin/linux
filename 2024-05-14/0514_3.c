#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	
	if((pid = fork()) > 0)
	{
		sleep(2);
		printf("Parent Die\n");
	}
	else if(pid==0)
	{
		printf("I'm Child\n");
		sleep(1);
		printf("Child Die\n");
		kill(getppid(),SIGCHLD);
	}
	else
		printf("fail to fork\n");
}
