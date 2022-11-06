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
		//fgets(buffer,BUFFER_SIZE,stdin);	//������ ����, ũ��, ǥ���Է�����(Ű����)
		//buffer[strlen(buffer) - 1] = '\0';
		int len = read_line(buffer, BUFFER_SIZE);
		printf("%s:%d\n", buffer, len);
	}

	return 0;
}

//�Լ� ���� ����ϱ� 
int read_line(char str[], int limit) {
	int ch, i = 0;

	while ((ch = getchar()) != '\n') {
		if (i < limit-1)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

