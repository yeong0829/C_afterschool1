#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#define year 2021

int gender(char *);

void main(){
	char n[8];
	int age, byear;
	puts("당신의 주민 번호를 입력하세요:");
	puts("예)880123-1");
	scanf("%s", n);
	num(n);

	return 0;
}

int gender(char* n) {
	if (n[7] == '1') {
		printf("성별: 남성");
	}
	else if (n[7] == '2') {
		printf("성별: 여성");
	}
	else {
		printf("잘못 입력 하셨습니다.");
	}
}

//주민번호를 입력받고 함수로 전달
//함수에서 나이와 성별 추출
