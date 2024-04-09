#include <stdio.h>
#include <unistd.h>

int main(){
	int n,sum1=0,sum2=1;
	pid_t pid;
	scanf("%d",&n);
	pid = fork();
	if(pid>0){
		for(int i=1;i<=n;i++)
			sum1+=i;
		printf("Parent Process : %d\n",sum1);
	}
	else if(pid == 0){
		for(int i=1;i<=n;i++)
			sum2*=i;
		printf("Child Process : %d\n",sum2);
	}
	else
		printf("Failed");
}

