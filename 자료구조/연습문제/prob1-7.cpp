//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

char** sort(char** str, int size);

int main(void) {
	int n;
	scanf("%d", &n);
	char** words = (char**)malloc(n * 20);
	char str[20];

	for (int i = 0; i < n; i++) {
		scanf("%s", str);
		words[i] = strdup(str);
	}

	words = sort(words, n);

	for (int i = 0; i < n; i++) {
		printf("%s\n", words[i]);
	}
	return 0;
}

char** sort(char** str, int size) {
	int minlen = strlen(str[0]);
	char temp[20];
	char** arr = (char**)malloc(size * 20);
	for (int i = 1; i < size; i++) {
		if (strlen(str[i]) < minlen) {
			minlen = strlen(str[i]);
		}
	}
	int count = 0;
	while (count < size) {
		for (int i = 0; i < size; i++) {
			if (strlen(str[i]) == minlen) {
				arr[count] = str[i];
				count++;
			}
		}
		minlen++;
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			if ((strcmp(arr[i], arr[j]) < 0) && (strlen(arr[i]) == strlen(arr[j]))) {
				strcpy(temp, arr[i]);
				strcpy(arr[i], arr[j]);
				strcpy(arr[j], temp);
			}
		}
	}
	return arr;
}