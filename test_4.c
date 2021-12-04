#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num = 0;
	int sum = 0;

	while (1) {
		printf("정수 입력: ");
		scanf_s("%d", &num);
		if (num == EOF && num == 0) {
			break;
		}else {
			sum += num;
		}
	}
	printf("입력된 정수의 합: %d\n", sum);

	return 0;
}