#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#pragma warning (disable:4996)
#define BUFFER_SIZE 100

int main() {
	char str[BUFFER_SIZE];
	scanf("%s", str);

	int num = 0;
	//stack	
	
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') {
			num++;
			printf("%d ", num);
			push(num);
		}
		else if (str[i] == ')') {
			printf("%d ", pop());
		}
	}
}