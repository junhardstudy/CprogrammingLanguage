#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	char char_data[1];
	int int_data;
}data;

typedef struct {
	data* element_data;
	int top;// equal size of stack(top + 1)
	int max_size_of_stack;

}stack_array;

typedef struct linked_data_inner {
	char* string_op;
	struct linked_data_inner* next;
	char char_data[1];
	int int_data;
}linked_data;

typedef struct {
	linked_data* top;
	int cur_size_of_stack;
}stack_linked;


data* pop(stack_array* t1);
data* retrieve(stack_array* t1);
int check_empty(stack_array* t1);
int full_check(stack_array* t1);
void push(stack_array* t1, char sel, int input_data);
void clear_stack(stack_array* t1);
linked_data* Top(stack_linked* t1);
linked_data pop_linked(stack_linked* t1);
void push_linked(stack_linked* t1, int );
void print_all_data(stack_linked* t1);
void convert_to_binary(int decimal);
void push_string_linked(stack_linked* t1, char* input_data);



int main()
{
	char test_Data[2]={'+','\0'};
	char equation[500];
	char for_operator[500];
	char tmp_op[500];
	char* tmp_digit = NULL;
	char* tmp_op2 = NULL;
	char* array_digit[300];
	char array_operator[200] = { NULL };
	char* ptr_array_op[200];
	char* infix[500];
	char* postfix[500] = { NULL };
	char concat_char[500];
	int menu;
	int i, j, k;
	int input_tmp;
	int op1, op2;
	stack_linked* t2;
	linked_data tmp_linked;
	data* tmp;
	data* test1;
	stack_array *t1;
	
	stack_linked* postfix_stack = (stack_linked*)malloc(sizeof(stack_linked));
	stack_linked* stack_operatror = (stack_linked*)malloc(sizeof(stack_linked));
	stack_linked* stack_calcul = (stack_linked*)malloc(sizeof(stack_linked));
	linked_data* access_stack_data;
	linked_data real_data;
	postfix_stack->cur_size_of_stack = 0;
	stack_operatror->cur_size_of_stack = 0;
	/*********************

	마지막에 free, 메모리 정리 필요

	*********************/
	

	printf("바꿀 10진수? : ");
	scanf("%d", &input_tmp);
	convert_to_binary(input_tmp);
	getchar();

	printf("수식 : ");
	//gets(equation);
	//scanf 에서 space는 입력 못받음
	//scanf에서 받고 싶으면 scanf("%[^\n]", equation); 형태로
	scanf("%[^\n]", equation);
	strcpy(for_operator, equation);
	i = 0;
	j = 0;
	k = 0;
	while (equation[i] != NULL) {
		switch (equation[i++]) {
		case '(':
			array_operator[j] = '(';
			tmp_op[k++] = array_operator[j++];
			tmp_op[k++] = ' ';

			break;
		case ')':
			array_operator[j] = ')';
			tmp_op[k++] = array_operator[j++];
			tmp_op[k++] = ' ';
			break;
		case '+':
			array_operator[j] = '+';
			tmp_op[k++] = array_operator[j++];
			tmp_op[k++] = ' ';
			break;
		case '-':
			array_operator[j] = '-';
			tmp_op[k++] = array_operator[j++];
			tmp_op[k++] = ' ';
			break;
		case '*':
			array_operator[j] = '*';
			tmp_op[k++] = array_operator[j++];
			tmp_op[k++] = ' ';
			break;
		case '/':
			array_operator[j] = '/';
			tmp_op[k++] = array_operator[j++];
			tmp_op[k++] = ' ';
			break;
		case '%':
			array_operator[j] = '%';
			tmp_op[k++] = array_operator[j++];
			tmp_op[k++] = ' ';
			break;

		}		
	}
	tmp_op[k] = NULL;
	
	array_digit[0] = strtok(equation, " *+-/%()");
	i = 0;
	while (array_digit[i] != NULL) {
		array_digit[++i] = strtok(NULL, " *+-/%()");
	}
	
	
	ptr_array_op[0] = strtok(tmp_op, " ");
	i = 0;
	while (array_operator[i] != NULL) {
		ptr_array_op[++i] = strtok(NULL, " ");
	}
	
	printf("\n\n");
	i = 0;
	while (array_operator[i] != NULL) {
		printf("%c ", array_operator[i++]);
	}
	
	printf("\n");
	i = 0;
	while (array_digit[i] != NULL) {
		printf("%s ", array_digit[i++]);
	}
	i = 0;
	printf("\nptr = ");
	i = 0;
	while (ptr_array_op[i] != NULL) {
		printf("%s ", ptr_array_op[i++]);
	}
	i = 0;
	
	//(23+ 56)/2 + 21 *2 +16 -13
	//infix로 만들기
	i = 0;
	j = 0;
	k = 0;
	
	while (ptr_array_op[i] != NULL) {
		if (!strcmp("(", ptr_array_op[i])) {
			infix[k++] = ptr_array_op[i++];
			
		}
		else if (!strcmp("+", ptr_array_op[i]) && j != 0) {
			
			infix[k++] = ptr_array_op[i++];
		}
		else if (!strcmp("-", ptr_array_op[i]) && j != 0) {
			infix[k++] = ptr_array_op[i++];
		}
		else if (!strcmp("/", ptr_array_op[i]) && j != 0) {
			infix[k++] = ptr_array_op[i++];
		}
		else if (!strcmp("%", ptr_array_op[i]) && j != 0) {
			infix[k++] = ptr_array_op[i++];
		}
		else if (!strcmp("*", ptr_array_op[i]) && j != 0) {
			infix[k++] = ptr_array_op[i++];
		}
		else {//닫힌 괄호 나왔을때
			if (j != 0) {
				infix[k++] = ptr_array_op[i++];
				continue;
			}
		}
		
		infix[k++] = array_digit[j++];
	}
	infix[k] = ptr_array_op[i];
	printf("\ninfix notation : ");
	i = 0;
	while (infix[i] != NULL)
	{
		printf("%s", infix[i++]);
	}
	printf("\n\n\n");
	i = 0;
	j = 0;
	while (infix[i] != NULL) {
		
		if (!strcmp(infix[i], "(")) {
			push_string_linked(stack_operatror, infix[i]);
			i++;


		}else if (!strcmp(infix[i], "+") || !strcmp(infix[i], "-")) {
			access_stack_data = Top(stack_operatror);

		
			while (1) {
				access_stack_data = Top(stack_operatror);
				if (access_stack_data == NULL || !strcmp(access_stack_data->string_op, "(")) {
					break;
				}
				
				if (!strcmp(access_stack_data->string_op, "*") || !strcmp(access_stack_data->string_op, "/") || !strcmp(access_stack_data->string_op, "+") || !strcmp(access_stack_data->string_op, "-")) {
					real_data = pop_linked(stack_operatror);
			
					postfix[j++] = real_data.string_op;
					
				}
				
			}
			

				push_string_linked(stack_operatror, infix[i++]);
				postfix[j++] = infix[i++];
			

		}else if (!strcmp(infix[i], "*") || !strcmp(infix[i], "/")) {
			access_stack_data = Top(stack_operatror);
			if (access_stack_data == NULL) {
				push_string_linked(stack_operatror, infix[i++]);
				continue;
			}
			if (!strcmp(access_stack_data->string_op, "*") || !strcmp(access_stack_data->string_op, "/")) {
				real_data = pop_linked(stack_operatror);
				push_string_linked(stack_operatror, infix[i]);
				i++;
				postfix[j++] = real_data.string_op;
				postfix[j++] = infix[i];//operator 다음에는 무조건 operand가 옴
				i++;
			}
			else {
				push_string_linked(stack_operatror, infix[i]);
				i++;
			}
			

		}else  if(!strcmp(")", infix[i])){//닫힌 괄호가 오는 경우
			i++;
			while (1) {
				
				real_data = pop_linked(stack_operatror);
				printf("%s \n", real_data.string_op);
				if (!strcmp(real_data.string_op, "(")) {
					printf("op = %s\n", real_data.string_op);
					break;
				}
				postfix[j++] = real_data.string_op;
				
			}
			

		}
		else {//숫자일 경우	
			postfix[j++] = infix[i];
			i++;
			
		}
		
	}
	access_stack_data = Top(stack_operatror);
	while (access_stack_data != NULL) {
		real_data = pop_linked(stack_operatror);
		postfix[j++] = real_data.string_op;
		access_stack_data = Top(stack_operatror);

	}
	printf("success?\n");
	i = 0;
	printf("postfix notation = ");
	while (postfix[i] !=NULL)printf("%s ", postfix[i++]);
	printf("\n\n");

	i = 0;
	while (1) {
		if (postfix[i] == NULL) break;

		if (!strcmp(postfix[i], "+") || !strcmp(postfix[i], "-") || !strcmp(postfix[i], "/") || !strcmp(postfix[i], "*") || !strcmp(postfix[i], "%")) {
			real_data = pop_linked(stack_calcul);
			op2 = atoi(real_data.string_op);
			real_data = pop_linked(stack_calcul);
			op1 = atoi(real_data.string_op);

			if (!strcmp(postfix[i], "+"))op1 = op1 + op2;
			if (!strcmp(postfix[i], "-"))op1 = op1 - op2;
			if (!strcmp(postfix[i], "/")) op1 = op1 / op2;
			if (!strcmp(postfix[i], "*")) op1 = op1 * op2;
			i++;

			push_linked(stack_calcul, op1);
			continue;
		}
		else {
			op1 = atoi(postfix[i++]);
			push_linked(stack_calcul, op1);
		}
	}
	printf("계산 결과 = %d\n", op1);
	
		
		
		
	}










