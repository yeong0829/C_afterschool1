#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char a, b;
	printf("첫번째 소문자 입력: ");
	scanf("%c", &a);
	//fflush(stdin);
	//if (a >= 'a' && a <= 'z') a = a - 32;
	printf("첫번째 대문자: %c\n", a-('a'-'A'));

	printf("두번째 소문자 입력: ");
	scanf("%c\n", &b);
	//fflush(stdin);
	//if (b >= 'a' && b <= 'z') b = b - 32;
	printf("두번째 대문자: %c\n", b-('a'-'A'));

	return 0;
}