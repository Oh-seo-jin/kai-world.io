//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define LINE_MAX 300
#define MAX 10000

void load(char* fileName);
void add(char* str, char* delim, int i);
void sort();
void swap(char** str1, char** str2);
void save(char* fileName);

char** word;
char** explain;
int size = 0;

int main() {
	word = (char**)malloc(MAX * sizeof(char*));
	explain = (char**)malloc(MAX * sizeof(char*));
	char fileName[] = "shuffled_dict.txt";
	load(fileName);
	sort();
	//for (int j = 0; j < size; j++) {
	//	printf(">> %s\t", word[j]);
	//	printf("%s", explain[j]);
	//}
	char saveName[] = "sorted_dict.txt";
	save(saveName);

	
}

void load(char* fileName) {
	char line[LINE_MAX];
	char delim[] = "\t";
	char* tmp1, * tmp2;

	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}

	while (fgets(line, LINE_MAX, fp)!=NULL) {
		printf("%s",line);
		add(line, delim, size);
		size++;
	}

	fclose(fp);
}

void add(char* line, char* delim, int size) {
	char* tmp1, * tmp2;
	tmp1 = strtok(line, delim);
	if (tmp1 == NULL) return;
	word[size] = strdup(tmp1);
	//printf("%s\n", tmp1);
	tmp2 = strtok(NULL, delim);
	explain[size] = strdup(tmp2);
	//printf("%s", tmp2);
}

void sort() {
	char* tmp;
	for (int i = size-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(word[i], word[j]) < 0) {
				tmp = word[i];
				word[i] = word[j];
				word[j] = tmp;

				tmp = explain[i];
				explain[i] = explain[j];
				explain[j] = tmp;
			}
		}

	}
}

void save(char *fileName) {
	FILE* fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}

	for (int i = 0; i < size; i++) {
		fprintf(fp, "%s\t%s", word[i], explain[i]);
	}
	fclose(fp);
}
