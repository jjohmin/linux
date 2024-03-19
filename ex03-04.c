#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fdin,fdout;
	ssize_t nread;
	char buffer[1024];

	fdin = open("temp1.txt",O_RDONLY);
	if(fdin== -1)
	{
		printf("Error fd1");
		exit(1);
	}
	fdout = open("temp2.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(fdout==-1)
	{
		printf("Error fd2");
		exit(1);
	}
	while((nread = read(fdin, buffer, 1024)) >0 )
	{
		if(write(fdout, buffer, nread)<nread)
		{
			close(fdin);
			close(fdout);
		}
	}

	close(fdin);
	close(fdout);
}
