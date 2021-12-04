// 도서검색 프로그램
//메뉴: 도서 입력, 도서 출력, 도서 검색, 종료
//기능: 도서 입력, 출력, 제목검색, 저자 검색
//요구사항: 메뉴방식으로 작업 선택
//			제목 최대 50글자
//			저자 최대 20글자
//			검색: 제목검색/ 저자검색
//			최대 100권 관리 가능


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct book {
	char bookTitle[50];
	char bookAuthor[20];
	int bookPrice;
	int bookStock;
}B;

int inBook(B*, int);
void outBook(B*, int);
void searchBook(B*, int);

int main(){
	int choose, totalBCnt = 0;
	B myBook[100];

	//file_read();

	while (1) {
		puts("\n-- 도서 관리 --");
		puts("1. 도서입력");
		puts("2. 도서출력");
		puts("3. 도서검색");
		puts("4. 종료 ");
		puts("메뉴 선택: ");
		scanf("%d", &choose);
		fflush(stdin);

		switch (choose) {
			case 1: totalBCnt = inBook(myBook, totalBCnt); break;
			case 2: outBook(myBook, totalBCnt); break;
			case 3: searchBook(myBook, totalBCnt); break;
			case 4: printf("\n프로그램을 종료합니다.\n"); return 0;
			default: puts("잘못된 입력입니다.");
		}

	}
	return 0;
}

int inBook(B* mb, int cnt){
	printf("\n책 제목 입력: ");
	scanf("%s", &mb[cnt].bookTitle);
	printf("저자명 입력: ");
	scanf("%s", &mb[cnt].bookAuthor);
	printf("가격 입력: ");
	scanf("%d", &mb[cnt].bookPrice);
	printf("수량 입력: ");
	scanf("%d", &mb[cnt].bookStock);
	printf("\n--------------------------\n");

	return ++cnt;
}

void outBook(B* mb, int cnt){
	for (int i = 0; i < cnt; i++)
	{
		printf("\n--------------------------\n");
		printf("\n제목 : %s \n", mb[i].bookTitle);
		printf("저자 : %s \n", mb[i].bookAuthor);
		printf("가격 : %d \n", mb[i].bookPrice);
		printf("수량 : %d \n", mb[i].bookStock);
	}
}

void searchBook(B* mb, int cnt){
	char title[50], author[50];
	int i, choose;
	puts("\n1. 제목검색 ");
	puts("2. 저자검색 ");
	puts("메뉴 선택: ");
	scanf("%d", &choose);
	fflush(stdin);

	switch (choose) {
		case 1: printf("\n검색할 제목 입력: ");
			gets(title);
			for (i = 0; i < cnt; i++) {
				if (!strcmp(mb[i].bookTitle, title)) break;

				if (i == mb[i].bookTitle) {
					printf("\n--------------------------");
					printf("\n제목 : %s \n", mb[i].bookTitle);
					printf("저자 : %s \n", mb[i].bookAuthor);
					printf("가격 : %d \n", mb[i].bookPrice);
					printf("수량 : %d \n", mb[i].bookStock);
				}else {
					printf("\n--------------------------");
					printf("\n잘못입력하셨습니다.\n");
				}break;
			}

		case 2: printf("\n검색할 저자명 입력: ");
			gets(author);
			for (i = 0; i < cnt; i++) {
				if (!strcmp(mb[i].bookAuthor, author)) break;

				if (i == mb[i].bookAuthor) {
					printf("\n--------------------------");
					printf("\n제목 : %s \n", mb[i].bookTitle);
					printf("저자 : %s \n", mb[i].bookAuthor);
					printf("가격 : %d \n", mb[i].bookPrice);
					printf("수량 : %d \n", mb[i].bookStock);
				}else {
					printf("\n--------------------------");
					printf("\n잘못입력하셨습니다.\n");
				}break;
			}

		default: puts("잘못된 입력입니다.");
	}
}
