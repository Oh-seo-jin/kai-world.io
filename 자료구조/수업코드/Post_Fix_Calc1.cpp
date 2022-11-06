#include "stackADT.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#pragma warning (disable:4996)

static char OPERATORS[] = "+-/*";
Stack operand_stack;

int is_operator(char ch);
int eval(char* expr);
int eval_op(char op);
void handle_exception(const char* err_msg);
int read_line(FILE* fp, char str[], int n) {
	int ch, i = 0;

	while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}

int main() {
	char str[100];
	read_line(stdin, str, 100);
	printf("%d",eval(str));
}

int is_operator(char ch) {
	for (int i = 0; i < strlen(OPERATORS); i++) {
		if (OPERATORS[i] == ch)
			return i;
	}
	return -1;
}

int eval(char* expr) {
	operand_stack = create();
	char* token = strtok(expr, " ");
	while (token != NULL) {
		if (token[0] >= '0' && token[0] <= '9') {
			int value = atoi(token);
			push(operand_stack, value);
		}
		else if (is_operator(token[0]) > -1) {
			int result = eval_op(token[0]);
			push(operand_stack, result);
		}
		else {
			handle_exception("Syntax Error: invalid character encountered.\n");
		}
		token = strtok(NULL, " ");
	}
	if (is_empty(operand_stack))
		handle_exception("Syntax Error: Stack empty in eval_op\n");
	int answer = pop(operand_stack);
	if (is_empty(operand_stack))
		return answer;
	else {
		handle_exception("Syntax Error: Stack could be empty.\n");
	}	return -1;
}

int eval_op(char op) {
	if (is_empty(operand_stack))
		handle_exception("Syntax Error: Stack empty in eval_op\n");
	int rhs = pop(operand_stack);
	if (is_empty(operand_stack))
		handle_exception("Syntax Error: Stack empty in eval_op\n");
	int lhs = pop(operand_stack);
	int result = 0;
	switch (op) {
		case '+': result = lhs + rhs; break;
		case '-': result = lhs - rhs; break;
		case '*': result = lhs * rhs; break;
		case '/': result = lhs / rhs; break;
	}
	return result;
}

void handle_exception(const char* err_msg) {
	printf("%s", err_msg);
	exit(1);
}
