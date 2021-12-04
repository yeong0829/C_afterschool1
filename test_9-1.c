#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int maxmin(int* n);

void main(void) {
    int arr[4], * n = arr;

    for (int i = 0; i < 5; i++)
        printf("정수 입력: ");
    gets(arr);

    printif("최대값: %d\n", maxmin(arr));


    return 0;
}

int maxmin(int* n) {
    int max = n[0];
    int min = n[0];
    for (int i = 1; i < 5; i++)
        if (n[i] > max) max = n[i];
    //else if (n[i] < min) min = n[i];
    return max;
}