#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    off_t nread;
    int num = 0; // 알파벳 개수를 저장할 변수를 초기화합니다.
    char buffer[1024];
    fp = fopen(argv[1], "r");
    while((nread = fread(buffer, 1024,1,fp)) > 0) {
        for(int cnt = 0; cnt < nread; cnt++) {
            if((buffer[cnt] >= 'a' && buffer[cnt] <= 'z') || (buffer[cnt] >= 'A' && buffer[cnt] <= 'Z')) {
                num++;
            }
        }
    }

    printf("Alpha Num : %d\n", num);

    fclose(fp); // 파일 디스크립터를 닫습니다.

    return 0;
}
