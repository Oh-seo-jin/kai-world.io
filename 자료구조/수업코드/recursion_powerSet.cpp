#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char data[MAX] = { 'a', 'b', 'c' };
bool include[MAX];
int n = strlen(data);

void powerSet(int k);

int main() {
	powerSet(0);
}

void powerSet(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++)
			if (include[i])
				printf("%c ", data[i]);
		printf("\n");
		return;
	}
	include[k] = false;
	powerSet(k + 1);
	include[k] = true;
	powerSet(k + 1);
}
