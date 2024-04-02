#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char* argv[]){
	DIR *dirp;
	if((dirp = opendir(argv[1])) == NULL){
		fprintf(stderr, "No\n");
		exit(1);
	}
	else
		fprintf(stderr, "Yes\n");

	closedir(dirp);
}
