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
		puts("\n\n���ϴ� �޴��� �����ϼ���");
		puts("1. �����Է�"); 
		puts("2. �������"); 
		puts("3. �����˻�"); 
		puts("0. ���� "); 
		scanf("%d", &sel);
		fflush(stdin);
		switch(sel){
			case 1 : myBook = inBook(myBook, &totalBCnt); break;
			case 2 : outBook(myBook, totalBCnt); break;
			case 3 : searchBook(myBook, totalBCnt); break;
			case 0 : saveBooks(myBook,totalBCnt);  return 0;
			default : puts("0~3 ������ �޴� ��ȣ�� �����ϼ���");
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
			printf("\nå�ڵ� : ");
			gets(mb[cnt].bookCode);
			if (!strcspn(mb[cnt].bookCode, "0123456789-") && (strstr(mb[cnt].bookCode, "-") - mb[cnt].bookCode)==4 && strlen(mb[cnt].bookCode)==8)
				break;
			printf("\nå�ڵ带 �ٽ� Ȯ�� �ϼ���  ���� : xxxx-xxx ");
		}
		while(1){			
			fflush(stdin);
			printf("å���� : ");
			gets(mb[cnt].bookTitle);  
			if ( strlen(mb[cnt].bookTitle) > 0 )
				break;
			printf("\nå������ �Է��ϼ��� ");
		}	
		while(1){			
			fflush(stdin);
			printf("���� : ");
			gets(mb[cnt].bookAuthor);  
			if ( strlen(mb[cnt].bookAuthor) > 0 )
				break;
			printf("\n���ڸ� �Է��ϼ��� ");
		}			
		printf("���� : ");
		scanf("%d",&mb[cnt].bookPrice);
		printf("�Ǹ� ���� : ");
		scanf("%d",&mb[cnt].bookSale);
		printf("\n ��� �Է��Ͻðڽ��ϱ�?(Y/N) ");		
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
		puts("\n\n���ϴ� �޴��� �����ϼ���");
		puts("1. ��ü��� "); 
		puts("2. �⵵����� "); 
		puts("3. ����Ʈ���� "); 		
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1 : for(i=0;i<cnt;i++)
					 {
						printf("\n-----------------------------------");
						printf("\n��    �� : %s \n",mb[i].bookCode);
						printf("��    �� : %s \n",mb[i].bookTitle);
						printf("��    �� : %s \n",mb[i].bookAuthor);
						printf("��    �� : %d \n",mb[i].bookPrice);
						printf("�Ǹż��� : %d \n",mb[i].bookSale);
					 }
					 
					 break;

			case 2 : 
					 printf("\n\n�˻��� ���ǳ⵵�� �Է��ϼ���: "); 
			         gets(sKey); 
			         
			         printf("\n-----------------------------------");
						printf("\n%10s %30s\n","��    ��", "��     ��");
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
					 	printf("\n��ġ�ϴ� å�� �����ϴ�. \n");
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
			
			default : puts("1~3 ������ �޴� ��ȣ�� �����ϼ���");
		}
		printf("\n ��� ����Ͻðڽ��ϱ�?(Y/N) ");		
		yn = getche();
		cnt++;
	}while(yn == 'y');
	
	
	
}

void searchBook(BOOK* mb, int cnt)
{
 	char sTitle[50]; 
 	int i, search,check=0;
 	puts("\n\n���ϴ� �޴��� �����ϼ���");
		puts("1. ����˻� "); 
		puts("2. ���ڰ˻� "); 		
		scanf("%d", &search);
		fflush(stdin);
		switch(search){
			case 1 : printf("\n\n�˻��� ������ �Է��ϼ���: "); 
			         gets(sTitle); 
			         for(i=0;i<cnt;i++)
			         {
			         	if (strstr(mb[i].bookTitle,sTitle)!=NULL)
			         	{
			         		printf("\n\n-----------------------------------");
							printf("\n��    �� : %s \n",mb[i].bookCode);
							printf("��    �� : %s \n",mb[i].bookTitle);
							printf("��    �� : %s \n",mb[i].bookAuthor);
							printf("��    �� : %d \n",mb[i].bookPrice);
							printf("�Ǹż��� : %d \n",mb[i].bookSale);
							check++;
						}			         		
					 }
					 if(check)
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n�˻� �Ǽ� : %d \n", check);
					 }
					 else{
					 
					 	printf("\n-----------------------------------");
					 	printf("\n��ġ�ϴ� å�� �����ϴ�. \n");
					 }			 
					 
					 break;
			case 2 : printf("\n\n�˻��� ���ڸ��� �Է��ϼ���: "); 
			         gets(sTitle); 
			         for(i=0;i<cnt;i++)
			         {
			         	if (strstr(mb[i].bookAuthor,sTitle)!=NULL)
			         	{
			         		printf("\n\n-----------------------------------");
							printf("\n��    �� : %s \n",mb[i].bookCode);
							printf("��    �� : %s \n",mb[i].bookTitle);
							printf("��    �� : %s \n",mb[i].bookAuthor);
							printf("��    �� : %d \n",mb[i].bookPrice);
							printf("�Ǹż��� : %d \n",mb[i].bookSale);
							check++;
						}			         		
					 }
					 if(check)
					 {
					 	printf("\n-----------------------------------");
					 	printf("\n�˻� �Ǽ� : %d \n", check);
					 }
					 else{					 
					 	printf("\n-----------------------------------");
					 	printf("\n��ġ�ϴ� å�� �����ϴ�. \n");
					 }	
					 		 
					 break;
			
			default : puts("1~2 ������ �޴� ��ȣ�� �����ϼ���");
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


