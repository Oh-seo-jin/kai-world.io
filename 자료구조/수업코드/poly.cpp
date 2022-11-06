#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define MAX_POLYS 100
#define BUFFER_LENGTH 30

struct term {
	int coef;
	int expo;
	struct term* next;
};
typedef struct term Term;

typedef struct polynomial {
	char name;
	Term* first;	//ù��° ���� �ּ�
	int size = 0;
}Polynomial;

Polynomial* polys[MAX_POLYS];	//������ �迭
int n = 0;						//���׽� ����

//������Ÿ��
Term* create_term_instance();
Polynomial* create_polynomial_instance(char name);
void add_term(int c, int e, Polynomial* poly);
int eval(Polynomial* poly, int x);
int eval(Term* term, int x);
void print_poly(Polynomial* p);
void print_term(Term* term);
void process_command();
int read_line(FILE* fp, char str[], int n) {
	int ch, i = 0;

	while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i;
}
void handle_print(char name);
void handle_calc(char name, int x);
void erase_blanks(char* expression);
void handle_definition(char* expression);
Polynomial* create_by_parse_polynomial(char name, char* body);
int parse_and_add_term(char* expr, int begin, int end, Polynomial* p_poly);
void insert_polynomial(Polynomial* ptr_poly);
void destroy_polynomial(Polynomial* ptr_poly);
Polynomial* create_by_add_two_polynomials(char name, char f, char g);


int main() {
	process_command();
}

Term* create_term_instance() {
	Term* t = (Term*)malloc(sizeof(Term));
	t->coef = 0;
	t->expo = 0;
	t->next = NULL;
	return t;
}

Polynomial* create_polynomial_instance(char name) {
	Polynomial* ptr_poly = (Polynomial*)malloc(sizeof(Polynomial));
	ptr_poly->name = name;
	ptr_poly->size = 0;
	ptr_poly->first = NULL;
	return ptr_poly;
}

void add_term(int c, int e, Polynomial* poly) {
	if (c == 0)
		return;
	Term* p = poly->first, * q = NULL;

	//1: ������ Ŭ ��� ����
	while (p != NULL && p->expo > e) {
		q = p;
		p = p->next;
	}

	//2: ������ ���� ��� ��� ����
	if (p != NULL && p->expo == e) {
		p->coef += c;
		if (p->coef == 0) {			//���ߴ��� 0�� �Ǵ� ���
			if (q == NULL) {		//p�� first node�� ���
				poly->first = p->next;
			}
			else {
				q->next = p->next;
			}
			poly->size--;
			free(p);
		}
		return;
	}

	//case1
	Term* term = create_term_instance();
	term->coef = c;
	term->expo = e;

	//�� �տ� ����
	if (q == NULL) {
		term->next = poly->first;
		poly->first = term;
	}

	//���̿� ����
	else {
		term->next = p;
		q->next = term;
	}
	poly->size++;
}

int eval(Polynomial* poly, int x) {
	int result = 0;
	Term* t = poly->first;
	while (t != NULL) {
		result += eval(t, x);
		t = t->next;
	}
	return result;
}

int eval(Term* term, int x) {
	int result = term->coef;
	for (int i = 0; i < term->expo; i++) {
		result *= x;
	}
	return result;
}

void print_poly(Polynomial* p) {
	printf("%c=", p->name);
	Term* t = p->first;
	while (t != NULL) {
		print_term(t);
		//����� -�̰ų� ���� ���
		if (t->next != NULL || t->coef >= 0)
			printf("+");
		t = t->next;
	}
}

void print_term(Term* term) {

	//����� 1�� ���
	if (term->coef == 1)
		printf("");
	else
		printf("%d", term->coef);

	//������ 1�� ���
	//����� ���
	if (term->expo == 1)
		printf("x");
	else if (term->expo == 0)
		printf("");
	else
		printf("x^%d", term->expo);
}

void process_command() {
	char command_line[BUFFER_LENGTH];
	char copied[BUFFER_LENGTH];
	char* command, * arg1, * arg2;

	while (1) {
		printf("$ ");
		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0)
			continue;	//���̰� 0�̸� ����
		strcpy(copied, command_line);
		command = strtok(command_line, " ");
		if (strcmp(command, "print") == 0) {	//print f
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_print(arg1[0]);
		}

		else if (strcmp(command, "calc") == 0) {
			arg1 = strtok(NULL, " ");
			if (arg1 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			arg2 = strtok(NULL, " ");
			if (arg2 == NULL) {
				printf("Invalid arguments.\n");
				continue;
			}
			handle_calc(arg1[0], int(arg2));

		}
		else if (strcmp(command, "exit") == 0) {
			break;
		}
		else {
			handle_definition(copied);
		}

	}
}

void handle_print(char name) {
	for (int i= 0; i < n; i++){
		if (polys[i]->name == name) {
			print_poly(polys[i]);
			return;
		}
	}
	printf("%c is not polys", name);
}

void handle_calc(char name, int x) {
	for (int i = 0; i < n; i++){
		if (polys[i]->name == name) {
			printf("%d", eval(polys[i], x));
			return;
		}
	}
	printf("%c is not polys", name);
}

