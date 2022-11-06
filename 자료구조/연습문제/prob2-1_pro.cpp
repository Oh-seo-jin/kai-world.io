//테스트 통과
#include <stdio.h>
#include <string.h>
#define MAX 20
#pragma warning (disable:4996)

void bubbleSort(char s[]);
void compress(char s[]);

int main() {
	char str1[MAX], str2[MAX];
	scanf("%s", str1);
	scanf("%s", str2);

	//정렬
	bubbleSort(str1);
	bubbleSort(str2);
	//printf("%s %s\n", str1, str2);

	//중복값 제거
	compress(str1);
	compress(str2);
	//printf("%s %s\n", str1, str2);

	//문자열 동일한가
	if (strcmp(str1, str2) == 0) {
		printf("yes");
	}
	else printf("no");
	
	return 0;
}

void bubbleSort(char s[]) {
	for (int i = strlen(s) - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (s[j] > s[j+1]) {
				char tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
}

void compress(char s[]) {
	int j = 0;
	for (int i = 0; i < strlen(s); i++) {
		if (i == 0 || s[i] != s[i - 1]) {
			//survive
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}