#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num = 0;
	int sum = 0;

	while (1) {
		printf("���� �Է�: ");
		scanf_s("%d", &num);
		if (num == EOF && num == 0) {
			break;
		}else {
			sum += num;
		}
	}
	printf("�Էµ� ������ ��: %d\n", sum);

	return 0;
}