#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX 100

void swap(int* a, int* b);

int main() {
	//int** intervals = (int**)malloc(2 * MAX * sizeof(int));
	int int_start[MAX], int_end[MAX];
	int temp;
	int n, min, index;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", int_start+i);
		scanf("%d", int_end+i);
	}

	for (int j = 0; j < n; j++) {
		min = int_start[j];
		index = j;
		for (int i = j; i < n; i++) {
			if (min > int_start[i]) {
				min = int_start[i];
				index = i;
			}
		}
		for (int i = j; i < n; i++) {
			if (int_start[index] == int_start[i] && int_end[index] > int_end[i]) {
				index = i;
			}
		}

		//printf(">%d\n", index);
	
		swap(int_start + index, int_start + j);
		swap(int_end + index, int_end + j);

		//for (int i = 0; i < n; i++) {
		//	printf("%d ", int_start[i]);
		//	printf("%d\n", int_end[i]);
		//}

	}

	for (int i = 0; i < n; i++) {
		printf("%d ", int_start[i]);
		printf("%d\n", int_end[i]);
	}

	return 0;
}

void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}