#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	off_t nread;
	char buffer[1024];
	fd = open("alpha.txt",O_RDWR);
	if(fd == -1){
		printf("Error!");
		exit(1);
	}

	while((nread=read(fd,buffer,sizeof(buffer)))>0){
		for(int cnt = 0;cnt<nread;cnt++){
			if(buffer[cnt]>='a' && buffer[cnt]<='z'){
				buffer[cnt]=buffer[cnt]-'a'+'A';
			}
			lseek(fd,(off_t)-nread,SEEK_CUR);
			write(fd,buffer,nread);
		}
	}
	close(fd);
}
