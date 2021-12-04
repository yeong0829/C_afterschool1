//파일 읽어 와서 출력하기

#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#include <stdio.h>

void main()
{
    FILE* fp = fopen("fg.txt", "r"); //rt:텍스트파일 읽어오기 t생략 가능
    char ch[MAX] = "NULL";

    fread(ch, MAX, 1, fp);
    printf("%s\n", ch);

    fclose(fp);
}

//int main(void) {
//    char n[256]; FILE* fp;
//    fp = fopen("fg.txt", "r");
//    if (fp == NULL) printf("  open fail");
//    else {
//        do {
//            gets(n, 255, fp);
//            puts(n);
//        } while (!feof(fp));//파일의 끝인가->참이면 계속 반복/ 끝이면 ture반환-끝 
//    }
//    fclose(fp);
//}


//이름 나이 입력받아 컨트롤z눌르면 종료 파일에 출력
//int main() {
//    char name[20]; int age;
//    FILE* fpi = NULL, * fpo = NULL;
//    fpo = fopen("name.txt", "w+");
//    if (fpo == NULL) printf("  open fail");
//    else {
//        while (1) {
//            check = fscanf(fpi, "%s", name); fscanf(fpi, "%d", age);
//            if (feof(fpi)) break;
//            fprintf(stdout, "\n%s %d", name, age);
//        }
//    }
//    fclose(fpo);
//}