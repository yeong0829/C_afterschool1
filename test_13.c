

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 100

struct p {
	int age;
	char name[10];
};

int main() {
	struct p t[SIZE];
	
	for(int i = 0; i<; i++)
		printf("�̸� �Է�: ");
		scanf("%s", t[i].name);
		printf("���� �Է�: ");
		scanf("%d", &t[i].age);
		
	
	for(int i=0; i<4; i++)	
		printf("�̸��� %s�̸� ���̴� %d�̴�.\n", t[i].name , t[i].age);

	
	return 0;
}
