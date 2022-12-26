#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define MAX 100
#define PATHWAY 0
#define WALL 1
#define VISIT -2
#pragma warning(disable:4996)

int n, T;
int maze[MAX][MAX];

void print_Maze();
bool findPath(int x, int y);
void read_maze();
int min_distance();

int main() {
	read_maze();
	findPath(0, 0);
	printf("%d\n", min_distance());
}

bool findPath(int x, int y) {

	//좌표가 유효한 범위인가
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;

	//if neighbor on the wall && visited
	else if (maze[x][y] != PATHWAY)
		return false;

	else {
		maze[x][y] = VISIT;

		if (findPath(x - 1, y) || findPath(x, y + 1)
			|| findPath(x + 1, y) || findPath(x, y - 1)) {
			//if findPath(neighbor)
			return true;
		}
	}
}

void print_Maze() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
}

void read_maze() {
	FILE* fp = fopen("maze.txt", "r");
	fscanf(fp, "%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &maze[i][j]);
		}
	}
	//print_Maze();
	fclose(fp);
}

int min_distance() {
	int min = n * n;
	int distance;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] < 0) {
				distance = abs(n - 1 - i) + abs(n - 1 - j);
				if (distance < min)
					min = distance;
			}
		}
	}

	return min;
}