//Å×½ºÆ® Åë°ú
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

int main(void) {
	int n;
	scanf("%d", &n);
	while (n != 0) {
		n /= 2;
		printf("%d ", n);
	}
	return 0;
}
