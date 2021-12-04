#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define PI 3.14

struct circle {
	int r;
	double area;
};

void Area(struct circle* c);
int print(int r, int a);

int main(void) {
	struct circle c;

	printf("������ �Է�: ");
	scanf("%d", &c.r);

	Area(&c);
	print("%d %f %d" , c.r, c.area);

	return 0;
}

void Area(struct circle *c) {
	c->area = c->r * c->r * PI;
}

int print(int r, int a) {
	printf("�������� %d�� ���� ���̴� %d�̴�.", r, a);
}