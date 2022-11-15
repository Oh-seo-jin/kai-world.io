#pragma once
#define MAX 100

typedef struct position {
	int x, y;
}Position;

extern int offset[8][2];
bool moveable(Position cur, int dir);
Position move_to(Position pos, int dir);