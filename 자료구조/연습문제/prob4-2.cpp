//�׽�Ʈ ���
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

	//���� �о���� �迭�� �����ϱ�
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

	//���ο���
	for (int j = 0; j < n; j++) {
		cal[j][0] = avg(nums[j], n);
		cal[j][1] = sd(nums[j], cal[j][0], n);
	}

	//���ο���(�����迭 ����)
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

	//���
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
		result += (arr[i] - avg)  * (arr[i] - avg);	//���� �Ǽ� ��ȯ��
	}
	result /= n;
	return sqrt(result);
}