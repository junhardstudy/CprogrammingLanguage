#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct {
	int num;
}data;

typedef struct {
	data* elements;
}list_array;

typedef struct in_node {
	int num;
	struct in_link* next;
}Node;

typedef struct {
	Node* link_head;
}head;

Node* search(head*, int, int);
void insert_Node(head* list_head);
void list_show(head* list_head);
void insert_Node(head* list_head);
void insert_array(Node* a[]);
Node* search(head* list_head, int target_num, int mode);
void check_insertion(Node* input, head* list_head);
void check_array(Node a[], Node* input);
void list_array_show(Node* a[]);
void insert_array(Node* a[]);

void out_array(Node* a[], int target) {
	int i = 0, j;
	while (a[i] != NULL) {
		if (a[i]->num == target) {
			for (j = i; a[j] != NULL; j++) {
				a[j] = a[j + 1];
			}
			return;
		}
		else {
			i++;
		}
	}
	printf("My List dose not have %d.\n", target);
}

void search_array(Node* a[], int target) {
	int i = 0;
	while (a[i] != NULL) {
		if (a[i]->num == target) {
			printf("My List has %d.\n", target);
			return;
		}
		else
		{
			i++;
		}
	}
	printf("My List dose not have %d.\n", target);
}

void list_array_show(Node* a[]) {
	int i = 0;
	printf("The current status of List : ");
	while (a[i] != NULL) {
		printf("%d", *a[i++]);
		if (a[i] != NULL)printf(", ");

	}
	printf("\n\n");
}

void insert_array(Node* a[]) {
	Node* tmp;
	printf("in : ");
	tmp = (Node*)malloc(sizeof(Node));
	scanf("%d", &(tmp->num));
	printf("\n");
	tmp->next = NULL;
	check_array(a, tmp);
}

void check_array(Node* a[], Node* input) {
	int i = 0, j;
	int tmp_index;
	Node* tmp;
	Node* s_n;//for swap
	Node* t_n;//for temporarily
	if (a[0] == NULL) {
		a[0] = input;
		return;
	}
	while (a[i] != NULL) {
		
		if (a[i]->num > input->num) {
			tmp_index = i;
			s_n = a[i];
			for (j = i; a[j] != NULL; j++) {
				t_n = a[j + 1];
				a[j + 1] = s_n;
				s_n = t_n;

			}
			a[tmp_index] = input;
			return;
		}
		else i++;
	}
	a[i] = input;
}


void insert_Node(head* list_head) {
	Node* tmp;
	printf("in : ");
	tmp = (Node*)malloc(sizeof(Node));
	scanf("%d", &(tmp->num));
	printf("\n");
	tmp->next = NULL;
	check_insertion(tmp, list_head);
}

Node* search(head* list_head, int target_num, int mode) {//when mode is zero, only perform search,
													   // otherwise perform search and deletion(out)
	Node* access;
	Node* preNode;
	Node* tmp;
	access = list_head->link_head;
	preNode = access;
	while (access != NULL) {
		if (access->num == target_num) {
			if (mode != 0) {//when deletion perform at head
				if (access == list_head->link_head) {
					tmp = list_head->link_head->next;
					free(access);
					list_head->link_head = tmp;
					return tmp;
				}//when deletion perform all exclude head position.
				else {
					preNode->next = access->next;
					free(access);
					return list_head->link_head;
				}
			}
			else
				return access;//if found the data, it'll be return address of where is data stored.
		}
		else {
			preNode = access;
			access = access->next;
		}
	}
	return NULL;//it can't be found.
}

void list_show(head* list_head) {
	Node* access;
	int i;
	access = list_head->link_head;
	printf("The current status of List : ");
	for (i = 0; access != NULL; i++) {
		printf("%d", access->num);
		if (access->next != NULL)printf(", ");
		access = access->next;

	}
	printf("\n\n");
}

void check_insertion(Node* input, head* list_head) {
	int i, j, k;
	Node* preNode;
	Node* access;

	access = list_head->link_head;

	if (list_head->link_head == NULL) {
		list_head->link_head = input;
		return;
	}

	if (input->num < access->num) {
		input->next = list_head->link_head;
		list_head->link_head = input;
		return;
	}//first
	else {
		while (access->next != NULL) {
			preNode = access;
			access = access->next;
			if (input->num < access->num) {
				input->next = preNode->next;
				preNode->next = input;
				return;
			}
		}//middle
		access->next = input;
		return;//last
	}

}



void main() {
	head* a_list = (head*)malloc(sizeof(head));
	Node* access = NULL;
	Node* tmp;
	int i, j, menu, target_num, sel;
	Node* list_array[100] = { NULL };

	a_list->link_head = NULL;

	srand((unsigned)time(NULL));

	printf("1. 배열로 구현한 list.\n2. linked list로 구현한 list\n1, 2 입력 : ");
	scanf("%d", &sel);
	switch (sel) {
	case 1:
		while (1) {
			printf("In (0), Search (1), Out (2), Exit (3) : ");
			scanf("%d", &menu);
			printf("\n");
			switch (menu) {
			case 0:
				 insert_array(list_array);
			     list_array_show(list_array);
				break;
			case 1:
				printf("Search : ");
				scanf("%d", &target_num);
				search_array(list_array, target_num);
				printf("\n");
				list_array_show(list_array);
				break;
			case 2:
				printf("Out : ");
				scanf("%d", &target_num);
				out_array(list_array, target_num);
				list_array_show(list_array);
				break;
			case 3:exit(1);
				break;
			default:
				break;

			};
		}
		break;








	case 2:
		while (1) {
			printf("In (0), Search (1), Out (2), Exit (3) : ");
			scanf("%d", &menu);
			printf("\n");
			switch (menu) {
			case 0:
				insert_Node(a_list);
				list_show(a_list);
				break;
			case 1:
				printf("Search : ");
				scanf("%d", &target_num);
				access = search(a_list, target_num, 0);//only search mode
				if (access == NULL)printf("My List does not have %d\n", target_num);
				else printf("My List has %d.\n", target_num);
				list_show(a_list);
				break;

			case 2:
				printf("Out : ");
				scanf("%d", &target_num);
				access = search(a_list, target_num, 1);//out mode
				if (access == NULL)printf("My List does not have %d\n", target_num);
				list_show(a_list);
				break;
			case 3:exit(1);
			default:
				break;
			};
		}
		break;
	}


}