#include "stackADT.h"
#include <stdio.h>

int main() {
	Stack s1 = create();
	Stack s2 = create();

	push(s1, 12);
	push(s2, 9);
	push(s1, 11);
	printf("%d\n",pop(s1));
	printf("%d\n",peek(s2));
}