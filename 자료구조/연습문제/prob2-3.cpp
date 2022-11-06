//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 30
#define MAX 5000
#pragma warning (disable:4996)

void swap(int a, int b);
void remove(int a);
char *words[MAX];
int size = 0;

int main() {
	char fileName[BUFFER_SIZE], temp[BUFFER_SIZE];
	char buffer[BUFFER_SIZE] = { 0 };
	char numbers[MAX] = { 0 };

	scanf("%s", fileName);
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Open failed.\n");
	}
	while (fscanf(fp, "%s", buffer) != EOF) {
		if (strlen(buffer) < 6) {
			continue;
		}
	
		bool duplicate = false;
		for (int i = 0; i < size; i++) {
			if (strcmp(buffer, words[i]) == 0) {
				duplicate = true;
				numbers[i]++;
				break;
			}
		}

		if (!duplicate) {
			int j = size - 1;
			while (j >= 0 && strcmp(buffer, words[j]) < 0) {
				words[j + 1] = words[j];
				numbers[j + 1] = numbers[j];
				j--;
			}
			words[j + 1] = strdup(buffer);
			size++;
		}
	}

	fclose(fp);

	//for (int i = 0; i < size; i++) {
	//	printf("%s\n", words[i]);
	//}

	////정렬
	//for (int i = size; i > 1; i--) {
	//	for (int j = 1; j < i; j++) {
	//		if (strcmp(words[j - 1], words[j]) > 0) {
	//			swap(j - 1, j);
	//		}
	//	}
	//}

	////중복제거
	//int k = 0;
	//while (k < size-1){
	//	int i = k + 1;
	//	while (i < size) {
	//		if (strcmp(words[k], words[i]) == 0) {
	//			numbers[k] += 1;
	//			remove(i);
	//		}
	//		else {
	//			i++;
	//			k++;
	//			break;
	//		}
	//	}
	//}

	for (int i = 0; i < size; i++) {
		printf("%s: %d\n", words[i], numbers[i]+1);
	}

	printf("%d", size);

	return 0;
}

void swap(int a, int b) {
	char temp[BUFFER_SIZE];
	strcpy(temp, words[a]);
	strcpy(words[a], words[b]);
	strcpy(words[b], temp);
	return;
}

void remove(int a) {
	int i;
	for (int i = a-1; i < size-1; i++) {
		strcpy(words[i], words[i + 1]);
	}
	size--;
	return;
}