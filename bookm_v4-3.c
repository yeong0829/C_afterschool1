#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

typedef struct book{
	char bookCode[9];
	char bookTitle[50];
	char bookAuthor[20];
	int bookPrice;
	int bookSale;	
}BOOK;
BOOK* inBook(BOOK* , int*);
void outBook(BOOK* , int);
void searchBook(BOOK* , int);
BOOK* readBooks(BOOK*, int*);
void saveBooks(BOOK* , int);

int main()
{
	int sel, totalBCnt=0;
	BOOK *myBook;	
	myBook = (BOOK *)calloc(1,sizeof(BOOK));
	myBook = readBooks(myBook,&totalBCnt);
	while(1){
	printf("   %p   " ,myBook);
		puts("\n\n원하는 메뉴를 선택하세요");
		puts("1. 도서입력"); 
		puts("2. 도서출력"); 
		puts("3. 도서검색"); 
		puts("0. 종료 "); 
		scanf("%d", &sel);
		fflush(stdin);
		switch(sel){
			case 1 : myBook = inBook(myBook, &totalBCnt); break;
			case 2 : outBook(myBook, totalBCnt); break;
			case 3 : searchBook(myBook, totalBCnt); break;
			case 0 : saveBooks(myBook,totalBCnt);  return 0;
			default : puts("0~3 사이의 메뉴 번호를 선택하세요");
		}
		
	} 
	return 0;	
}


BOOK* inBook(BOOK* mb, int* cn)
{
	char yn;
	int cnt;
	cnt = *cn;
	do{		
		while(1){			
			fflush(stdin);
			printf("\n책코드 : ");
			gets(mb[cnt].bookCode);
			if (!strcspn(mb[cnt].bookCode, "0123456789-") && (strstr(mb[cnt].bookCode, "-") - mb[cnt].bookCode)==4 && strlen(mb[cnt].bookCode)==8)
				break;
			printf("\n책코드를 다시 확인 하세요  형식 : xxxx-xxx ");
		}
		while(1){			
			fflush(stdin);
			printf("책제목 : ");
			gets(mb[cnt].bookTitle);  
			if ( strlen(mb[cnt].bookTitle) > 0 )
				break;
			printf("\n책제목을 입력하세요 ");
		}	
		while(1){			
			fflush(stdin);
			printf("저자 : ");
			gets(mb[cnt].bookAuthor);  
			if ( strlen(mb[cnt].bookAuthor) > 0 )
				break;
			printf("\n저자를 입력하세요 ");
		}			
		printf("가격 : ");
		scanf("%d",&mb[cnt].bookPrice);
		printf("판매 수량 : ");
		scanf("%d",&mb[cnt].bookSale);
		printf("\n 계속 입력하시겠습니까?(Y/N) ");		
		yn = getche();		
	}while(yn == 'y');
	*cn = cnt;
	return mb;	
}

int compare(const void *a, const void  *b)
{
    BOOK* ptr_a = (BOOK *)a;
    BOOK* ptr_b = (BOOK *)b;
    
    if (ptr_a->bookSale < ptr_b->bookSale) return 1;
    else if (ptr_a->bookSale == ptr_b->bookSale) return 0;
    else return -1;
}

void outBook(BOOK* mb, int cnt)
{
	char sKey[20]; 
 	int i, op;
 	char *year;
	int check=0; 
	char yn;
	do{
		puts("\n\n원하는 메뉴를 선택하세요");
		puts("1. 전체출력 "); 
		puts("2. 년도별출력 "); 
		puts("3. 베스트셀러 "); 		
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1 : for(i=0;i<cnt;i++)
					 {
						printf("\n-----------------------------------");
						printf("\n코    드 : %s \n",mb[i].bookCode);
						printf("제    목 : %s \n",mb[i].bookTitle);
						printf("저    자 : %s \n",mb[i].bookAuthor);
						printf("가    격 : %d \n",mb[i].bookPrice);
						printf("판매수량 : %d \n",mb[i].bookSale);
					 }
					 
					 break;

			case 2 : 
					 printf("\n\n검색할 출판년도를 입력하세요: "); 
			         gets(sKey); 
			         
			         printf("\n-----------------------------------");
						printf("\n%10s %30s\n","코    드", "제     목");
			         for(i=0;i<cnt;i++)
			         {
					 	strcpy(year , mb[i].bookCode);			         	
			         	if (!strcmp(strtok(year,"-"),sKey))
			         	{
			         		printf("\n%10s %30s",mb[i].bookCode, mb[i].bookTitle);
			         		check++;
						}
			         		
					 }
					 if(check == 0)
					 {
					 	printf("\n일치하는 책이 없습니다. \n");
					 }
					 break;
			
			case 3 : qsort(mb, cnt+1, sizeof(BOOK), compare);
					 printf("\n-----------------------------------\n");
					 printf("----------BestSeller Top 3----------");
					 printf("\n-----------------------------------\n");
					 for (int i = 0; i < cnt ; i++) 
					 {
				        printf("Top %d : %30s  Sale: %d\n", i+1, mb[i].bookTitle, mb[i].bookSale );
				     }
					 
					 printf("\n-----------------------------------\n");
					 break;
			
			default : puts("1~3 사이의 메뉴 번호를 선택하세요");
		}
		printf("\n 계속 출력하시겠습니까?(Y/N) ");		
		yn = getche();
		cnt++;
	}while(yn == 'y');
	
	
	
}

