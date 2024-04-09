#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int i=0;

int main(){
	pid_t pid;

	i++;
	printf("before calling fork(%d)\n",i);

	pid = fork();

	if(pid == 0)
		/* Child Process */
		printf("child process(%d)\n",++i);
	else if(pid > 0)
		/* Parent Process */
		printf("parent process(%d)\n",--i);
	else
		/* fork failed */
		printf("fail to fork\n");
}
