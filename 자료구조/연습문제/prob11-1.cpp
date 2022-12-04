//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#define MAX 15

int cols[MAX+1];

int queens(int level,int N);
bool promising(int level);
void print_queens(int N);
void clear_cols(int N);

int main() {
	for (int i = 1; i <= 15; i++) {
		//printf("----- N: %d -----\n", i);
		printf("N=%d: %d\n",i, queens(0,i));
	}
}	

int queens(int level, int N) {
	int count = 0;
	if (!promising(level))	//충돌하면 더이상 탐색하지 않음
		return count;
	else if (level == N) {	//마지막 level node 도착하면 성공
		//print_queens(N);
		count++;
		//printf(">>count: %d\n", count);

	}
	for (int i = 1; i <= N && level < N; i++) {	//탐색 필요
		cols[level + 1] = i;
		//printf("cols[%d] = %d\n", level + 1, i);
		int result = queens(level + 1, N);
		if (result) {
			count += result;
		}
	}
	return count;
}

bool promising(int level) {
	//마지막 말이 충돌하는지만 검사하면 충분
	for (int i = 1; i < level; i++) {
		if (cols[i] == cols[level])
			return false;
		else if (level - i == abs(cols[level] - cols[i]))
			return false;
	}
	return true;
}

void print_queens(int N) {
	for (int i = 1; i <= N; i++)
		printf("(%d, %d)\n", i, cols[i]);
	printf("\n");
}

void clear_cols(int N) {
	for (int i = 1; i < N; i++) {
		cols[i] = 0;
	}
}