//테스트 통과
#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX 100

void swap(int* a, int* b);

int main() {
	int n, max, index, temp;
	int nums[MAX];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", nums+i);
	}

	for (int i = n-1; i > 0; i--) {
		max = nums[0];
		index = 0;
		for (int j = 1; j <= i; j++) {
			if (max < nums[j]) {
				max = nums[j];
				index = j;
			}
		}
		swap(nums + index, nums + i);
		temp = nums[index];
		nums[index] = nums[i];
		nums[i] = temp;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", nums[i]);
	}

	return 0;
}

void swap(int* a, int* b) {
	int* temp;
	temp = a;
	a = b;
	b = temp;
	return;
}