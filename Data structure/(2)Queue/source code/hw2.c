#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

/************************************************
	data_variable_for_array
************************************************/
//////////////////////////////////////////////////
typedef struct {
	char name[20];
}customer_info;

typedef struct {
	customer_info* customer[6];
	int front;
	int rear;
	int size;

}queue_array;


////////////////////////////////////////////////

/************************************************
	data_variable_for_linked_list
************************************************/
//////////////////////////////////////////////////

typedef struct customer_node{
	char name[20];
	struct customer_node* next;
}Node;

typedef struct {
	
	Node* front;
	Node* rear;
}queue_linked_list;


queue_linked_list* make_queue_linked_list() {
	queue_linked_list* bank;
	bank = (queue_linked_list*)malloc(sizeof(queue_linked_list));
	bank->front = NULL;
	bank->rear = NULL;
	return bank;
}

int enqueue_linked_list(queue_linked_list* bank) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	printf("Customer : ");
	scanf("%s", new_node->name);
	
	new_node->next = NULL;
	if (bank->front == NULL && bank->rear == NULL) {
		bank->front = new_node;
		bank->rear = new_node;
		return 1;
	}
	else {
		bank->rear->next = new_node;
		bank->rear = new_node;
		return 1;
	}
	

}

int dequeue_linked_list(queue_linked_list* bank) {
	Node* tmp;
	if (bank->front == NULL && bank->rear == NULL) {
		printf("현재 대기열은 비어있습니다. 메뉴로 돌아갑니다.\n");
		return 0;
	}
	if (bank->front != NULL) {
		printf("customer : %s\n", bank->front->name);
		tmp = bank->front;
		bank->front = bank->front->next;
		if (tmp == bank->rear )bank->rear = NULL;
		free(tmp);
		return 1;
	}
	else {
		printf("현재 대기열은 비어있습니다. 메뉴로 돌아갑니다.\n");
		return 0;
	}
}


void show_queue_linked_list(queue_linked_list* bank) {
	Node* tmp;
	tmp = bank->front;
	printf("The current status of Queue : (");
	while (tmp != NULL) {
		printf("%s", tmp->name);
		tmp = tmp->next;
		if (tmp != NULL)printf(", ");
	}
	printf(")\n");
}




//배열형태의 큐를 만들고, 큐의 주소 return
queue_array* make_queue_array() {
	queue_array* bank;
	int i;
	bank = (queue_array*)malloc(sizeof(queue_array));

	bank->front = 0;
	bank->rear = 0;
	bank->size = 6;

	for (i = 0; i < 6; i++) {
		bank->customer[i] = NULL;
	}
	return bank;
}

int enqueue_array(queue_array* bank) {
	customer_info* gogek;
	char customer_name[20];

	if (check_queue_array_full(bank)) {
		gogek = (customer_info*)malloc(sizeof(customer_info));
		printf("Customer : ");
		scanf("%s", gogek->name);
		bank->customer[bank->rear] = gogek;
		++(bank->rear);
		(bank->rear) %= bank->size;
		return 1;
	}
	else {
		printf("대기열이 모두 찼습니다. 초기화면으로 돌아갑니다.\n");
		return 0;
	}
	
}

int dequeue_array(queue_array* bank) {
	if (check_queue_array_empty(bank)) {
		printf("customer : %s\n", bank->customer[bank->front]);
		free(bank->customer[bank->front]);
		++(bank->front);
		bank->front %= bank->size;
		return 1;
	}
	else {
		printf("대기열이 없습니다. 초기화면으로 돌아갑니다.\n");
	}//비어있는 경우
}

void show_queue_array(queue_array* bank) {
	int i = 0;
	printf("The current status of Queue : (");
	if ((bank->front + i) % bank->size == bank->rear) {
		printf(")\n");
		return;
	}
	while(1){
		
		printf("%s", bank->customer[(bank->front + i) % bank->size]);
		i++;
		if ((bank->front + i) % bank->size == bank->rear)break;
		printf(", ");
	}
	printf(")\n");
}

int check_queue_array_full(queue_array* bank) {
	if (bank->rear == 0 && bank->front == 0)return 1;//초기상태

	if ((bank->rear + 1) % bank->size == bank->front) {
		return 0;
	}
	else
		return 1;
}
int check_queue_array_empty(queue_array* bank) {
	if (bank->front == bank->rear)return 0;
	else return 1;
}

int main() {
	queue_array* deagu_bank;
	queue_linked_list* korea_bank;
	int sel;
	int menu;
	printf("숫자를 입력 해주세요.\n1 : 배열로 만든 queue\n2 : 연결 리스트로 만든 queue\n입력 :  ");
	scanf("%d", &sel);
	if (sel == 1) {
		deagu_bank = make_queue_array();

		while (1) {
			printf("\n");
			printf("In (0), out (1), exit (2) : ");
			scanf("%d", &menu);
			switch (menu) {
			case 0:
				if (!enqueue_array(deagu_bank)) {
					show_queue_array(deagu_bank);
					continue;
				}
				else show_queue_array(deagu_bank);
				//printf("%s , front = %d, %d, %d\n", deagu_bank->customer[deagu_bank->front], deagu_bank->front, deagu_bank->rear, deagu_bank->size);

				break;

			case 1:
				if (!dequeue_array(deagu_bank)) {
					show_queue_array(deagu_bank);
					continue;
				}
				show_queue_array(deagu_bank);
				//printf("%s , front = %d, %d, %d\n", deagu_bank->customer[deagu_bank->front], deagu_bank->front, deagu_bank->rear, deagu_bank->size);
				printf("\n");
				break;

			case 2:
				printf("프로그램을 종료합니다.\n");
				exit(1);

			default:
				break;
			};

		}
	}
	
	if (sel == 2) {
		korea_bank = make_queue_linked_list();
		while (1) {

			printf("\n");
			printf("In (0), out (1), exit (2) : ");
			scanf("%d", &menu);
			switch (menu) {
			case 0:
				enqueue_linked_list(korea_bank);
				show_queue_linked_list(korea_bank);
				//printf("%d %d", korea_bank->front, korea_bank->rear);
				break;
			case 1:
				dequeue_linked_list(korea_bank);
				show_queue_linked_list(korea_bank);
				//printf("%d %d", korea_bank->front, korea_bank->rear);
				break;
			case 2:

			default:
				printf("프로그램을 종료합니다.\n");
				exit(1);
				break;
			}
		}
	}
	
	
	
}