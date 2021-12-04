#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(void) {
	char str[SIZE];
	printf("입력 텍스트: ");
	gets(str);

	printf("결과 문자열: ");
	for (int i = 0; i<str[i]; i++)
		if (str[i] != ' ')
			printf("%c", str[i]);

	return 0;
}