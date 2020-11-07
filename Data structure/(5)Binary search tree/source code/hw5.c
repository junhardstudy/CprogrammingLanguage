#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
문자열을 사전식 순서로 binary search tree로 구현 했습니다.
*/
typedef struct {
	struct Node* first;
	struct Node* end;
	struct Node* (*deqeueu)(void* argument1, void* argument2);
	struct queue* (*enqueue)(void* argument1, void* argument2);
}queue;

typedef struct {
	struct Node* element;
	struct Node* next;
}queue_elements;

typedef struct {
	char* character;
	struct Node* left;
	struct Node* right;
	void (*printing)(void* argument);
}Node;


//////////////////////////////////////////////////////////////////
int Node_character_cmp(void* a, void* b);
int Node_int_cmp(void* a, void* b);
Node* insert_Node(char* input, Node* bst, int (*cmp)(void* a, void* b));
Node* search(Node* bst, char* target, int (*cmp)(void* a, void* b));
Node* search_and_delete(Node* bst, char* target, Node* preNode, int (*cmp)(void* a, void* b));
int print_BST_right_center_left(Node* bst, int level);
void print_breadth_first(Node* bst);
Node* deqeueu(queue* q, Node* bst);
queue* enqueue(queue* q, Node* bst);
void print_inorder(Node* bst);
void print_postorder(Node* bst);
void print_preorder(Node* bst);
void total_view(Node* bst);
//////////////////////////////////////////////////////////////////


void main() {
	int sel = 0;
	char input[200] = { '\0' };
	Node* head = NULL;
	Node* success = NULL;
	int i = 0;

	while (1) {


		printf("문자열들을 사전식 순서로 정렬했습니다.\nplz type the number for select menu(1.insert 2.search 3.delete) : ");
		scanf("%d", &sel);
		switch (sel)
		{
		case 1:
			printf("입력 : ");
			scanf("%s", input);
			head = insert_Node(&input, head, &Node_character_cmp);
			head->printing(head);

			break;
		case 2:
			printf("data? : ");
			scanf("%s", input);
			success = search(head, &input, &Node_character_cmp);
			if (success == NULL) {
				head->printing(head);
				printf("we don't have such data!\n");
			}
			else {
				head->printing(head);
				printf("we have such data!\n");
			}
			break;
		case 3:
			head->printing(head);
			printf("which data wanna delete? : ");
			scanf("%s", input);
			head = search_and_delete(head, &input, head, &Node_character_cmp);
			head->printing(head);
			break;
		case 4:

		default:
			printf("프로그램을 종료합니다.");
			exit(0);
			break;
		}
	}








}

void total_view(Node* head) {
	system("cls");
	printf("---------current_node_state-----------\n");
	if (head == NULL)return;
	print_BST_right_center_left(head, 0);
	printf("\n-------------------------------------\n");
	printf("\n-------------------------------\n");
	printf("inorder : ");
	print_inorder(head);
	printf("\n-------------------------------\n");
	printf("preorder : ");
	print_preorder(head);
	printf("\n-------------------------------\n");
	printf("postorder : ");
	print_postorder(head);
	printf("\n-------------------------------\n");
	printf("breadth-fist-traverse: ");
	print_breadth_first(head);
	printf("\n-------------------------------\n");
	printf("\n");
}

int Node_character_cmp(void* a, void* b) {
	if (strcmp((char*)a, (char*)b) > 0)return 1;
	if (strcmp((char*)a, (char*)b) < 0)return -1;
	else return 0;
}
int Node_int_cmp(void* a, void* b) {
	if (*((int*)a) >= *((int*)b))return 1;
	else return 0;
}
Node* insert_Node(char* input, Node* bst, int (*cmp)(void* a, void* b)) {
	if (bst == NULL) {
		bst = (Node*)malloc(sizeof(Node)*200);
		bst->character = (char*)malloc(sizeof(char));
		strcpy(bst->character, input);
		bst->left = NULL;
		bst->right = NULL;
		bst->printing = &total_view;
		return bst;
	}
	else {
		if (cmp((bst->character), input) == 1) {

			bst->left = insert_Node(input, bst->left, cmp);

		}
		else {

			bst->right = insert_Node(input, bst->right, cmp);
		}
	}
	return bst;
}

void print_inorder(Node* bst) {

	if (bst->left != NULL)print_inorder(bst->left);
	if (bst != NULL)printf("%s ", (bst->character));
	if (bst->right != NULL)print_inorder(bst->right);


}

void print_preorder(Node* bst) {

	if (bst != NULL)printf("%s ", (bst->character));
	if (bst->left != NULL)print_preorder(bst->left);
	if (bst->right != NULL)print_preorder(bst->right);
}

void print_postorder(Node* bst) {

	if (bst->left != NULL)print_postorder(bst->left);
	if (bst->right != NULL)print_postorder(bst->right);
	if (bst != NULL)printf("%s ", (bst->character));
}

