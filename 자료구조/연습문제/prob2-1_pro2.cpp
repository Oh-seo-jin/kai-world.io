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

	int flag1[26] = { 0 };	//배열 초기화
	for (int i = 0; i < strlen(str1); i++) {
		flag1[str1[i]-'a'] = 1;	//ASCII코드 값
	}

	int flag2[26] = { 0 };	//배열 초기화
	for (int i = 0; i < strlen(str1); i++) {
		flag2[str2[i] - 'a'] = 1;	//ASCII코드 값
	}

	for (int i = 0; i < 26; i++) {
		if (flag1[i] != flag2[i]) {
			printf("no");
			return 0;
		}
	}
	printf("yes");
}

void bubbleSort(char s[]) {
	for (int i = strlen(s) - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (s[j] > s[j + 1]) {
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