void searchBook(BOOK* mb, int cnt)
{
 	char sTitle[50]; 
 	int i, search,check=0;
 	puts("\n\n원하는 메뉴를 선택하세요");
		puts("1. 제목검색 "); 
		puts("2. 저자검색 "); 		
		scanf("%d", &search);
		fflush(stdin);
		switch(search){
			case 1 : printf("\n\n검색할 제목을 입력하세요: "); 
			         gets(sTitle); 
			         for(i=0;i<cnt;i++)
			         {
			         	if (strstr(mb[i].bookTitle,sTitle)!=NULL)
			         	{
			         		printf("\n\n-----------------------------------");
							printf("\n코    드 : %s \n",mb[i].bookCode);
							printf("제    목 : %s \n",mb[i].bookTitle);
							printf("저    자 : %s \n",mb[i].bookAuthor);
							printf("가    격 : %d \n",mb[i].bookPrice);
							printf("판매수량 : %d \n",mb[i].bookSale);
							check++;
						}			         		
					 }
					 if(check)
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n검색 건수 : %d \n", check);
					 }
					 else{
					 
					 	printf("\n-----------------------------------");
					 	printf("\n일치하는 책이 없습니다. \n");
					 }			 
					 
					 break;
			case 2 : printf("\n\n검색할 저자명을 입력하세요: "); 
			         gets(sTitle); 
			         for(i=0;i<cnt;i++)
			         {
			         	if (strstr(mb[i].bookAuthor,sTitle)!=NULL)
			         	{
			         		printf("\n\n-----------------------------------");
							printf("\n코    드 : %s \n",mb[i].bookCode);
							printf("제    목 : %s \n",mb[i].bookTitle);
							printf("저    자 : %s \n",mb[i].bookAuthor);
							printf("가    격 : %d \n",mb[i].bookPrice);
							printf("판매수량 : %d \n",mb[i].bookSale);
							check++;
						}			         		
					 }
					 if(check)
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n검색 건수 : %d \n", check);
					 }
					 else{					 
					 	printf("\n-----------------------------------");
					 	printf("\n일치하는 책이 없습니다. \n");
					 }	
					 		 
					 break;
			
			default : puts("1~2 사이의 메뉴 번호를 선택하세요");
		}	
}

void saveBooks(BOOK* mb, int cnt)
{
   FILE * fp;
   int i;
   fp = fopen ("myBooks.txt" , "w+");
   if (fp == NULL) perror ("Error opening file");
   else {
        fprintf(fp, "%d\n", cnt);
       	for(i=0;i<cnt;i++){  
     		fprintf(fp, "%s %s %s %d %d\n",mb[i].bookCode, mb[i].bookTitle, mb[i].bookAuthor , mb[i].bookPrice , mb[i].bookSale);
     	}
	
     fclose (fp);
   }

}
BOOK* readBooks(BOOK* mb, int* cn)
{
   FILE * fp;
   int i,cnt;
   
   fp = fopen ("myBooks.txt" , "r+");
   if (fp == NULL) perror ("Error opening file");
   else {
   		fscanf(fp,"%d",&cnt);
   		mb = (BOOK*)realloc(mb,sizeof(BOOK)*(cnt+1));
     	for(i=0;i<cnt;i++){     		
     		fscanf(fp, "%s %s %s %d %d",mb[i].bookCode, mb[i].bookTitle, mb[i].bookAuthor , &mb[i].bookPrice , &mb[i].bookSale);  
		 }    		           
     fclose (fp);
   }
   *cn = cnt;
   return mb;

}


