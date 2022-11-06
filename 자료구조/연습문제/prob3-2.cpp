//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX 100

void swap(int a[], int b[]);

int main() {
	int intervals[2][MAX];
	//int intervals[MAX][2];
	int* temp;
	int n, min, index;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &intervals[0][i]);
		scanf("%d", &intervals[1][i]);
	}

	for (int j = 0; j < n; j++) {
		min = intervals[0][j];
		index = j;
		for (int i = j; i < n; i++) {
			if (min > intervals[0][i]) {
				min = intervals[0][i];
				index = i;
			}
		}
		for (int i = j; i < n; i++) {
			if (intervals[0][index] == intervals[0][i] && intervals[1][index] > intervals[1][i]) {
				index = i;
			}
		}
		//swap
		swap(intervals[0]+index, intervals[0]+j);
		swap(intervals[1] + index, intervals[1] + j);
		
		
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", intervals[0][i]);
		printf("%d\n", intervals[1][i]);
	}

	return 0;
}

void swap(int a[], int b[]) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}