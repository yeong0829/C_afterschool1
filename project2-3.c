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
		puts("\n\n원하는 메뉴를 선택하세요");
		puts("1. 도서입력");
		puts("2. 도서출력");
		puts("3. 도서검색");
		puts("0. 종료 ");
		scanf("%d", &sel);
		fflush(stdin);
		switch (sel) {
		case 1: totalBCnt = inBook(myBook, totalBCnt); break;
		case 2: outBook(myBook, totalBCnt); break;
		case 3: searchBook(myBook, totalBCnt); break;
		case 0: return 0;
		default: puts("0~3 사이의 메뉴 번호를 선택하세요");
		}
	}
	return 0;
}

int inBook(BOOK* mb, int cnt)
{
	int number;
	while (1) {
		printf("\n책코드 : ");
		gets(mb[cnt].bookCode);
		if (strlen(mb[cnt].bookCode) == 8)
		{
			number = strspn(mb[cnt].bookCode, "0123456789-");
			if (number == 8 && number != 0)
				break;
		}
		printf("\n책코드를 다시 확인 하세요  형식 : xxxx-xxx");
	}
	printf("책제목 : ");
	gets(mb[cnt].bookTitle);
	printf("저자 : ");
	gets(mb[cnt].bookAuthor);
	printf("가격 : ");
	scanf("%d", &mb[cnt].bookPrice);
	printf("판매 수량 : ");
	scanf("%d", &mb[cnt].bookSale);

	return ++cnt;
}

void outBook(BOOK* mb, int cnt)
{
	char sKey[20];
	int i, op;
	char* year;
	int check = 0;
	puts("\n\n원하는 메뉴를 선택하세요");
	puts("1. 전체출력 ");
	puts("2. 년도별출력 ");
	scanf("%d", &op);
	fflush(stdin);
	switch (op) {
	case 1: for (i = 0; i < cnt; i++)
	{
		printf("\n-----------------------------------");
		printf("\n코    드 : %s \n", mb[i].bookCode);
		printf("제    목 : %s \n", mb[i].bookTitle);
		printf("저    자 : %s \n", mb[i].bookAuthor);
		printf("가    격 : %d \n", mb[i].bookPrice);
		printf("판매수량 : %d \n", mb[i].bookSale);
	}

		  break;
	case 2:
		printf("\n검색할 출판년도를 입력하세요: ");
		gets(sKey);

		printf("\n-----------------------------------");
		printf("\n%10s %30s\n", "코    드", "제     목");
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
			printf("\n일치하는 책이 없습니다. \n");
		}
		break;

	default: puts("1~2 사이의 메뉴 번호를 선택하세요");
	}


}

void searchBook(BOOK* mb, int cnt)
{
	char sTitle[50];
	int i, search, check = 0;
	puts("\n\n원하는 메뉴를 선택하세요");
	puts("1. 제목검색 ");
	puts("2. 저자검색 ");
	scanf("%d", &search);
	fflush(stdin);
	switch (search) {
	case 1: printf("\n\n검색할 제목을 입력하세요: ");
		gets(sTitle);
		for (i = 0; i < cnt; i++)
		{
			if (strstr(mb[i].bookTitle, sTitle) != NULL)
			{
				printf("\n\n-----------------------------------");
				printf("\n코    드 : %s \n", mb[i].bookCode);
				printf("제    목 : %s \n", mb[i].bookTitle);
				printf("저    자 : %s \n", mb[i].bookAuthor);
				printf("가    격 : %d \n", mb[i].bookPrice);
				printf("판매수량 : %d \n", mb[i].bookSale);
				check++;
			}
		}
		if (check)
		{
			printf("\n-----------------------------------");
			printf("\n검색 건수 : %d \n", check);
		}
		else {

			printf("\n-----------------------------------");
			printf("\n일치하는 책이 없습니다. \n");
		}

		break;
	case 2: printf("\n\n검색할 저자명을 입력하세요: ");
		gets(sTitle);
		for (i = 0; i < cnt; i++)
		{
			if (strstr(mb[i].bookAuthor, sTitle) != NULL)
			{
				printf("\n\n-----------------------------------");
				printf("\n코    드 : %s \n", mb[i].bookCode);
				printf("제    목 : %s \n", mb[i].bookTitle);
				printf("저    자 : %s \n", mb[i].bookAuthor);
				printf("가    격 : %d \n", mb[i].bookPrice);
				printf("판매수량 : %d \n", mb[i].bookSale);
				check++;
			}
		}
		if (check)
		{
			printf("\n-----------------------------------");
			printf("\n검색 건수 : %d \n", check);
		}
		else {

			printf("\n-----------------------------------");
			printf("\n일치하는 책이 없습니다. \n");
		}

		break;

	default: puts("1~2 사이의 메뉴 번호를 선택하세요");
	}
}