/**************************************
	operation for array
**************************************/
data* retrieve(stack_array* t1) {
	int check;
	check = check_empty(t1);
	if (check == 1)
		return (t1->element_data) + t1->top;
	else {
		printf("there is no data for retireve at stack!\n");
		exit(-1);
	}
}

data* pop(stack_array *t1) {
	int check;

	check = check_empty(t1);
	if (check == 1)
		return (t1->element_data) + t1->top--;
	else {
		printf("there is no data for pop at stack!\n");
		exit(-1);
	}

}

void push(stack_array* t1, char sel, int input_data) {
	int check;
	check = full_check(t1);
	if (check == 0) {
		if (sel == 'c') {//character
			++(t1->top);
			(t1->element_data + t1->top)->char_data[0] = (char)input_data;
		}
		else if (sel == 'd') {//digit
			++(t1->top);
			(t1->element_data + t1->top)->int_data = (int)input_data;
		}
		else {
			printf("wrong selection!\n");
			exit(-1);
		}
	}
	else {
		printf("there is no space for pushing data into stack!\n");
		exit(-1);
	}

}

int check_empty(stack_array* t1) {
	if (t1->top != -1)return 1;
	else return 0;
}

int full_check(stack_array* t1) {
	if (t1->max_size_of_stack - 1 == t1->top)return 1;//full
	else return 0;//still seat
}

