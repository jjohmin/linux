#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char *filename = argv[1];

	if(access(filename,F_OK)==-1){
		fprintf(stderr,"User dont't have file %s \n",filename);
		exit(1);
	}
	printf("%s File OK, proceeding \n", filename);
}
