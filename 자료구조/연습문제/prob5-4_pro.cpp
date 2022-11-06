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

	FILE* fp = fopen("sample.html", "r");
	FILE* of = fopen("sample.txt", "w");
	int c;
	bool inside_tag = false;
	while ((c = fgetc(fp)) != EOF) {
		if (c == '<')
			inside_tag = true;
		else if (c == '>')
			inside_tag = false;
		else if (!inside_tag)
			fputc(c, of);
	}

	return 0;
}