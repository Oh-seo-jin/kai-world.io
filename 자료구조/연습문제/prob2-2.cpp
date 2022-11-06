//테스트 통과
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 30
#define MAX 5000
#pragma warning (disable:4996)

char *words[MAX];
int size = 0;
void add(int a, char* str);
void swap(int a, int b);

int main() {
	char buffer[100];
	char temp[100];

	int  n = 0;
	bool pass;

	FILE* fp = fopen("harry.txt", "r");

	if (fp == NULL) {
		printf("Open failed.\n");
	}
	while (fscanf(fp, "%s", buffer) != EOF) {
		pass = true;
		//중복제거 
		for (int i = 0; i < size; i++){
			if (strcmp(buffer, words[i]) == 0) {
				pass = false;
				break;
			}
		}
		//배열에 정렬하여 저장 
		if (pass) {
			//words[size++] = buffer;
			int j = size - 1;
			while (j >= 0 && strcmp(buffer, words[j]) < 0) {
				words[j + 1] = words[j];
				j--;
			}
			words[j + 1] = strdup(buffer);
			size++;
		}
	}

	fclose(fp);

	for (int i = 0; i < size; i++) {
		printf("%s\n", words[i]);
	}
	
	////bubble sort 
	//for (int i = size; i > 1; i--) {
	//	for (int j = 1; j < i; j++) {
	//		if (strcmp(words[j - 1], words[j]) > 0) {
	//			swap(j - 1, j);
	//		}
	//	}
	//}

	
	//접두사 입력 & 단어 출력 
	scanf("%s", temp);
	for (int j = 0; j < size; j++) {
		if (strncmp(temp, words[j], strlen(temp)) == 0) {
			printf("%s\n", words[j]);
			n++;
		}
	}
	printf("%d\n", n);

	//for (int j = 0; j < size; j++) {
	//	printf("%s\n", words[j]);
	//}

	return 0;
}

void swap(int a, int b) {
	char temp[BUFFER_SIZE];
	strcpy(temp, words[a]);
	strcpy(words[a], words[b]);
	strcpy(words[b], temp);
	return;
}

void add(int a, char* str) {
	for (int i = a; i < size +1; i++) {
		strcpy(words[i+1], words[i]);
	}
	strcpy(words[a], str);
	return;
}
