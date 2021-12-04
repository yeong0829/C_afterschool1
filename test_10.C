#include <stdio.h>
#define SIZE 100

void string(char*);

int main(void) {

	char s[SIZE];

	printf("문자열 입력: ");
	gets_s("%s", s);

	//string(str);
	printf("변환된 문자: %s\n", s);

	return 0;
}

void string(char* s) {
	size_t size = strlen(s);    
	char temp;                      

	for (size_t i = 0; i < size / 2; i++) {
		temp = s[i];
		s[i] = s[(size - 1) - i];
		s[(size - 1) - i] = temp;
	}
}


