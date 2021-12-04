#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int avg(int score[]);

int main(void) {
	int num[5];

	for (int i = 0; i <= 5; i++) {
		printf("정수 입력: ");
		scanf_s("%d", &num[i]);
	}
	//avg(num[]);

	

	return 0;
}

int avg(int* arry) {
	int sum = 0;
	int avg = 0;
	for (int i = 1; i <= 5; i++) {
		sum += arry[i];
	}
	avg = sum / 5;
	printf("평균: %d", avg);

	if (avg >= 70)
		return 'P';
	else
		return 'F';
}