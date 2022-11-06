//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#pragma warning (disable:4996)

int board[MAX][MAX];
int N;

void load();
bool check(int x, int y);

int main() {

	load();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0)
				continue;

			//check
			if (check(i, j)) {
				if (board[i][j] == 1)
					printf("black\n");
				else
					printf("white\n");
				return 0;
			}
		}
	}

	printf("not finished.\n");
	return 0;
}

void load() {
	FILE* fp = fopen("board.txt", "r");
	fscanf(fp, "%d ", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(fp, "%d", &board[i][j]);
		}
	}
}

int offset[4][2] = {
	{-1,1},
	{1, 0},
	{1, 1},
	{0, 1}
};

bool check(int x, int y) {
	//S, E, SW, SE 방향 확인
	int mystone = board[x][y];
	for (int dir = 0; dir < 4; dir++) {
		int d = 1;
		while (d < 5 
			&& x + d * offset[dir][0] < N 
			&& x + d * offset[dir][1] >= 0
			&& y + d * offset[dir][1] < N) {
			if (board[x + d * offset[dir][0]][y + d * offset[dir][1]] != mystone)
				break;
			d++;
		}
		if (d == 5)
			return true;
	}


	return false;
}