#include "pos.h"
#include "queueADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

#define PATH 0
#define WALL 1

int n, m, T;
int maze[MAX][MAX];

void read_maze();
void print_maze();
bool movable(Position pos, int dir);

int main() {

	read_maze();

	Queue queue = create();
	Position cur;
	cur.x = 0;
	cur.y = 0;

	enqueue(queue, cur);
	maze[0][0] = -1;
	bool found = false;

	while (!is_empty(queue)) {
		Position cur = dequeue(queue);

		for (int dir = 0; dir < 4; dir++) {
			if (moveable(cur, dir)) {
				Position p = move_to(cur, dir);
				maze[p.x][p.y] = maze[cur.x][cur.y] - 1;
				printf("maze[%d][%d] : %d\n", p.x, p.y, maze[p.x][p.y]);
				if (p.x == n - 1 && p.y == n - 1) {
					printf("Found the path.\n");
					found = true;
					break;
				}
				enqueue(queue, p);
			}
		}
	}
	if (!found) {
		printf("No path exists.\n");
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
	print_maze();
	fclose(fp);
}

void print_maze() {
	printf("----------\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
}

bool moveable(Position cur, int dir) {
	if (cur.x + offset[dir][0] < 0
		|| cur.y + offset[dir][1] < 0
		|| cur.x + offset[dir][0] >= n
		|| cur.y + offset[dir][1] >= n)
		return false;
	//printf("maze[%d][%d] = %d\n", cur.x + offset[dir][0], cur.y + offset[dir][1], maze[cur.x + offset[dir][0]][cur.y + offset[dir][1]]);
	if (maze[cur.x + offset[dir][0]][cur.y + offset[dir][1]] == PATH)
		return true;
	return false;
}