#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define BUFFER_SIZE 20

int read_line(char str[], int n);

int main(void) {
	char buffer[BUFFER_SIZE];
	while (1) {
		printf("$ ");
		//fgets(buffer,BUFFER_SIZE,stdin);	//데이터 저장, 크기, 표준입력파일(키보드)
		//buffer[strlen(buffer) - 1] = '\0';
		int len = read_line(buffer, BUFFER_SIZE);
		printf("%s:%d\n", buffer, len);
	}

	return 0;
}

//함수 만들어서 사용하기 
int read_line(char str[], int limit) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < limit-1)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

