#include <stdio.h>
int main()
{
	char c, n[20], out[20];
	FILE* fpi = NULL, * fpo = NULL;

	fpo = fopen("./name.txt", "w+");
	if (fpo == NULL)  printf(" open fail ");
	else {
		gets(n); //fgets(n,20,stdin);
		fputs(n, fpo);
	}
	fclose(fpo);

	fpi = fopen("./name.txt", "r");
	if (fpi == NULL)  printf(" open fail ");
	else {
		fgets(out, 20, fpi);
		puts(out);  // fputs(out,stdout);
	}
	fclose(fpi);
	// --------------------------------------	
	fpo = fopen("./name.txt", "w+");
	while (1) {
		c = fgetc(stdin);
		if (c == EOF)  break;
		else  fputc(c, fpo);
	}
	fclose(fpo);

	fpi = fopen("./name.txt", "r");
	do {
		c = fgetc(fpi);
		putchar(c);
	} while (c != EOF);
	fclose(fpi);






	//fscanf(fp,"%c",&op);


	return 0;
}
