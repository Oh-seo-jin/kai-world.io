//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX 100

int insert(int n, int num[], int k);

int main() {
	int num[MAX];
	int n = 0, k;

	while (1) {
		scanf("%d", &k);
		if (k == -1) break;
		n = insert(n, num, k);
	}

	return 0;
}

int insert(int n, int num[], int k) {

	int i = 0;
	for (; i < n && num[i] <= k; i++) {
		if (num[i] == k) {
			printf("duplicate\n");
			return n;
		}
	}

	//i : 새로운 정수가 삽입될 위치
	int j = n - 1;
	for (; j >= i; j--) {
		num[j + 1] = num[j];
	}
	num[j + 1] = k;
	n++;
	 
	for (int i = 0; i < n; i++) {
		printf("%d ", num[i]);
	}
	printf("\n");
	return n;
	
}

/*
int main() {
	int num[MAX];
	int n = 0, k;

	while (1) {
		scanf("%d", &k);
		if (k == -1) break;
		bool duplicate = false;
		for (int i = 0; i < n; i++) {
			if (num[i] == k) {
				printf("duplicate\n");
				duplicate = true;
				break;
			}
		}
		if (!duplicate) {
			int j = n - 1;
			while (j>=0 && num[j] > k) {
				num[j + 1] = num[j];
				j--;
			}
			num[j + 1] = k;
			n++;

			for (int i = 0; i < n; i++) {
				printf("%d ", num[i]);
			}
			printf("\n");
		}
	}

	return 0;
}
*/

/*void swap(int* a, int* b);

int main(void) {
	int* nums = (int*)malloc(MAX * sizeof(int));
	signed int in;
	int num = 0;
	while (1) {
		bool pass = false;
		scanf("%d", &in);
		if (in == -1)
			break;
		if (in < 0)
			continue;
		if (num > 0) {
			for (int i = 0; i <= num; i++) {
				if (in == nums[i]) {
					printf("duplicate\n");
					pass = true;
				}
			}
		}
		if (pass) {
			continue;
		}
		nums[num] = in;
		for (int i = 0; i < num; i++) {
			if (nums[num] < nums[i]) {
				//printf("> %d %d\n", nums[i], nums[num]);
				swap(nums + num, nums + i);
				//printf("> %d %d\n", nums[i], nums[num]);
			}
		}
		for (int i = 0; i <= num; i++)
			printf("%d ", nums[i]);
		num++;
		printf("\n");
	}
	return 0;
}

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}*/
