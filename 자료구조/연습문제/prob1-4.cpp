//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main(void) {
	int n, k;
	scanf("%d", &n);
	while (n > 100) {
		printf("다시 입력하세요.");
		scanf("%d", &n);
	}
	signed int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}
	scanf("%d", &k);
	int cl_num = 0;
	int close = abs(k - arr[0]);
	for (int i = 1; i < n; i++) {
		if (abs(k - arr[i]) < close) {
			close = abs(k - arr[i]);
			cl_num = i;
		}

	}
	printf("%d", arr[cl_num]);
	return 0;
}