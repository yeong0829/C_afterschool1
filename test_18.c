//���� �о� �ͼ� ����ϱ�

#define _CRT_SECURE_NO_WARNINGS
#define MAX 1000
#include <stdio.h>

void main()
{
    FILE* fp = fopen("fg.txt", "r"); //rt:�ؽ�Ʈ���� �о���� t���� ����
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
//        } while (!feof(fp));//������ ���ΰ�->���̸� ��� �ݺ�/ ���̸� ture��ȯ-�� 
//    }
//    fclose(fp);
//}


//�̸� ���� �Է¹޾� ��Ʈ��z������ ���� ���Ͽ� ���
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