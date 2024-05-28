#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>

int num=0;

int main(){
	sigset_t set;
	int count =10;

	static struct sigaction act;

	void int_handle(int);

	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT,&act,NULL);

	sigemptyset(&set);
	sigfillset(&set);

	sigprocmask(SIG_BLOCK,&set,NULL);
	while(1)
	{
		if(num>=1){
			printf("bye~\n");
			exit(0);
		}
		if(count==5){
			sigemptyset(&set);
			sigaddset(&set,SIGINT);
			sigprocmask(SIG_UNBLOCK,&set,NULL);
		}
		else if(count==0){

			exit(0);
		}
		printf("I am a child\n");
		count--;
		sleep(1);
	}
}

void int_handle(int signum){
	num++;
	int fd = open("log.txt",O_RDWR|O_CREAT,0644);
	time_t t = time(NULL);
	char* buf = ctime(&t);
	write(fd,buf,strlen(buf));
	close(fd);
}
