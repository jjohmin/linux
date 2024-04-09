#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc,char* argv[]){
	pid_t pid;

	for(int i=0;i<argc;i++)
		pid = fork();

	if(pid > 0){
		execl("/bin/wc","wc","-l","-w","-c",(char*)0);
	}
	else if(pid == 0){
		execl("/bin/wc","wc","-l","-w","-c",(char*)0);
	}
	else
		printf("fail\n");

}
