#include <stdio.h>
#include <string.h>

typedef struct book {
	char bookTitle[50];
	char bookAuthor[20];
	int bookPrice;
	int bookSale;
	char bookCode[8];
}BOOK;
int inBook(BOOK*, int);
void outBook(BOOK*, int);
void searchBook(BOOK*, int);
int main()
{
	int sel, totalBCnt = 0;
	BOOK myBook[100];
	while (1) {
		puts("\n\n���ϴ� �޴��� �����ϼ���");
		puts("1. �����Է�");
		puts("2. �������");
		puts("3. �����˻�");
		puts("0. ���� ");
		scanf("%d", &sel);
		fflush(stdin);
		switch (sel) {
		case 1: totalBCnt = inBook(myBook, totalBCnt); break;
		case 2: outBook(myBook, totalBCnt); break;
		case 3: searchBook(myBook, totalBCnt); break;
		case 0: return 0;
		default: puts("0~3 ������ �޴� ��ȣ�� �����ϼ���");
		}
	}
	return 0;
}

int inBook(BOOK* mb, int cnt)
{
	int number;
	while (1) {
		printf("\nå�ڵ� : ");
		gets(mb[cnt].bookCode);
		if (strlen(mb[cnt].bookCode) == 8)
		{
			number = strspn(mb[cnt].bookCode, "0123456789-");
			if (number == 8 && number != 0)
				break;
		}
		printf("\nå�ڵ带 �ٽ� Ȯ�� �ϼ���  ���� : xxxx-xxx");
	}
	printf("å���� : ");
	gets(mb[cnt].bookTitle);
	printf("���� : ");
	gets(mb[cnt].bookAuthor);
	printf("���� : ");
	scanf("%d", &mb[cnt].bookPrice);
	printf("�Ǹ� ���� : ");
	scanf("%d", &mb[cnt].bookSale);

	return ++cnt;
}

void outBook(BOOK* mb, int cnt)
{
	char sKey[20];
	int i, op;
	char* year;
	int check = 0;
	puts("\n\n���ϴ� �޴��� �����ϼ���");
	puts("1. ��ü��� ");
	puts("2. �⵵����� ");
	scanf("%d", &op);
	fflush(stdin);
	switch (op) {
	case 1: for (i = 0; i < cnt; i++)
	{
		printf("\n-----------------------------------");
		printf("\n��    �� : %s \n", mb[i].bookCode);
		printf("��    �� : %s \n", mb[i].bookTitle);
		printf("��    �� : %s \n", mb[i].bookAuthor);
		printf("��    �� : %d \n", mb[i].bookPrice);
		printf("�Ǹż��� : %d \n", mb[i].bookSale);
	}

		  break;
	case 2:
		printf("\n�˻��� ���ǳ⵵�� �Է��ϼ���: ");
		gets(sKey);

		printf("\n-----------------------------------");
		printf("\n%10s %30s\n", "��    ��", "��     ��");
		for (i = 0; i < cnt; i++)
		{
			strcpy(year, mb[i].bookCode);
			if (!strcmp(strtok(year, "-"), sKey))
			{
				printf("\n%10s %30s", mb[i].bookCode, mb[i].bookTitle);
				check++;
			}

		}
		if (check == 0)
		{
			printf("\n��ġ�ϴ� å�� �����ϴ�. \n");
		}
		break;

	default: puts("1~2 ������ �޴� ��ȣ�� �����ϼ���");
	}


}

void searchBook(BOOK* mb, int cnt)
{
	char sTitle[50];
	int i, search, check = 0;
	puts("\n\n���ϴ� �޴��� �����ϼ���");
	puts("1. ����˻� ");
	puts("2. ���ڰ˻� ");
	scanf("%d", &search);
	fflush(stdin);
	switch (search) {
	case 1: printf("\n\n�˻��� ������ �Է��ϼ���: ");
		gets(sTitle);
		for (i = 0; i < cnt; i++)
		{
			if (strstr(mb[i].bookTitle, sTitle) != NULL)
			{
				printf("\n\n-----------------------------------");
				printf("\n��    �� : %s \n", mb[i].bookCode);
				printf("��    �� : %s \n", mb[i].bookTitle);
				printf("��    �� : %s \n", mb[i].bookAuthor);
				printf("��    �� : %d \n", mb[i].bookPrice);
				printf("�Ǹż��� : %d \n", mb[i].bookSale);
				check++;
			}
		}
		if (check)
		{
			printf("\n-----------------------------------");
			printf("\n�˻� �Ǽ� : %d \n", check);
		}
		else {

			printf("\n-----------------------------------");
			printf("\n��ġ�ϴ� å�� �����ϴ�. \n");
		}

		break;
	case 2: printf("\n\n�˻��� ���ڸ��� �Է��ϼ���: ");
		gets(sTitle);
		for (i = 0; i < cnt; i++)
		{
			if (strstr(mb[i].bookAuthor, sTitle) != NULL)
			{
				printf("\n\n-----------------------------------");
				printf("\n��    �� : %s \n", mb[i].bookCode);
				printf("��    �� : %s \n", mb[i].bookTitle);
				printf("��    �� : %s \n", mb[i].bookAuthor);
				printf("��    �� : %d \n", mb[i].bookPrice);
				printf("�Ǹż��� : %d \n", mb[i].bookSale);
				check++;
			}
		}
		if (check)
		{
			printf("\n-----------------------------------");
			printf("\n�˻� �Ǽ� : %d \n", check);
		}
		else {

			printf("\n-----------------------------------");
			printf("\n��ġ�ϴ� å�� �����ϴ�. \n");
		}

		break;

	default: puts("1~2 ������ �޴� ��ȣ�� �����ϼ���");
	}
}
