#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double circle(double r);

int main(void) {
	double r;
	printf("���� ������ �Է�: ");
	scanf("%lf", &r);
	printf("���� ����: %f\n", circle(r));

	return 0;
}

double circle(double r) {
	return r * r * 3.14;
	
}

