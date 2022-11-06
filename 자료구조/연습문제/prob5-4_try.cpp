#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#pragma warning (disable:4996)

struct node {
	char* data;
	struct node* next;
};
typedef struct node Node;
Node* head = NULL;
int size;

void load();
void show();
void remove_first();
void remove();
void slice();


int main() {

	printf("===============1차==============\n");
	load();
	remove();
	show();

	printf("\n===============slice==============\n");
	slice();
	printf("===============remove==============\n");
	//공백으로 자르기
	remove();
	printf("===============finish==============\n");
	show();

	return 0;
}

void load() {
	// ">"을 기준으로 strtok 하여 저장
	char delim[] = ">";
	char line[MAX];
	int count, i = 1;
	Node* p = head;

	FILE* fp = fopen("sample.html", "r");
	while (fgets(line, MAX, fp) != NULL) {
		//printf("%s", line);

		count = 0;
		for (int i = 0; i < strlen(line); i++) {
			if (line[i] == '>')
				count++;
		}

		if (count == 0) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			p->next = newNode;
			newNode->data = strdup(line);
			newNode->next = NULL;
			printf("[i]%s\n", newNode->data);
			i++;
			continue;
		}

		if (head == NULL) {
			head = (Node*)malloc(sizeof(Node));
			head->data = strdup(strtok(line, delim));
			head->next = NULL;
			printf("[0]%s\n", head->data);
			p = head;
		}
		else {
			//해당 line의 strtok 처음
			Node* firstNode = (Node*)malloc(sizeof(Node));
			p->next = firstNode;
			firstNode->data = strdup(strtok(line, delim));
			firstNode->next = NULL;
			printf("[%d]%s\n", i, firstNode->data);
			p = p->next;
			i++;
		}

		for (int j = 0; j < count && p->next == NULL; j++) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			p->next = newNode;
			newNode->data = strdup(strtok(NULL, delim));
			if (newNode->data == NULL) {
				p->next = NULL;
				break;
			}
			newNode->next = NULL;
			printf("[%d]%s\n", i, newNode->data);
			p = p->next;
			i++;
		}
		//printf("---next line---\n");
	}
	fclose(fp);
}

void slice() {
	//공백으로 자르기
	char delim[] = " ";
	Node* p = head;
	char *tmp;
	int count = 0;

	while (p != NULL) {
		for (int i = 0; i < strlen(p->data); i++) {
			if (p->data[i] == ' ')
				count++;
		}
		
		if (count > 0) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			tmp = strdup(strtok(p->data, delim));
			printf("%s\n", tmp);
			Node* q = p;

			while (count>0) {
				Node* newNode = (Node*)malloc(sizeof(Node));
				newNode->data = strdup(strtok(NULL, delim));
				printf("%s\n", newNode->data);
				newNode->next = q->next;
				q->next = newNode;
				count--;
			}
			p->data = strdup(strtok(p->data, delim));
		}
		p = p->next;
	}

}

void remove_first() {
	if (head == NULL)
		return;
	else {
		head = head->next;
		printf("=>%s\n", head->data);
	}
}

void remove() {
	//"<"으로 시작하는 node 삭제
	Node* prev = head;
	Node* tmp = head->next;
	while (head->data[0] == '<') {
		remove_first();
	}
	while (prev != NULL && tmp->data!=NULL) {
		if (tmp->data[0] == '<') {
			prev->next = tmp->next;
			printf("=>%s\n", tmp->data);
		}
		tmp = tmp->next;
		prev = prev->next;
	}
}

//void add(char item[]) {
//
//	if (p->next == NULL) {
//		Node* newNode = (Node*)malloc(sizeof(Node));
//		p->next = newNode;
//		newNode->data = strdup(item);
//		newNode->next = NULL;
//	}
//
//
//	while (p != NULL) {
//		for (int i = 1; i < strlen(p->data); i++) {
//			if (p->data[i] == '>') {
//				tok = true;
//			}
//		}
//		if (tok) {
//			rhead = (Node*)malloc(sizeof(Node));
//			rhead->data = strdup(strtok(p->data, delim));
//			printf("%s\n", rhead->data);
//			rhead->next = NULL;
//
//			q = rhead;
//
//			for (int i = 1; i < strlen(p->data); i++) {
//				Node* newNode = (Node*)malloc(sizeof(Node));
//				q->next = newNode;
//				newNode->data = strtok(NULL, delim);
//				newNode->next = NULL;
//				//printf("%s\n", newNode->data);
//				q = q->next;
//			}
//		}
//		else {
//			q = rhead;
//
//			while (q != NULL) {
//				q = q->next;
//			}
//			Node* newNode = (Node*)malloc(sizeof(Node));
//			q->next = newNode;
//			newNode->data = p->data;
//			newNode->next = NULL;
//		}
//		p = p->next;
//	}
//}

void show() {
	Node* p = head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->next;
	}

	//int i = 0;
	//Node* q = rhead;
	//while (q != NULL) {
	//	printf("[%d]%s\n",i, q->data);
	//	q = q->next;
	//	i++;
	//}

}