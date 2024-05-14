#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int num = 0;

int main(){
	static struct sigaction act;

	void int_handle(int);

	act.sa_handler = int_handle;
	sigfillset(&(act.sa_mask));
	sigaction(SIGINT, &act, NULL);
	while(1){
		printf("i'm sleepy..\n");
		sleep(1);
		if(num>=1)
			exit(0);
	}
}

void int_handle(int signum)
{
	num++;
	int fd;
	fd = open("a.txt",O_RDWR|O_CREAT,0644);
	char* buf = "Goodbye!";
	write(fd,buf,strlen(buf));
	close(fd);
}
