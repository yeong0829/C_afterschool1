#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100

int str_chr(char* s, int c);

int main(void) {
	char str[SIZE];
	char ch;
	printf("���ڿ��� �Է�: ");
	gets(str);
	printf("Ư�� ���� Ȯ��: ");
	ch = getchar();
	printf("%c�� ����: %d", ch, str_chr(str, ch));

	return 0;
}
int str_chr(char* s, int c) {
	int count = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (s[i] == c)
			count++;
	}

	return count;
}