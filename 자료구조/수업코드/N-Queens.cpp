#include <stdio.h>
#include <stdlib.h>
#define N 4

int cols[N + 1];

bool queens(int level);
bool promising(int level);

int main() {
	queens(0);
}

bool queens(int level) {
	if (!promising(level))
		return false;
	else if (level == N) {
		for (int i = 1; i <= N; i++)
			printf("(%d, %d)\n", i, cols[i]);
		return true;
	}
	for (int i = 1; i <= N; i++) {
		cols[level + 1] = i;
		if (queens(level + 1))
			return true;
	}
	return false;
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
}6