#include <stdio.h>

struct ABC{
	char a;
	int b;
	double c;
}ABC;

int main(){
	printf("%ld",sizeof(ABC));
}
