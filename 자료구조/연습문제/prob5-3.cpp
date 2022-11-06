//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#pragma warning (disable:4996)

int board[MAX][MAX];
int N;

void load();
int check_row();	//1성공 0실패
int check_col();
int check_cross();

int main() {

	load();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	//printf("=====row check=====\n");
	check_row();
	//printf("=====col check=====\n");
	check_col();
	//printf("=====cross check=====\n");
	check_cross();



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

int check_row() {
	int player = NULL;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (player == NULL && board[i][j] != 0) {
				player = board[i][j];
				//printf("[%d][%d] player:%d \n", i, j, player);
			}

			if (player != NULL) {
				if (board[i][j] == 0) {
					count = 0;
					continue;
				}

				else if (player != board[i][j]) {
					count = 0;
					player = board[i][j];
					//printf("[%d][%d] change player:%d \n", i, j, player);
				}

				else if (player == board[i][j]) {
					count++;
					//printf(">%d\n", count);
				}
			}
			if (count >= 4) {
				player == 1 ? printf("Black\n") : printf("White\n");
				return 1;
			}
		}
	}
	return 0;
}

int check_col () {
	int player = NULL;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (player == NULL && board[j][i] != 0) {
				player = board[j][i];
				//printf("[%d][%d] player:%d \n", j, i, player);
			}
			if (player != NULL) {
				if (board[j][i] == 0) {
					count = 0;
					continue;
				}

				else if (player != board[j][i]) {
					count = 0;
					player = board[j][i];
					//printf("[%d][%d] change player:%d \n", j, i, player);
				}

				else if (player == board[j][i]) {
					count++;
					//printf(">%d\n", count);
				}
			}
			if (count >= 4) {
				player == 1 ? printf("Black\n") : printf("White\n");
				return 1;
			}
		}
	}
	return 0;
}

int check_cross() {
	int player = NULL;
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (player == NULL && board[i][j] != 0) {
				player = board[i][j];
				//printf("[%d][%d] player:%d >%d\n", i, j, player,count);
			}
			if (player != NULL) {

				if (board[i][j] == 0) {
					count = 0;
					continue;
				}

				else if (player != board[i][j]) {
					count = 0;
					player = board[i][j];
					//printf("[%d][%d] change player:%d \n", i, j, player);
				}
				//printf(":::[%d][%d] player:%d \n", i, j, player);

				//8시방향
				int k = 1;
				while (k < 5) {
					if (player != board[i + k][j - k]) {
						//printf("X [%d][%d] player:%d >%d\n", i+k, j-k, player, count);
						count = 0;
						break;
					}
					else if (player == board[i+k][j-k]) {
						//printf("[%d][%d] player:%d >%d\n", i + k, j - k, player, count);
						count++;
					}
					k++;
				}
				if (count >= 4) {
					player == 1 ? printf("Black\n") : printf("White\n");
					return 1;
				}

				//5시방향
				k = 1;
				while (k < 5) {
					if (player != board[i + k][j + k]) {
						//printf("X [%d][%d] player:%d >%d\n", i + k, j + k, player, count);
						count = 0;
						break;
					}
					else if (player == board[i + k][j + k]) {
						//printf("[%d][%d] player:%d >%d\n", i + k, j + k, player, count);
						count++; 
					}

					k++;
				}
				if (count >= 4) {
					player == 1 ? printf("Black\n") : printf("White\n");
					return 1;
				}
			}
			
		}
	}
	return 0;
}