#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	char a, b;
	printf("ù��° �ҹ��� �Է�: ");
	scanf("%c", &a);
	//fflush(stdin);
	//if (a >= 'a' && a <= 'z') a = a - 32;
	printf("ù��° �빮��: %c\n", a-('a'-'A'));

	printf("�ι�° �ҹ��� �Է�: ");
	scanf("%c\n", &b);
	//fflush(stdin);
	//if (b >= 'a' && b <= 'z') b = b - 32;
	printf("�ι�° �빮��: %c\n", b-('a'-'A'));

	return 0;
}