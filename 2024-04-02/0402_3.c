#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[]){
	char name[1024];
	int nread
	DIR *dirp;
	if((dirp = opendir(argv[1]))== NULL){
		fprintf(stderr, "Error\n");
		exit(1);
	}
	if((nread = readlink(argv[1],name,1024))==-1)
		printf("Soft");
	else
		printf("no soft");

	closedir(dirp);
	
