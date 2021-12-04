#include <stdio.h>

int main() {
	char op = "p";
	FILE* fp = NULL;
	fp = fopen("./a.txt", "r");
	if (fp == NULL)  printf(" open fail ");
	else printf("open success\n");

	fscanf(fp, "%c", &op);
	fprintf(stdout, "%c", op);
	

	return 0;
}