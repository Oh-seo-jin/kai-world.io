//�׽�Ʈ ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX 100

typedef struct words {
	char* word;
	int frequency;
	struct words* next;
}Words;

Words* first = NULL;

void load();
Words* create_instance();
void print_words();
void remove_lessthan(int n);
void sort_frequency();

int main() {

	//prob1
	//printf("-------------------prob1--------------------\n");
	load();
	print_words();

	//prob2
	//printf("-------------------prob2--------------------\n");
	remove_lessthan(10);
	print_words();

	//prob3
	//printf("-------------------prob3--------------------\n");
	sort_frequency();
	print_words();
}
void load() {
	char tmp[MAX];
	FILE* fp = fopen("harry.txt", "r");
	while (fscanf(fp, "%s", tmp) != EOF) {
		//printf("tmp: %s\n", tmp);

		if (first == NULL) {
			first = create_instance();
			first->word = strdup(tmp);
			first->frequency++;
			//printf("[%d]%s: %d\n", 0, first->word, first->frequency);
		}
		else {

			if (strcmp(first->word, tmp) > 0) {
				Words* newWord = create_instance();
				newWord->word = strdup(tmp);
				newWord->frequency++;
				newWord->next = first;
				first = newWord;
				//printf("[%d]%s: %d\n", 0, first->word, first->frequency);
			}
			else {
				int i = 0;
				Words* w = first;
				Words* x = NULL;
				while (w != NULL && strcmp(w->word, tmp) < 0) {
					x = w;
					w = w->next;
					i++;
				}

				if (w == NULL) {
					Words* newWord = create_instance();
					newWord->word = strdup(tmp);
					newWord->frequency++;
					x->next = newWord;
					//printf("[%d]%s: %d\n", i, newWord->word, newWord->frequency);
				}

				else {
					if (strcmp(w->word, tmp) > 0) {
						//w ������ ����
						Words* newWord = create_instance();
						newWord->word = strdup(tmp);
						newWord->frequency++;
						newWord->next = w;
						x->next = newWord;
						//printf("[%d]%s: %d\n", i, newWord->word, newWord->frequency);
					}

					else if (strcmp(w->word, tmp) == 0) {
						//w�� frequency++
						w->frequency++;
						//printf("[%d]%s: %d\n", i, w->word, w->frequency);
					}
				}
			}		
		}
	}
	fclose(fp);
}

Words* create_instance() {
	Words* w = (Words*)malloc(sizeof(Words));
	w->word = NULL;
	w->frequency = 0;
	w->next = NULL;
	return w;
}

void print_words() {
	Words* w = first;
	int i = 0;
	while (w != NULL) {
		printf("%s: %d\n", w->word, w->frequency);
		w = w->next;
		i++;
	}
	printf("%d\n\n", i);
}

void remove_lessthan(int n) {
	Words* w = first;
	Words* x = NULL;
	while (w != NULL) {
		if (w->frequency <= n) {
			Words* y = w;
			w = w->next;
			x->next = w;
			free(y);
			continue;
		}
		x = w;
		w = w->next;
	}
}

void sort_frequency() {
	//������ node���� ������ �ٲپ� ����
	
	Words* w = first->next;
	Words* pre_w = first;
	while (w != NULL) {
		//�������� ������ �ƴ� �� Ž��
		if (pre_w->frequency < w->frequency) {

			//���� ��ġ Ž��
			Words* x = first;
			Words* pre_x = NULL;
			while (w->frequency < x->frequency) {
				pre_x = x;
				x = x->next;
			}

			////����
			//if (pre_x == NULL)
			//	printf("%s ���� %s insert\n", x->word, w->word);
			//else printf("%s�� %s ���̿� %s insert\n", pre_x->word, x->word, w->word);

			if (pre_x == NULL) {
				//printf("+++ %s\n", w->word);
				pre_w->next = w->next;
				w->next = x;
				first = w;
			}
			else {
				pre_w->next = w->next;
				if (pre_x != NULL)
					pre_x->next = w;
				w->next = x;
			}
		}
		pre_w = w;
		w = w->next;
	}
}