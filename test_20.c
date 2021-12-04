#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//struct number {
//	double s, f; int d;
//};

int main(void) {
	/*int n; struct number *p;
	scanf("%d", &n);
	p = (struct number*)malloc(sizeof(struct number)*n);
	for (int i = 0; i < n; i++)
		scanf("%1f", &p[i].s);
	printf("\n\n");

	for (int i = 0; i < n; i++) {
		p[i].d = (int)p[i].s;
		p[i].f = p[i].s - p[i].d;
	}*/


	int n=1; *p;
	scanf("%d", &n);
	p = (int *)malloc(sizeof(int) * 1);
	if (p == NULL) printf("error");
	i = 0;
	while (1) {
		scanf("%d", &p[i]);
		if (p[i] == 0) break;
		n++; i++;
		p= (int *realloc(p, sizeof(int) *n)
		if (p == NULL) printf("error");
	}
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		p[i].d = (int)p[i].s;
		p[i].f = p[i].s - p[i].d;
	}

	printf("정수 부분: %d\n", (int)n);
	printf("실수 부분: %f\n", n - (int)n);

	return 0;
}