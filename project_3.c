#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define year 2021

int gender(char *);

void main(){
	char n[8];
	int age, byear;
	puts("����� �ֹ� ��ȣ�� �Է��ϼ���:");
	puts("��)880123-1");
	scanf("%s", n);
	num(n);

	return 0;
}

int gender(char* n) {
	if (n[7] == '1') {
		printf("����: ����");
	}
	else if (n[7] == '2') {
		printf("����: ����");
	}
	else {
		printf("�߸� �Է� �ϼ̽��ϴ�.");
	}
}

//�ֹι�ȣ�� �Է¹ް� �Լ��� ����
//�Լ����� ���̿� ���� ����
