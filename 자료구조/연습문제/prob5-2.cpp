//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#pragma warning (disable:4996)

void load();
void show();
void colmax();
void colmin();
void rowmax();
void rowmin();
void slice(int x, int p, int y, int q);

int N;
int data[MAX_LEN][MAX_LEN];

int main() {
	char command[MAX_LEN];
	int x, y, p, q;

	load();

	while (1) {
		printf("$ ");
		scanf("%s", command);
		if (strcmp(command, "show") == 0) {
			show();
		}
		else if (strcmp(command, "colmax") == 0) {
			colmax();
		}
		else if (strcmp(command, "colmin") == 0) {
			colmin();
		}
		else if (strcmp(command, "rowmax") == 0) {
			rowmax();
		}
		else if (strcmp(command, "rowmin") == 0) {
			rowmin();
		}
		else if (strcmp(command, "slice") == 0) {
			scanf(" %d %d %d %d", &x, &p, &y, & q);
			slice(x,p,y,q);
		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
	}
	return 0;
}

void load() {
	FILE* fp = fopen("data.mat", "r");
	fscanf(fp, "%d ", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(fp, "%d", &data[i][j]);
		}
	}
	fclose(fp);
}

void show() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%2d ", data[i][j]);
		}
		printf("\n");
	}
}

void colmax() {
	int max;
	for (int i = 0; i < N; i++) {
		max = data[0][i];
		for (int j = 1; j < N; j++) {
			if (max < data[j][i])
				max = data[j][i];
		}
		printf("%d ", max);
	}
	printf("\n");
}

void colmin() {
	int min;
	for (int i = 0; i < N; i++) {
		min = data[0][i];
		for (int j = 1; j < N; j++) {
			if (min > data[j][i])
				min = data[j][i];
		}
		printf("%d ", min);
	}
	printf("\n");
}

void rowmax() {
	int max;
	for (int i = 0; i < N; i++) {
		max = data[i][0];
		for (int j = 1; j < N; j++) {
			if (max < data[i][j])
				max = data[i][j];
		}
		printf("%d ", max);
	}
	printf("\n");
}

void rowmin() {
	int min;
	for (int i = 0; i < N; i++) {
		min = data[i][0];
		for (int j = 1; j < N; j++) {
			if (min > data[i][j])
				min = data[i][j];
		}
		printf("%d ", min);
	}
	printf("\n");
}

void slice(int x, int p, int y, int q) {
	for (int i = x; i < N; i += p) {
		for (int j = y; j < N; j += q) {
			printf("%2d ", data[i][j]);
		}
		printf("\n");
	}
}