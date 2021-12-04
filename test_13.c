

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
		printf("이름 입력: ");
		scanf("%s", t[i].name);
		printf("나이 입력: ");
		scanf("%d", &t[i].age);
		
	
	for(int i=0; i<4; i++)	
		printf("이름은 %s이며 나이는 %d이다.\n", t[i].name , t[i].age);

	
	return 0;
}
