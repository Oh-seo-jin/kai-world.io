//�׽�Ʈ ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define LINE_MAX 100
#pragma warning (disable:4996)

void compress(char* str);
//int spchar(char str[]);

int main() {
	int m, n;
	char *table[MAX][LINE_MAX];
	char line[LINE_MAX];
	char delim[] = "&";
	int maxlen[MAX];

	FILE* fp = fopen("table.txt", "r");
	if (fp == NULL) {
		printf("Open failed.\n");
	}
	fscanf(fp, "%d", &m);
	fscanf(fp, "%d ", &n);
	//������ �а� �ٹٲ��� ���� ���� ����
	//%d ���� ������ �θ� white space�� �Һ���.

	//fgets(line, LINE_MAX, fp);	//������ line �ѱ�

	for (int i = 0; i < m ; i++) {
		fgets(line, LINE_MAX, fp);

		//�ٹٲ� ����
		int j = strlen(line)-1;
		if (line[j] == '\n') {
			line[j] = '\0';
		}
		//printf("%s\n", line);

		//strtok�� �� ����
		table[i][0] = strdup(strtok(line, delim));
		for (int j = 1; j < n; j++) {
			table[i][j] = strdup(strtok(NULL, delim));
		}

		//��������
		for (int j = 0; j < n; j++) {
			compress(table[i][j]);
			//if (table[i][j][0] == ' ') remove(table[i][j], 0);
			//int k = 0;
			//while (table[i][j][k]) {
			//	if (k > 0 && table[i][j][k - 1] == table[i][j][k] && table[i][j][k] == ' ') {
			//		remove(table[i][j], k);
			//		continue;
			//	}
			//	k++;
			//}
			//if (table[i][j][k-1] == ' ') table[i][j][k-1] = '\0';

		}
		//for (int j = 0; j < n; j++) {
		//}
		//printf("\n");
	}

	fclose(fp);

	//���� �ִ���� ���ϱ�
	for (int i = 0; i < n; i++) {
		maxlen[i] = strlen(table[0][i]);
		for (int j = 1; j < m; j++) {
			if (maxlen[i] < strlen(table[j][i])) {
				maxlen[i] = strlen(table[j][i]);
			}
		}

	}

	////���
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++) {
	//		printf("%s|", table[i][j]);
	//	}
	//	printf("\n");
	//}

	char fileName[] = "output.txt";
	fp = fopen(fileName, "w");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(fp, "%s", table[i][j]);
			int empty = maxlen[j] - strlen(table[i][j]);
			//printf("%d %d\n", maxlen[j], empty);
			while (empty >= 0) {
				fprintf(fp, " ");
				empty--;
			}
		}
		fprintf(fp,"\n");
	}

	
	return 0;
}

//void remove(char str[], int i) {
//	for (int j = i; j < strlen(str); j++) {
//		str[j] = str[j + 1];
//	}
//}

void compress(char* str) {
	int s = 0;
	for (int i = 0; i < strlen(str); i++) {
		//������ �ƴϰų� �����ε� ������ ���� ������ �ƴϾ��� ���
		//������ ������ ���Ÿ���
		if (!isspace(str[i]) ||
			i > 0 && !isspace(str[i - 1]))
			str[s++] = str[i];
	}
	if (isspace(str[s]))
		str[s - 1] = '\0';
	else
		str[s] = '\0';
}