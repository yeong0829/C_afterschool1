//동적 메모리 할당을 이용해서 사용자로부터 받은 주소록을 저장하고 출력하기


#define _CRT_SECURE_NO_WARNINGS   
#include <stdio.h>
#include <stdlib.h>

typedef struct contacts {
	char name[100];
	char mobile_phone[100];
}

CONTACTS;

int main(void) {
	CONTACTS* c;
	int size;

	printf("주소의 개수: ");
	scanf("%d", &size);
	c = (CONTACTS*)malloc(sizeof(CONTACTS) * size);

	
	if (c == NULL) {
		printf("동적 메모리 할당 오류");
		exit(1);
	}
	
	
	for (int i = 0; i < size; i++) {
		printf("이름 입력: ");
		scanf("%s", c[i].name);
		printf("휴대폰 번호 입력: ");
		scanf("%s", c[i].mobile_phone);
	}
	

	printf("\n---------------------\n");
	printf("\n이름 휴대폰 번호\n");
	printf("\n---------------------\n");

	for (int i = 0; i < size; i++)
		printf("\n%s %s \n", c[i].name, c[i].mobile_phone);

	printf("\n---------------------\n");

	free(c);
	return 0;

}