void handle_definition(char *expression) {

	erase_blanks(expression);

	char* f_name = strtok(expression, "=");
	if (f_name == NULL || strlen(f_name) != 1) {
		printf("Unsupported command.\n");
		return;
	}

	char* exp_body = strtok(NULL, "=");
	if (exp_body == NULL || strlen(exp_body) <=0) {
		printf("Invalid expression format.\n");
		return;
	}

	//body : �Լ������� ���
	//x�� ������ ���ĺ����� ����
	if (exp_body[0] >= 'a' && exp_body[0] <= 'z' && exp_body[0] != 'x') {
		char* former = strtok(exp_body, "+");
		if (former == NULL || strlen(former) != 1) {
			printf("Invalid expression format.");
			return;
		}
		char* later = strtok(NULL, "+");
		if (later == NULL || strlen(later) != 1) {
			printf("Invalid expression format.");
			return;
		}

		Polynomial* pol = create_by_add_two_polynomials(f_name[0], former[0], later[0]);
		
		if (pol == NULL) {
			printf("Invalid expression format.");
			return;
		}
		insert_polynomial(pol);
	}

	//body : �׿��� ���, ���ο� ���׽� ����
	else {
		Polynomial* pol = create_by_parse_polynomial(f_name[0], exp_body);
		if (pol == NULL) {
			printf("Invalid expression format.");
			return;
		}
		insert_polynomial(pol);
	}
}

void erase_blanks(char* expression) {
	int i, len = strlen(expression);
	for (i = 0; i < len; i++) {
		if (expression[i] == ' ') {
			int j = i;
			while (j < len-1){
				expression[j++] = expression[j+1];
			}
			expression[len-1] = '\0';
			len--;
		}
	}
}

Polynomial* create_by_parse_polynomial(char name, char* body) {
	//f = 12x^3 -x^2 +13

	//���ο� �Լ� ����
	Polynomial* ptr_poly = create_polynomial_instance(name);

	int i = 0, begin_term = 0;
	while (i < strlen(body)) {
		//ù�� ���� ��ȣ ~ ��ȣ
		if (body[i] == '+' || body[i] == '-')
			i++;
		while (i < strlen(body) && body[i] != '+' && body[i] != '-')
			i++;

		//���ο� �� ����
		int result = parse_and_add_term(body, begin_term, i, ptr_poly);

		if (result == 0) {
			destroy_polynomial(ptr_poly);
			return NULL;
		}
		begin_term = i;
	}
	return ptr_poly;
}

int parse_and_add_term(char* expr, int begin, int end, Polynomial* p_poly) {
	int i = begin;
	int sign_coef = 1, coef = 0, expo;

	//��ȣ
	if (expr[i] == '+')
		i++;
	else if (expr[i] == '-') {
		sign_coef = -1;
		i++;
	}

	//���
	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		coef = coef * 10 + (int)(expr[i] - '0');
		i++;
	}
	if (coef == 0)
		coef = sign_coef;
	else
		coef *= sign_coef;
	if (i >= end) {		//���
		add_term(coef, 0, p_poly);
		return 1;
	}

	//����
	if (expr[i] != 'x')
		return 0;
	i++;
	if (i >= end) {		//1����
		add_term(coef, 1, p_poly);
		return 1;
	}

	//����
	if (expr[i] != '^')
		return 0;
	i++;
	expo = 0;
	while (i < end && expr[i] >= '0' && expr[i] <= '9') {
		expo = expo * 10 + (int)(expr[i] - '0');
		i++;
	}
	add_term(coef, expo, p_poly);
	return 1;

}

void insert_polynomial(Polynomial* ptr_poly) {
	for (int i = 0; i < n; i++) {
		//�ߺ� �˻�
		if (polys[i]->name == ptr_poly->name) {
			destroy_polynomial(polys[i]);
			polys[i] = ptr_poly;	//�������׽� free
			return;
		}
	}

	//�ߺ����� ����
	polys[n++] = ptr_poly;
}

void destroy_polynomial(Polynomial* ptr_poly) {
	if (ptr_poly == NULL)
		return;

	//�׺��� free
	Term* t = ptr_poly->first, * tmp;
	while (t != NULL) {
		tmp = t;
		t = t->next;
		free(tmp);
	}

	free(ptr_poly);
}

Polynomial* create_by_add_two_polynomials(char name, char f, char g) {

	Polynomial* f_poly = NULL, *g_poly = NULL;
	for (int i = 0; i < n; i++) {
		if (polys[i]->name == f) {
			f_poly = polys[i];
		}
		if (polys[i]->name == g) {
			g_poly = polys[i];
		}
	}

	//���ο� ���׽� ����
	//new = f -> new + g
	Polynomial* new_poly = create_polynomial_instance(name);
	polys[n++] = new_poly;
	
	//���׽� f ����
	Term* f_ptr = f_poly->first, *new_ptr = new_poly->first;
	while (f_ptr != NULL) {
		Term* new_term = create_term_instance();
		new_term->coef = f_ptr->coef;
		new_term->expo = f_ptr->expo;

		if (new_poly->first == NULL)
			new_poly->first = new_term;
		else
			new_ptr->next = new_term;

		f_ptr = f_ptr->next;
		new_ptr = new_ptr->next;
	}
	
	//g ���ϱ�
	Term* g_ptr = g_poly->first;
	while (g_ptr != NULL) {
		add_term(g_ptr->coef, g_ptr->expo, new_poly);
		g_ptr = g_ptr->next;
	}

	return new_poly;
}