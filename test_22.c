//���� �޸� �Ҵ��� �̿��ؼ� ����ڷκ��� ���� �ּҷ��� �����ϰ� ����ϱ�


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

	printf("�ּ��� ����: ");
	scanf("%d", &size);
	c = (CONTACTS*)malloc(sizeof(CONTACTS) * size);

	
	if (c == NULL) {
		printf("���� �޸� �Ҵ� ����");
		exit(1);
	}
	
	
	for (int i = 0; i < size; i++) {
		printf("�̸� �Է�: ");
		scanf("%s", c[i].name);
		printf("�޴��� ��ȣ �Է�: ");
		scanf("%s", c[i].mobile_phone);
	}
	

	printf("\n---------------------\n");
	printf("\n�̸� �޴��� ��ȣ\n");
	printf("\n---------------------\n");

	for (int i = 0; i < size; i++)
		printf("\n%s %s \n", c[i].name, c[i].mobile_phone);

	printf("\n---------------------\n");

	free(c);
	return 0;

}