void clear_stack(stack_array* t1) {
	t1->element_data = NULL;
	t1->top = -1;
}

/**************************************
	operation for linked list
**************************************/

linked_data pop_linked(stack_linked *t1) {
	linked_data tmp;
	linked_data* prev_node;
	if (t1->top != NULL) {//exist data for retrieve at linked list
		tmp = *(t1->top);
		prev_node = t1->top;
		(t1->top) = t1->top->next;
		free(prev_node);//delete node when data was pop from stack
		t1->cur_size_of_stack--;
		return tmp;
	}
	else {
		printf("there is no data from stack!\n");
		printf("program will be terminated!\n");
		exit(-1);
	}
}

linked_data* Top(stack_linked* t1) {
	if (t1->top != NULL) {//exist data for retrieve at linked list
		return t1->top;
	}
	else {
		return NULL;
	}
}
void print_all_data(stack_linked* t1) {
	linked_data *tmp;
	tmp = t1->top;

	while(tmp != NULL){
		
		
		printf("%d", tmp->int_data);
		tmp = tmp->next;
	
	}
}

void push_linked(stack_linked* t1, int input_data) {
	linked_data* input;
	input = (linked_data*)malloc(sizeof(linked_data));
	
	input->int_data = input_data;
	
	if (t1->cur_size_of_stack == 0){
		
		input->next = NULL;
		
		t1->top = input;
		


	}
	else {
		
		input->next = t1->top;
		t1->top = input;
	}
	++(t1->cur_size_of_stack);
	
}

void push_string_linked(stack_linked* t1, char* input_data) {
	linked_data* input = (linked_data*)malloc(sizeof(linked_data));
	printf("인자 : %s\n", input_data);
	input->string_op = input_data;
	if (t1->cur_size_of_stack == 0) {

		input->next = NULL;

		t1->top = input;



	}
	else {

		input->next = t1->top;
		t1->top = input;
	}
	++(t1->cur_size_of_stack);

}
/**********************************
	function to solve the problem
**********************************/

void convert_to_binary(int decimal) {
	int tmp = decimal;
	stack_linked *t1;
	t1 = (stack_linked*)malloc(sizeof(stack_linked));
	t1->cur_size_of_stack = 0;
	t1->top = NULL;
	//char bin[30];//2E30 까지만 표현
	push_linked(t1, decimal % 2);
	decimal /= 2;
	while(decimal / 2 != 0)
	{

		push_linked(t1,	decimal % 2);
		decimal /= 2;
		
	}
	push_linked(t1, decimal % 2);
	printf("\n*******************************\n");
	printf("%d(base 10) -> ", tmp);
	print_all_data(t1);
	printf("(base 2)\n");
	printf("*******************************\n");

}
