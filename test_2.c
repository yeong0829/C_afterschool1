#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double circle(double r);

int main(void) {
	double r;
	printf("원의 반지름 입력: ");
	scanf("%lf", &r);
	printf("원의 넓이: %f\n", circle(r));

	return 0;
}

double circle(double r) {
	return r * r * 3.14;
	
}

