#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(void) {
	char str[SIZE];
	printf("�Է� �ؽ�Ʈ: ");
	gets(str);

	printf("��� ���ڿ�: ");
	for (int i = 0; i<str[i]; i++)
		if (str[i] != ' ')
			printf("%c", str[i]);

	return 0;
}