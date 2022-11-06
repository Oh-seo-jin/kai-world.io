//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
#pragma warning (disable:4996)

void load();
void remove_tag();

char data[MAX][MAX];
int size = 0;

int main() {

	load();
	remove_tag();

	return 0;
}

void load() {
	char line[MAX];
	FILE* fp = fopen("sample.html", "r");

	while (fgets(data[size], MAX, fp) != NULL) {
		printf("[%d]%s\n",size, data[size]);
		size++;
	}
	fclose(fp);
}

void remove_tag() {
	FILE* fp = fopen("sample.txt", "w");;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < strlen(data[i]); j++) {
			if (data[i][j] == '<') {
				for (j = j + 1; j < strlen(data[i]); j++) {
					if (data[i][j] == '>')
						break;
				}
			}
			else {
				printf("%c", data[i][j]);
				fprintf(fp, "%c", data[i][j]);
			}
		}
	}
	fclose(fp);
}

