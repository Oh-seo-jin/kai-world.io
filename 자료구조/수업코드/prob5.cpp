//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

void swap(int* a, int* b);

int main(void) {
	int n, dup = 0;
	bool pass = false;
	scanf("%d", &n);
	while (n > 100) {
		printf("다시 입력하세요.");
		scanf("%d", &n);
	}
	int* arr = (int*)malloc(n * sizeof(int));
	int* arr2 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				swap(arr + i, arr + j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		arr2[i] = arr[i+dup];
		for (int j = i+dup+1; j < n; j++) {
			if (arr2[i] == arr[j]) {
				dup++;
			}
			else break;
		}
	}
	printf("%d: ", n - dup);
	for (int i = 0; i < n - dup; i++)
		printf("%d ", arr2[i]);
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
