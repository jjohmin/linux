#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int x=2,y=2;
	int status;
	do{
		scanf("%d %d",&x,&y);
		if(x<1 || x>10 || x>y)
			printf("re\n");
	}while(!(x>=1 && x<=10 && x<y));
	pid = fork();

	if(pid>0){
		int n=x;
		for(int i=1;i<y;i++)
			x*=n;
		wait(&status);
		printf("result : %d\n",x+(status>>8));
	}
	else if(pid==0){
		int sum =0 ;
		for(int i=x;i<=y;i++)
			sum+=i;
		exit(sum);
	}
	else
		printf("fail\n");
}
