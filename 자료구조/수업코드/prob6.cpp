//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

double prob(int N, int k);

int main(void) {
	srand((unsigned int)time(NULL));
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	double result = prob(n, k);
	printf("%.10f\n", result);
}

double prob(int N, int k) {
	int result = 0;
	for (int test = 0; test < 1000000; test++) {
		int count = 0;
		for (int i = 0; i < N; i++) {
			int r = (rand() % 6) + 1;
			//printf("%d ", r);
			if (r == 1)
				count++;
		}
		//printf("\ncount : %d\n", count);
		if (count >= k)
			result++ ;
		//printf("result : %d\n", result);
	}
	//printf("%.10f\n", (float(result) / 100));
	return (float(result) / 1000000);
}