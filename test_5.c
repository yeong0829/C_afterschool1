#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stars(int num, char ch);

int main(void) {
	int n = 0;
	char c;
	printf("숫자: ");
	scanf_s("%d", &n);
	printf("문자: ");
	scanf_s(" %c", &c);
	stars(n, c);

	return 0;
}

int stars(int num, char ch) {
	for (int i = num; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			printf("%c",ch);
		}
		printf("\n");
	}
}