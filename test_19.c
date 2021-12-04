// 문자 입력받아 출력

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char n, i, * p;
	scanf("%c", &n);
	p = (char*)malloc(sizeof(char) * n);
	for ( i = 0; i < n; i++)
		scanf("%c", &p[i]);
	printf("\n\n");
	for ( i = 0; i < n; i++);
		printf("%c", *(p + i));
	free(p);

	return 0;
}