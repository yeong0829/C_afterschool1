#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void) {
	char ch;
	int count = 0;

	while (1) {
		printf("���� �Է�: ");
		scanf(" %c", &ch);

		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			count++;

		else if (ch == 'q')
			break;
	}

	printf("������ ������ %d�� �Դϴ�.\n", count);

	return 0;
}