void print_breadth_first(Node* bst) {
	queue* q = (queue*)malloc(sizeof(queue));
	q->first = NULL;
	q->end = NULL;
	q->enqueue = &enqueue;
	q->deqeueu = &deqeueu;
	//큐를 먼저 생성합니다.
	//큐와 관련된 모든 function은 큐 구조체내에서 void 함수로 정의해서 사용합니다.


	q = q->enqueue(q, bst);
	while (1) {

		bst = q->deqeueu(q, bst);
		if (bst == NULL)break;
		if (bst->left != NULL)q = q->enqueue(q, bst->left);
		if (bst->right != NULL)q = q->enqueue(q, bst->right);
		printf("%s ", (bst->character));


	}
}

Node* deqeueu(queue* q, Node* bst) {
	queue_elements* tmp;
	Node* access;
	if (q->first == NULL && q->end == NULL) {
		return NULL;
	}
	else if (q->first == q->end) {
		tmp = q->first;
		access = tmp->element;
		free(tmp);

		q->first = NULL;
		q->end = NULL;

		return access;
	}
	else {

		tmp = q->first;
		access = tmp->element;

		q->first = tmp->next;
		free(tmp);


		return access;


	}
}

queue* enqueue(queue* q, Node* bst) {
	queue_elements* tmp;
	queue_elements* new_element = (queue_elements*)malloc(sizeof(queue_elements));
	new_element->element = bst;
	new_element->next = NULL;

	if (q->first == NULL && q->end == NULL) {
		q->first = new_element;
		q->end = new_element;
		return q;
	}
	else {
		tmp = q->end;
		tmp->next = new_element;
		q->end = new_element;

		return q;
	}
}

int print_BST_right_center_left(Node* bst, int level) {
	level++;

	int i = 0;
	int tmp = level;
	if (bst->right != NULL) {
		tmp = print_BST_right_center_left(bst->right, level);
	}
	for (i = 0; i < level - 1; i++)printf("   ");
	printf("%s\n", (bst->character));
	if (bst->left != NULL) {
		tmp = print_BST_right_center_left(bst->left, level);
	}


}

Node* search_and_delete(Node* bst, char* target, Node* preNode, int (*cmp)(void* a, void* b)) {

	Node* head = bst;
	Node* tmp;
	Node* target_Node;

	if (bst == NULL)return NULL;
	else {
		if (cmp(bst->character, target) == 0) {//if found the node to delete
			if (bst->left == NULL && bst->right == NULL) {
				free(bst);
				return NULL;
			}

			if (bst->left != NULL && bst->right == NULL) {
				tmp = bst->left;
				free(bst);
				bst = tmp;
				return bst;
			}

			if (bst->left == NULL && bst->right != NULL) {
				tmp = bst->right;
				free(bst);
				bst = tmp;
				return bst;
			}

			if (bst->left != NULL && bst->right != NULL) {//양쪽 node 둘다 존재하는 경우
				target_Node = bst;
				bst = bst->right;
				preNode = bst;
				if (bst->left == NULL) {//지우고자 하는 노드의 right child로 한번 이동한후
										//, 그 node의 left가 비어있다면 right subtree의 가장 작은 값은 right sbutree의 root가 됩니다.
					bst->left = target_Node->left;
					free(target_Node);
					target_Node = bst;
					return target_Node;
				}

				if (bst->left != NULL) {//지우고자 하는 노드의 right child로 한번 이동한후
										//, 그 node의 left가 있다면, 지우고자 하는 node의 right subtree의 가장 작은 값을 가지는 node를 찾습니다.
					while (bst->left != NULL) {
						preNode = bst;
						bst = bst->left;
					}


					if (bst->right != NULL) preNode->left = bst->right;//가장 작은 값을 가지는 node가 right child가 존재하는 경우 
																	   //가장 작은 값을 가지는 node의 parent node에 가장 작은 값을 가지는 node의 right child를 붙여줍니다.

					if (bst->right == NULL)preNode->left = NULL;//반대로 가장 작은 값을 가지는 node가 leaf이면
																//가장 작은값을 가지는 node의 parent node의 left에 null을 붙여줍니다.

					if (target_Node->left != NULL) bst->left = target_Node->left;//지우고자 하는 node의 left가 있다면 지우고자 하는 노드의 left subtree를
																				 //가장 작은 값의 node의 left에 붙여줍니다.

					else bst->left = NULL;//반대로 지우고자 하는 노드의 left subtree가 비어있다면, 가장 작은 값의 node의 left에 null을 붙여줍니다.

					if (target_Node->right != NULL)bst->right = target_Node->right;//지우고자 하는 node의 right의 경우또한 마찬가지입니다.
					else bst->right = NULL;


				}
			}

		}

		if (*(bst->character) > * target) {

			bst->left = search_and_delete(bst->left, target, preNode, cmp);
			return bst;
		}

		if (*(bst->character) < *target) {

			bst->right = search_and_delete(bst->right, target, preNode, cmp);
			return bst;
		}


	}
	return bst;



}
Node* search(Node* bst, char* target, int (*cmp)(void* a, void* b)) {
	if (bst == NULL)return NULL;
	else {
		if (cmp(bst->character, target)==0)return bst;
		else if (cmp(bst->character, target) ==1)search(bst->left, target, cmp);
		else search(bst->right, target, cmp);
	}
}