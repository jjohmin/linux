#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd;
    off_t nread;
    int num = 0; // 알파벳 개수를 저장할 변수를 초기화합니다.
    char buffer[1024];
    fd = open("alpha.txt", O_RDONLY);
    if(fd == -1) {
        printf("Error!");
        exit(1);
    }

    while((nread = read(fd, buffer, sizeof(buffer))) > 0) {
        for(int cnt = 0; cnt < nread; cnt++) {
            if((buffer[cnt] >= 'a' && buffer[cnt] <= 'z') || (buffer[cnt] >= 'A' && buffer[cnt] <= 'Z')) {
                num++;
            }
        }
    }

    printf("Alpha Num : %d\n", num);

    close(fd); // 파일 디스크립터를 닫습니다.

    return 0;
}
