#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print(int car);

struct apartment {
	short dong; int car;
};

int main(void) {
	int n, car;
	struct apartment a[4] = { {111,35},{112, 47},{113,53},{114,42} };
	
	printf("동 입력: ");
	scanf("%d", &n);

	for (int i = 0; i < 4; i++)
		if (n == a[i].dong) 
			car = a[i].car;
	print(car);

	return 0;
}

void print(int car) {
	printf("주차가능 대수: %d", car);
}