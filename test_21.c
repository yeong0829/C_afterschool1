#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void) {
	char s[100];
	int count = 0;

	printf("���� �Է�: ");
	scanf("%s", s);
	if (getch() == 'q') return 0;

	for (int i = 0; s[i] != 0; i++){
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i')
			count++;
	}
	printf("������ ����: %d", count);
	

	return 0;
}