#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef int Item;
/* 코드의 재사용 : data의 type을 바꾸어 사용할 수 있도록 */

typedef struct stack_type* Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
//bool is_full(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);
//void reallocate(Stack s);

#endif