#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "string_tools.h"
#pragma warning (disable:4996)
#define BUFFER_SIZE 100


int main() {
	handle_command();
	
}

void handle_command() {
	char buffer[BUFFER_SIZE];
	char* command, *name, *str;

	while (1) {
		printf("$ ");
		if (read_line(stdin, buffer, BUFFER_SIZE)<0)
			return;
		command = strtok(buffer, " ");
		if (strcmp(command, "create") == 0) {
			name = strtok(NULL, " ");
			handle_create(name);
		}
		else if (strcmp(command, "push") == 0) {
			name = strtok(NULL, " ");
			str = strtok(NULL, " ");
			handle_push(name, str);
		}
		else if (strcmp(command, "list") == 0) {
			handle_list();
		}
		else if (strcmp(command, "pop") == 0) {
			name = strtok(NULL, " ");
			handle_pop(name);
		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
	}
}

void handle_create(char* name) {

}

void handle_push(char* name, char* str) {

}

void handle_list() {

}

void handle_pop(char* name) {

}