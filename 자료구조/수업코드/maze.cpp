#include "stackADT.h"
#include "pos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

#define PATH 0
#define WALL 1
#define VISITED 2
#define BACKTRACKED 3

//배열과 스택 모두 초기화

int n, m, T;
int maze[MAX][MAX];

void read_maze();
void print_maze();
bool movable(Position pos, int dir);

int main() {

	read_maze();

	Stack s = create();
	Position cur;
	cur.x = 0;
	cur.y = 0;

	int init_dir = 0;

	while (1) {
		maze[cur.x][cur.y] = VISITED;

		if (cur.x == m - 1 && cur.y == n - 1) {
			printf("Found the path.\n");
			print_maze();
			break;
		}

		bool forwarded = false;
		for (int dir = init_dir; dir < 4; dir++) {
			//printf("방향: %d, 가능: %d\n", dir, moveable(cur, dir));
			if (moveable(cur, dir)) {
				push(s, dir);
				cur = move_to(cur, dir);
				//printf("cur: %d, %d\n", cur.x, cur.y);
				forwarded = true;
				init_dir = 0;
				break;
			}
		}
		if (!forwarded) {
			list(s);
			maze[cur.x][cur.y] = BACKTRACKED;
			if (is_empty(s)) {
				printf("No path exists.\n");
				break;
			}
			int d = pop(s);
			cur = move_to(cur, (d + 2) % 4);

			init_dir = d + 1;
		}
		if (forwarded)
			print_maze();
	}



}

void read_maze() {
	FILE* fp = fopen("maze.txt", "r");
	fscanf(fp, "%d", &n);
	fscanf(fp, "%d", &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fscanf(fp, "%d", &maze[i][j]);
		}
	}
	print_maze();
	fclose(fp);
}

void print_maze() {
	printf("----------\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
}

bool moveable(Position cur, int dir) {
	if (cur.x + offset[dir][0] < 0
		|| cur.y + offset[dir][1] < 0
		|| cur.x + offset[dir][0] >= m
		|| cur.y + offset[dir][1] >= n)
		return false;
	//printf("maze[%d][%d] = %d\n", cur.x + offset[dir][0], cur.y + offset[dir][1], maze[cur.x + offset[dir][0]][cur.y + offset[dir][1]]);
	if (maze[cur.x + offset[dir][0]][cur.y + offset[dir][1]] == PATH)
		return true;
	return false;
}