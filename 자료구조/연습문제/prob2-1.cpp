//�׽�Ʈ ���
#include <stdio.h>
#include <string.h>
#define MAX 20
#pragma warning (disable:4996)

int main() {
	char str1[MAX], str2[MAX];
	bool pass = false, print = true;
	scanf("%s", str1);
	scanf("%s", str2);

	//��1
	for (int i = 0; i < strlen(str1); i++) {
		pass = false;
		for (int j = 0; j < strlen(str2); j++) {
			if (str1[i] == str2[j]) {
				pass = true;
				break;
			}
		}
		if (!pass) {
			print = false;
		}
	}

	//��2
	for (int i = 0; i < strlen(str2); i++) {
		pass = false;
		for (int j = 0; j < strlen(str1); j++) {
			if (str2[i] == str1[j]) {
				pass = true;
				break;
			}
		}
		if (!pass) {
			print = false;
		}
	}

	if (print)
		printf("yes\n");
	else
		printf("no\n");


	//�ΰ��� ���ڿ� ��

	//for (int i = 0; i < strlen(str1); i++)
	//	printf("%s", str1[i]);
}