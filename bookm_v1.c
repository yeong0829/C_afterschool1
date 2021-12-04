#include <stdio.h>
#include <string.h>

typedef struct book{
	char bookTitle[50];
	char bookAuthor[20];
	int bookPrice;
	int bookStock;
}BOOK;
int inBook(BOOK* , int);
void outBook(BOOK* , int);
void searchBook(BOOK* , int);
int main()
{
	int sel, totalBCnt=0;
	BOOK myBook[100];
	while(1){
		puts("\n���ϴ� �޴��� �����ϼ���");
		puts("1. �����Է�"); 
		puts("2. �������"); 
		puts("3. �����˻�"); 
		puts("0. ���� "); 
		scanf("%d", &sel);
		fflush(stdin);
		switch(sel){
			case 1 : totalBCnt = inBook(myBook, totalBCnt); break;
			case 2 : outBook(myBook, totalBCnt); break;
			case 3 : searchBook(myBook, totalBCnt); break;
			case 0 : return 0;
			default : puts("0~3 ������ �޴� ��ȣ�� �����ϼ���");
		}
		
	} 
	return 0;	
}

int inBook(BOOK* mb, int cnt)
{
	
	printf("\nå���� : ");
	gets(mb[cnt].bookTitle);
	printf("���� : ");
	gets(mb[cnt].bookAuthor);
	printf("���� : ");
	scanf("%d",&mb[cnt].bookPrice);
	printf("���� : ");
	scanf("%d",&mb[cnt].bookStock);
	
	return ++cnt;	
}

void outBook(BOOK* mb, int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		printf("\n-----------------------------------");
		printf("\n���� : %s \n",mb[i].bookTitle);
		printf("���� : %s \n",mb[i].bookAuthor);
		printf("���� : %d \n",mb[i].bookPrice);
		printf("���� : %d \n",mb[i].bookStock);
	}
}

void searchBook(BOOK* mb, int cnt)
{
 	char sTitle[50]; 
 	int i, search;
 	puts("\n���ϴ� �޴��� �����ϼ���");
		puts("1. ����˻� "); 
		puts("2. ���ڰ˻� "); 		
		scanf("%d", &search);
		fflush(stdin);
		switch(search){
			case 1 : printf("\n�˻��� ������ �Է��ϼ���: "); 
			         gets(sTitle); 
			         for(i=0;i<cnt;i++)
			         {
			         	if (!strcmp(mb[i].bookTitle,sTitle))
			         		break;
					 }
					 if(i<cnt)
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n���� : %s \n",mb[i].bookTitle);
				  	 	printf("���� : %s \n",mb[i].bookAuthor);
				 	 	printf("���� : %d \n",mb[i].bookPrice);
					 	printf("���� : %d \n",mb[i].bookStock);
					 }
					 else
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n��ġ�ϴ� å�� �����ϴ�. \n");
					 }			 
					 
					 break;
			case 2 : printf("\n�˻��� ���ڸ��� �Է��ϼ���: "); 
			         gets(sTitle); 
			         for(i=0;i<cnt;i++)
			         {
			         	if (!strcmp(mb[i].bookAuthor,sTitle))
			         		break;
					 }
					 if(i<cnt)
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n���� : %s \n",mb[i].bookTitle);
				  	 	printf("���� : %s \n",mb[i].bookAuthor);
				 	 	printf("���� : %d \n",mb[i].bookPrice);
					 	printf("���� : %d \n",mb[i].bookStock);
					 }
					 else
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n��ġ�ϴ� å�� �����ϴ�. \n");
					 }
					 break;
			
			default : puts("1~2 ������ �޴� ��ȣ�� �����ϼ���");
		}	
}