//테스트 통과
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100
#pragma warning (disable:4996)

double avg(int arr[], int n);
double sd(int arr[], double avg, int n);

int main() {
	int n;
	int nums[MAX][MAX];
	double cal[MAX][MAX] = { 0 };
	int tmp[MAX][MAX];

	//파일 읽어오고 배열에 저장하기
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("Open failed.");
	}
	fscanf(fp, "%d", &n);

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			fscanf(fp, "%d", &nums[j][i]);
		}
	}

	//가로연산
	for (int j = 0; j < n; j++) {
		cal[j][0] = avg(nums[j], n);
		cal[j][1] = sd(nums[j], cal[j][0], n);
	}

	//세로연산(반전배열 생성)
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			tmp[j][i] = nums[i][j];
		}
	}

	//for (int j = 0; j < n; j++) {
	//	for (int i = 0; i < n; i++) {
	//		printf("%d ", tmp[j][i]);
	//	}
	//	printf("\n");
	//}
	//printf("\n");
	
	for (int i = 0; i < n; i++) {
		cal[n][i] = avg(tmp[i], n);
		cal[n + 1][i] = sd(tmp[i], cal[n][i], n);
	}

	//출력
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			printf("%d ", nums[j][i]);
		}
		printf("%.2f ", cal[j][0]);
		printf("%.2f\n", cal[j][1]);
	}

	for (int j = n; j < n + 2; j++) {
		for (int i = 0; i < n; i++) {
			printf("%.2f ", cal[j][i]);
		}
		printf("\n");
	}

	fclose(fp);
}

double avg(int arr[], int n) {
	double result = 0;
	for (int i = 0; i < n; i++) {
		result += arr[i];
	}
	result /= n;
	return result;
}

double sd(int arr[], double avg, int n) {
	double result = 0;
	for (int i = 0; i < n; i++) {
		result += (arr[i] - avg)  * (arr[i] - avg);	//정수 실수 변환됨
	}
	result /= n;
	return sqrt(result);
}