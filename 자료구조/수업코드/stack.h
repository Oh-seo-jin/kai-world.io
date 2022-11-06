#ifndef STACK_H
#define STACK_H
#include <stdio.h>

void push(char ch);
char* pop();
char* peek();
int is_empty();
int is_full();

#endif