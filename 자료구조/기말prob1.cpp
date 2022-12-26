#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_WORD_LEN 20
#pragma warning (disable: 4996)

struct node {
	char* data;
	struct node* prev, * next;
};
typedef struct node Node;

void ordered_insert(char* item);
void remove_dup();
void print_list_twice();

Node* head = NULL, * tail = NULL;

int main() {
	int n;
	char buf[MAX_WORD_LEN];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		ordered_insert(buf);
	}

	print_list_twice();
	remove_dup();
	print_list_twice();

	return 0;
}

void ordered_insert(char* item) {
	//2중 연결리스트에 문자열 사전식 정렬 삽입
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = strdup(item);
	new_node->next = NULL;
	new_node->prev = NULL;

	Node *p = head;
	while (p != NULL && strcmp(p->data, new_node->data) < 0) {
		p = p->next;
	}
	
	//if (p!=NULL)
		//printf("p: %s\n", p->data);

	if (head == NULL) {
		//첫 노드
		head = new_node;
		tail = new_node;
		//printf("0: insert %s\n", new_node->data);
	}

	else if (p == head) {
		//맨 앞 
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
		//printf("1: insert %s\n", new_node->data);

	}

	else if (p == NULL) {
		//맨 뒤
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
		//printf("2: insert %s\n", new_node->data);

	}

	else {
		new_node->next = p;
		new_node->prev = p->prev;
		p->prev->next = new_node;
		p->prev = new_node;
		//printf("3: insert %s\n", new_node->data);

	}
}

void remove_dup() {
	//중복된 문자열 하나빼고 제거
	Node* p = head;
	while (p != NULL) {
		if (p->prev!=NULL && strcmp(p->prev->data, p->data) == 0) {
			//printf("%s == %s", p->prev->data, p->data);
			Node* tmp = p->prev;
			if (tmp->prev != NULL)
				p->prev = tmp->prev;
			else
				p->prev = NULL;
			tmp->prev->next = p;
			//printf("remove %s\n", tmp->data);
			free(tmp);
		}
		p = p->next;
	}
}

void print_list_twice() {
	Node* p = head;
	while (p != NULL) {
		printf("%s ", p->data);
		p = p->next;
	}
	printf("\n");

	Node* q = tail;
	while (q != NULL) {
		printf("%s ", q->data);
		q = q->prev;
	}
	printf("\n");
}