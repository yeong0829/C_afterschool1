//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//typedef struct apartment {
//	char num[10]; char name[10]; int weight;
//}P;   //p=struct apartment
//
//int main(void) {
//	char name[10];
//	P p[3] = { {"001","홍길동", 50}, {"002","홍길순", 60} , {"003","아무개", 70} };
//
//
//	while (1) {
//		printf("이름 검색: ");
//		scanf("%s", name);
//		
//		if (name == "n"); break;
//
//		for (int i = 0; i < 3; i++)
//			if (name == p[i].name)
//				printf("회원번호: %s, 이름: %s, 체중: %d\n", p[i].num, p[i].name, p[i].weight);
//			
//	}
//	/*while (1) {
//		printf("이름 검색: ");
//		scanf(" %c", name);
//
//		for (int i = 0; i < 3; i++)
//			if (name == p[i].name)
//				printf("회원번호: %s, 이름: %s, 체중: %d\n", p[i].num, p[i].name, p[i].weight);
//			else if (name == "n")
//				break;
//	}*/
//
//	return 0;
//}


//파일 입출력, 구조체 사용
struct member {
	char name[20], num[4]; int weigth;
};
int data_read(struct member*);
int main() {
	struct member m[100];
	char name[20], num[4]; file[20] = "member.txt";  
	int weigth, check, member_cnt;
	FILE* fpi = NULL, * fpo = NULL;

	member_cnt = data_read(m);
	all_prt(m, member_cnt);


	//printf("사용할 데이터 파일 명 입력: ");
	//gets(file);

	//파일 입력
	//fpo = fopen("member.txt", "w+");
	//if (fpo == NULL) printf("  open fail");
	//else {
	//	while (1) {
	//		fflush(stdin);
	//		printf("input \n");
	//		check = fscanf(stdin, "%s", m[i].name);  if (check == EOF) break;
	//		fflush(stdin);
	//		gets(name); //공백 입력 가능
	//		fscanf(stdin, "%d", &weigth);
	//		fprintf(fpo, "\n%s %s %d", num, name, weigth);
	//		i++;
	//	}
	//}
	//fclose(fpo);

	return 0;
}
//파일 출력 함수
int data_read(struct member* m){
	FILE* fpi int i=0;
	fpi = fopen(file, "r");
	if (fpi == NULL) printf(" open fail ");
	esle{
		printf("회원번호        이름         체중       \n");
		while (1) {
			fscanf(fpi, "%s", m[i].num);
			fscanf(fpi, "%s", m[i].name); fscanf(fpi, "%d", &m[i].weight);
			if (feof(fpi)) break;
			//fprintf(stdout, "%5s %-15s %3d\n", num, name, weight);
			i++;
		}
		//for(int j=0; j<i; j++)
			//fprintf("%5s %-15s %3d\n", m[i].num, m[i].name, m[i].weight);
	}
	fclose(fpi);
	return i;
}

void all_prt(struct member *m, int m_cnt ) {
	for (int j = 0; j < m_cnt; j++)
		fprintf("%5s %-15s %3d\n", m[j].num, m[j].name, m[j].weight);
}