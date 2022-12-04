//테스트 통과
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define MAX 100
#define PATHWAY 0
#define WALL 1
#define VISITED_BLOCK 2	//visited, blocked
#define VISITED_PATH 3	//visited, unknown

int maze[MAX][MAX] = {
	{0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0},
	{0,0,0,1,0,0,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,0,0,0},
	{1,0,0,0,1,0,0},
	{1,0,1,0,0,0,0}
};

//int maze[MAX][MAX] = {
//	{0,0,0,0},
//	{0,0,1,0},
//	{1,0,1,0},
//	{0,0,0,0}
//};

int offset[4][2] = {
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};

int N = 7;
int count = 0;

void printMaze();
bool findPath(int x, int y);

int main() {
	//printMaze();
	findPath(0, 0);
	//printf("------find------\n");
	printf("%d\n", count);
	//printMaze();
}

bool findPath(int x, int y) {

	//좌표가 유효한 범위인가
	if (x < 0 || y < 0 || x >= N || y >= N)
		return false;

	//if neighbor on the wall && visited
	else if (maze[x][y] != PATHWAY)
		return false;

	//현재위치 = 출구
	else if (x == N - 1 && y == N - 1) {
		count++;
		//printf("====================\n");
		//printMaze();
		return true;
	}

	//현재위치 != 출구
	else {
		maze[x][y] = VISITED_PATH;
		//printf(">>[%d][%d]%d\n", x, y, maze[x][y]);

		//for neighbouring cell : 4
		for (int dir = 0; dir < 4; dir++) {
			findPath(x + offset[dir][0], y + offset[dir][1]);
		}

		//지나간 자리 다시 초기화
		maze[x][y] = PATHWAY;
		return false;
	}
}

void printMaze() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}