#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	char ch;
	int count = 0;

	while (1) {
		printf("문자 입력: ");
		scanf(" %c", &ch);

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			count++;

		else if (ch == 'q')
			break;
	}

	printf("모음의 갯수는 %d개 입니다.\n", count);

	return 0;
}
