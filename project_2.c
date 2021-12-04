// �����˻� ���α׷�
//�޴�: ���� �Է�, ���� ���, ���� �˻�, ����
//���: ���� �Է�, ���, ����˻�, ���� �˻�
//�䱸����: �޴�������� �۾� ����
//			���� �ִ� 50����
//			���� �ִ� 20����
//			�˻�: ����˻�/ ���ڰ˻�
//			�ִ� 100�� ���� ����


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
		puts("\n-- ���� ���� --");
		puts("1. �����Է�");
		puts("2. �������");
		puts("3. �����˻�");
		puts("4. ���� ");
		puts("�޴� ����: ");
		scanf("%d", &choose);
		fflush(stdin);

		switch (choose) {
			case 1: totalBCnt = inBook(myBook, totalBCnt); break;
			case 2: outBook(myBook, totalBCnt); break;
			case 3: searchBook(myBook, totalBCnt); break;
			case 4: printf("\n���α׷��� �����մϴ�.\n"); return 0;
			default: puts("�߸��� �Է��Դϴ�.");
		}

	}
	return 0;
}

int inBook(B* mb, int cnt){
	printf("\nå ���� �Է�: ");
	scanf("%s", &mb[cnt].bookTitle);
	printf("���ڸ� �Է�: ");
	scanf("%s", &mb[cnt].bookAuthor);
	printf("���� �Է�: ");
	scanf("%d", &mb[cnt].bookPrice);
	printf("���� �Է�: ");
	scanf("%d", &mb[cnt].bookStock);
	printf("\n--------------------------\n");

	return ++cnt;
}

void outBook(B* mb, int cnt){
	for (int i = 0; i < cnt; i++)
	{
		printf("\n--------------------------\n");
		printf("\n���� : %s \n", mb[i].bookTitle);
		printf("���� : %s \n", mb[i].bookAuthor);
		printf("���� : %d \n", mb[i].bookPrice);
		printf("���� : %d \n", mb[i].bookStock);
	}
}

void searchBook(B* mb, int cnt){
	char title[50], author[50];
	int i, choose;
	puts("\n1. ����˻� ");
	puts("2. ���ڰ˻� ");
	puts("�޴� ����: ");
	scanf("%d", &choose);
	fflush(stdin);

	switch (choose) {
		case 1: printf("\n�˻��� ���� �Է�: ");
			gets(title);
			for (i = 0; i < cnt; i++) {
				if (!strcmp(mb[i].bookTitle, title)) break;

				if (i == mb[i].bookTitle) {
					printf("\n--------------------------");
					printf("\n���� : %s \n", mb[i].bookTitle);
					printf("���� : %s \n", mb[i].bookAuthor);
					printf("���� : %d \n", mb[i].bookPrice);
					printf("���� : %d \n", mb[i].bookStock);
				}else {
					printf("\n--------------------------");
					printf("\n�߸��Է��ϼ̽��ϴ�.\n");
				}break;
			}

		case 2: printf("\n�˻��� ���ڸ� �Է�: ");
			gets(author);
			for (i = 0; i < cnt; i++) {
				if (!strcmp(mb[i].bookAuthor, author)) break;

				if (i == mb[i].bookAuthor) {
					printf("\n--------------------------");
					printf("\n���� : %s \n", mb[i].bookTitle);
					printf("���� : %s \n", mb[i].bookAuthor);
					printf("���� : %d \n", mb[i].bookPrice);
					printf("���� : %d \n", mb[i].bookStock);
				}else {
					printf("\n--------------------------");
					printf("\n�߸��Է��ϼ̽��ϴ�.\n");
				}break;
			}

		default: puts("�߸��� �Է��Դϴ�.");
	}
}
