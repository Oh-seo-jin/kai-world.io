#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define MAX 100
#define PATHWAY 0
#define WALL 1
#define VISITED_BLOCK 2	//visited, blocked
#define VISITED_PATH 3	//visited, unknown

int maze[MAX][MAX] = {
	{0,0,0,0,0,0,0,1},
	{0,1,1,0,1,1,0,1},
	{0,0,0,1,0,0,0,1},
	{0,1,0,0,1,1,0,0},
	{0,1,1,1,0,0,1,1},
	{0,1,0,0,0,1,0,1},
	{0,0,0,1,0,0,0,1},
	{0,1,1,1,0,1,0,0}
};
int N = 8;

void printMaze();
bool findPath(int x, int y);

int main() {
	printMaze();
	findPath(0, 0);
	printf("------find------\n");
	printMaze();
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
		maze[x][y] = VISITED_PATH;
		return true;
	}

	//현재위치 != 출구
	else {
		//mark visited cell
		maze[x][y] = VISITED_PATH;

		//for neighbouring cell : 4

		if (findPath(x - 1, y) || findPath(x, y + 1)
			|| findPath(x + 1, y) || findPath(x, y - 1)) {
			//if findPath(neighbor)
			return true;
		} 

		maze[x][y] = VISITED_BLOCK;
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