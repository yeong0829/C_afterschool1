#define _CER_SECURE_NO_WARNINGS
#include <stdio.h>

int check();

int main(void) {
	char pass;

	printf("��й�ȣ: ");
	for (int i = 0; i <= 3; i++)
		gets(pass);

	check(pass);

	return 0;
}

int check(char pass) {
	static int count = 0;
	static int password = 123;

	if (strcmp(pass == password)) {
		printf("�α��� ����");
	}
	else {
		count++;
	}
	if (count > 3) {
		printf("������ ���ϴ�.");
	}
}