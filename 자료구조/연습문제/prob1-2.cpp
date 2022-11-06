//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

/*
int main(void) {
	int n;
	int min_num;
	scanf("%d", &n);
	while (n < 2 || n > 100) {
		printf("다시 입력하세요.");
		scanf("%d", &n);
	}
	signed int* str = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", (str + i));
	signed int min1 = str[0];
	signed int min2 = str[0];
	for (int i = 1; i < n; i++) {
		if (str[i] <= min1) {
			min1 = str[i];
			min_num = i;
		}
	}
	for (int i = 1; i < n; i++) {
		if (str[i] <= min2 && i != min_num) {
			min2 = str[i];
		}
	}
	printf("%d %d", min1, min2);
	return 0;
}
*/

int main() {
	int n;
	int num[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	//for (int i = 0; i < n; i++)
	//	printf("%d ", num[i]);

	int theMin;
	int theSecond;
	if (num[0] <= num[1]) {
		theMin = num[0];
		theSecond = num[1];
	}
	else {
		theMin = num[1];
		theSecond = num[0];
	}
	for (int i = 0; i < n; i++) {
		if (num[i] <= theMin) {
			theSecond = theMin;
			theMin = num[i];
		}
		else if (num[i] < theSecond) {
			theSecond = num[i];
		}
	}
	printf("%d %d", theMin, theSecond);
}