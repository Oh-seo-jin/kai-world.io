#include "stack.h"
#define MAX_CAPACITY 100

char stack[MAX_CAPACITY];
int top = -1;

int is_empty() {
	return top == -1;
}

int is_full() {
	return top == MAX_CAPACITY - 1;
}

void push(char ch) {
	if (is_full()) {
		printf("stack is full.\n");
		return;
	}
	top++;
	stack[top] = ch;
}

char pop() {
	if (is_empty()) {
		printf("stack is empty.\n");
		return -1;
	}
	char tmp = stack[top];
	top--;
	return tmp;
}

char peek() {
	return stack[top];
}

