#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 512

int main(){
	char buffer[SIZE];
	int filedes[2],nread[2],i;
	pid_t pid;

	if(pipe(filedes)==-1){
		printf("fail to call pipe()\n)");
		exit(1);
	}
	if((pid=fork())==-1){
		printf("fail to call fork()\n");
		exit(1);
	}
	else if(pid>0){
		close(filedes[0]);
		for(i=0;i<2;i++){
			printf("input %d :",i+1);
			fgets(buffer,SIZE,stdin);
			write(filedes[1],buffer,SIZE);
		}
		sleep(2);
	}
	else{
		close(filedes[1]);
		sleep(1);
		read(filedes[0],buffer,SIZE);
		printf("%d\n",buffer[0]+buffer[1]);
	}
}
