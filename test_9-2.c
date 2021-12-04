#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 5

int maxmin(int* arr, int* n);

int main(void) {
    int n[4];
    int arr[SIZE];
    char* ch[2] = { "min", "max" };

    //maxmin(arr, n);
    printf("정수 입력: ");
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < 3; i++)
        printf("%s: %d\n", ch[i], n[i]);

    return 0;
}

int maxmin(int* arr, int* n) {
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < 5; i++)
        if (max < arr[i]) max = n[i];
        else if (min > arr[i]) min = n[i];
}