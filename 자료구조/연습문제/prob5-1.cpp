//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#pragma warning (disable:4996)

int isvowel(char c);

int main(){
	char input[MAX_LEN];
	int max=0, start_index=0, final_index=0;
	int max_start=0, max_end=0;
	scanf("%s", &input);

	for (int start_index = 0; start_index < strlen(input); start_index++){
		if (isvowel(input[start_index]) || start_index < final_index)
			continue;
		final_index = start_index;
		while (!isvowel(input[final_index]) && input[final_index] != NULL) {
			final_index++;
		}
		if (max < final_index - start_index) {
			max = final_index - start_index;
			max_start = start_index;
			max_end = final_index;
		}
	}

	//printf("%d, %d\n", max_start, max_end);
	for (int i = max_start; i < max_end; i++) {
		printf("%c", input[i]);
	}
	return 0;
}

int isvowel(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return 1;
	}
	else return 0;
}