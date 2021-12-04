#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct num {
	int a;
	int b; 
	double avg;
};

int main() {
	struct num t;
	scanf("%d %d", &t.a, &t.b);
	t.avg = (t.a + t.b) / 2;
	printf("ЦђБе: %f\n", t.avg);

	return 0;
}
