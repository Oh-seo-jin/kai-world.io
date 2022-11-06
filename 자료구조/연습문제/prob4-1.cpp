//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#pragma warning (disable:4996)

int main() {
	int n, count = 0;
	int nums[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", nums + i);
	}

	//for (int i = 0; i < n; i++) {
	//	printf("%d ", nums[i]);
	//}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (nums[i] > nums[j]) {
				count++;
			}
		}
	}

	printf("%d", count);

	return 0;
}