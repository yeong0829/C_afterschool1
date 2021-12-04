#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int n[5];
	FILE* fp;
	fp = fopen("a.txt", "w+");
	for (int i = 0; i < 5; i++)
		fscanf(stdin, "%d", &n[i]);
	for (int i = 0; i < 5; i++)
		fprintf(stdout, "%d", n[i]);

	fclose(fp);
	return 0;
}