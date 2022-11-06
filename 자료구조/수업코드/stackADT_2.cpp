//연결리스트
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
	Item data;
	struct node* next;
};

struct stack_type {
	struct node* top;
};

static void terminate(const char* message) {
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

Stack create() {
	Stack s = (Stack)malloc(sizeof(struct stack_type));
	if (s == NULL)
		terminate("Error in create: stack could not be created.\n");
	s->top = NULL;
	return s;
}

//스택 삭제
void destroy(Stack s) {
	make_empty(s);
	free(s);
}

//스택 비우기
void make_empty(Stack s) {
	while (!is_empty(s))
		pop(s);
}

bool is_empty(Stack s) {
	return s->top == NULL;
}

void push(Stack s, Item i) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node==NULL)
		terminate("Error in push: stack is full.\n");
	new_node->data = i;
	new_node->next = s->top;
	s->top = new_node;
}

Item pop(Stack s) {
	struct node* old_top;
	Item i;

	if (is_empty(s))
		terminate("Error in pop: stack is empty.\n");
	old_top = s->top;
	i = old_top->data;
	s->top = old_top->next;
	free(old_top);
	return i;
}

Item peek(Stack s) {
	if (is_empty(s))
		terminate("Error in peek: stack is empty.\n");
	return s->top->data;
}
