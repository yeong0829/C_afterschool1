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
void saveBooks(BOOK* , int);
int readBooks(BOOK*);

int main()
{
	int sel, totalBCnt=0;
	BOOK myBook[100];
	totalBCnt = readBooks(myBook);
	while(1){
		puts("\n원하는 메뉴를 선택하세요");
		puts("1. 도서입력"); 
		puts("2. 도서출력"); 
		puts("3. 도서검색"); 
		puts("0. 종료 "); 
		scanf("%d", &sel);
		fflush(stdin);
		switch(sel){
			case 1 : totalBCnt = inBook(myBook, totalBCnt); break;
			case 2 : outBook(myBook, totalBCnt); break;
			case 3 : searchBook(myBook, totalBCnt); break;
			case 0 : saveBooks(myBook, totalBCnt); return 0;
			default : puts("0~3 사이의 메뉴 번호를 선택하세요");
		}
		
	} 
	return 0;	
}
void saveBooks(BOOK* mb, int cnt)
{
   FILE * fp;
   int i;
   char sp[50]; 
   fp = fopen ("myBooks.txt" , "w");
   if (fp == NULL) perror ("Error opening file");
   else {
        fprintf(fp,"%d\n",cnt);
     	
		 for(i=0;i<cnt;i++){   	
   			fprintf(fp, "%s\n",mb[i].bookCode);
     		fprintf(fp, "%s\n", mb[i].bookTitle);
     		fprintf(fp, "%s\n", mb[i].bookAuthor);
    		fprintf(fp, "%d\n", mb[i].bookPrice);
     		fprintf(fp, "%d\n", mb[i].bookSale);    
		 }
     fclose (fp);
   }
}

int readBooks(BOOK* mb)
{
   FILE * fp;
   int i,cnt;

   fp = fopen ("myBooks.txt" , "r");
   if (fp == NULL) perror ("Error opening file");
   else {
     	fscanf(fp, "%d", &cnt); 
     	for(i=0;i<cnt;i++){     		
     		fscanf(fp, "%s %s %s %d %d",&mb[i].bookCode, &mb[i].bookTitle, &mb[i].bookAuthor , &mb[i].bookPrice , &mb[i].bookSale);	
		 }   
     fclose (fp);
   }
   return cnt;
}

int inBook(BOOK* mb, int cnt)
{
	
	printf("\n책제목 : ");
	gets(mb[cnt].bookTitle);
	printf("저자 : ");
	gets(mb[cnt].bookAuthor);
	printf("가격 : ");
	scanf("%d",&mb[cnt].bookPrice);
	printf("수량 : ");
	scanf("%d",&mb[cnt].bookStock);
	
	return ++cnt;	
}

void outBook(BOOK* mb, int cnt)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		printf("\n-----------------------------------");
		printf("\n제목 : %s \n",mb[i].bookTitle);
		printf("저자 : %s \n",mb[i].bookAuthor);
		printf("가격 : %d \n",mb[i].bookPrice);
		printf("수량 : %d \n",mb[i].bookStock);
	}
}

void searchBook(BOOK* mb, int cnt)
{
 	char sTitle[50]; 
 	int i, search;
 	puts("\n원하는 메뉴를 선택하세요");
		puts("1. 제목검색 "); 
		puts("2. 저자검색 "); 		
		scanf("%d", &search);
		fflush(stdin);
		switch(search){
			case 1 : printf("\n검색할 제목을 입력하세요: "); 
			         gets(sTitle); 
			         for(i=0;i<cnt;i++)
			         {
			         	if (!strcmp(mb[i].bookTitle,sTitle))
			         		break;
					 }
					 if(i<cnt)
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n제목 : %s \n",mb[i].bookTitle);
				  	 	printf("저자 : %s \n",mb[i].bookAuthor);
				 	 	printf("가격 : %d \n",mb[i].bookPrice);
					 	printf("수량 : %d \n",mb[i].bookStock);
					 }
					 else
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n일치하는 책이 없습니다. \n");
					 }			 
					 
					 break;
			case 2 : printf("\n검색할 저자명을 입력하세요: "); 
			         gets(sTitle); 
			         for(i=0;i<cnt;i++)
			         {
			         	if (!strcmp(mb[i].bookAuthor,sTitle))
			         		break;
					 }
					 if(i<cnt)
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n제목 : %s \n",mb[i].bookTitle);
				  	 	printf("저자 : %s \n",mb[i].bookAuthor);
				 	 	printf("가격 : %d \n",mb[i].bookPrice);
					 	printf("수량 : %d \n",mb[i].bookStock);
					 }
					 else
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n일치하는 책이 없습니다. \n");
					 }
					 break;
			
			default : puts("1~2 사이의 메뉴 번호를 선택하세요");
		}	
}
