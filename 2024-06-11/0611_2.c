#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 512

int main(){
	char  buffer[SIZE];
	int p1[2],p2[2],i;
	pid_t pid1,pid2;
	fd_set initset,newset;

	pid1=pid2=0;

	if(pipe(p1)==-1)
		onerror("fail1p\n");
	if(pipe(p2)==-1)
		onerror("fail2p\n");
	if((pid1=fork())==-1)
		onerror("fail1f\n");
	if(
	else if(pid>0){
		close(fildes[0]);

		for(i=0;i<2;i++){
			printf("input%d :",i+1);
			fgets(buffer,SIZE,stdin);
			write(filedes[1],buffer,SIZE);
		}
	}


