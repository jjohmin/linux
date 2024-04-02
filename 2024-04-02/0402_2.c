#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int dir_count =0,file_cnt=0;
void dire(char* arg){
	DIR *dirp2;

	if((dirp2 = opendir(arg)) == NULL)
		file_cnt++;
	else
		dir_count++;

	closedir(dirp2);
}

int main(int argc,char* argv[]){
	DIR *dirp;

	struct dirent *dentry;

	if((dirp = opendir(argv[1])) == NULL)
		exit(1);

	while(dentry = readdir(dirp)){
		if(dentry->d_ino != 0)
			dire(dentry->d_name);
	}
	printf("FILE : %d\n",dir_count);
	printf("DIRECTIRY : %d\n",file_cnt);
	closedir(dirp);
}
