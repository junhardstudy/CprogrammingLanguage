#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	char element;
	struct CBT_Node* left;
	struct CBT_Node* right;
}CBT_Node;

typedef struct {
	struct CBTNode* elemnt;
	struct queue_element* next;
}queue_element;

typedef struct {
	struct queue_element* first;
	struct queue_element* last;
}queue;

void print_inorder(CBT_Node* cbt);
void print_postorder(CBT_Node* cbt);
void print_preorder(CBT_Node* cbt);
void destroy_CBT(CBT_Node* cbt);
void print_breadth_first_traverse(CBT_Node** array_CBT, int number_Nodes);
void enqueue(queue* q, CBT_Node* new_Node);
CBT_Node* dequeue(queue* q);
void print_breadth_first_traverse_2(CBT_Node* cbt);

void main() {
	char input[100] = { NULL };
	CBT_Node** array_CBT;
	CBT_Node* tmp;
	int i;

	printf("please, type strings: ");
	gets(input);
	printf("\n\n\n\n");


	array_CBT = (CBT_Node*)malloc(sizeof(CBT_Node) * strlen(input) + 1);


	for (i = 0; i < strlen(input); i++) {
		tmp = (CBT_Node*)malloc(sizeof(CBT_Node));
		tmp->element = input[i];
		tmp->left = NULL;
		tmp->right = NULL;

		*(array_CBT + i + 1) = tmp;
		

	}

	
	i = 0;
	while (++i < strlen(input)) {
		if (strlen(input) + 1 <=  2 * i)break;
		(*(array_CBT + i))->left = (*(array_CBT + 2*i));
		if (strlen(input) +1 <= 2 * i + 1)break;
		(*(array_CBT + i))->right = (*(array_CBT + 2 * i + 1));
	}

	tmp = *(array_CBT + 1);
	printf("----------------deapth - first - traverse-----------------\n");
	printf("inoreder : ");
	print_inorder(tmp);
	printf("\n");
	printf("preoreder : ");
	print_preorder(tmp);
	printf("\n");
	printf("postoreder : ");
	print_postorder(tmp);
	printf("\n");
	printf("----------------------------------------------------------\n\n\n");
	printf("----------------breadth - first - traverse----------------\n");
	printf("1. from array : ");
	print_breadth_first_traverse(array_CBT, strlen(input));
	printf("\n\n");
	printf("2. from linked_list : ");
	print_breadth_first_traverse_2(tmp);
	printf("\n----------------------------------------------------------\n");

	free(array_CBT);
	destroy_CBT(tmp);

}

void print_inorder(CBT_Node* cbt) {//left_subtree -> center -> right_subtree
	if (cbt->left != NULL)print_inorder(cbt->left);
	printf("%c ", cbt->element);
	if (cbt->right != NULL)print_inorder(cbt->right);
}

void print_preorder(CBT_Node* cbt) {//center -> left_subtree -> right_subtree
	if (cbt != NULL)printf("%c ", cbt->element);
	else return;

	if (cbt->left != NULL)print_preorder(cbt->left);
	if (cbt->right != NULL)print_preorder(cbt->right);
}

void print_postorder(CBT_Node* cbt) {//left_subtree -> right_subtree -> center
	if (cbt == NULL)return;
	else {
		if (cbt->left != NULL)print_postorder(cbt->left);
		if (cbt->right != NULL)print_postorder(cbt->right);
	}
	printf("%c ", cbt->element);

}

void destroy_CBT(CBT_Node* cbt) {
	if (cbt == NULL)return;
	else {
		if (cbt->left != NULL)destroy_CBT(cbt->left);
		if (cbt->right != NULL)destroy_CBT(cbt->right);
	}
	free(cbt);
}

void print_breadth_first_traverse(CBT_Node** array_CBT, int number_Nodes) {
	int i = 0;
	for (i = 0; i < number_Nodes; i++) {
		printf("%c ", (*(array_CBT + i + 1))->element);
	}
}

void print_breadth_first_traverse_2(CBT_Node* cbt) {
	queue* q;
	q = (queue*)malloc(sizeof(queue));
	q->first = NULL;
	q->last = NULL;

	while (cbt != NULL) {

		if (cbt->left != NULL)enqueue(q, cbt->left);
		if (cbt->right != NULL)enqueue(q, cbt->right);
		printf("%c ", cbt->element);
		cbt = dequeue(q);
	}
	
}

void enqueue(queue* q, CBT_Node* new_Node) {
	queue_element* tmp = (queue_element*)malloc(sizeof(queue_element));
	queue_element* read_tmp;
	tmp->elemnt = new_Node;
	tmp->next = NULL;

	if (q->first == NULL && q->last == NULL) {//for empty queue
		q->first = tmp;
		q->last = tmp;
		return;
	}
	else {
		read_tmp = q->last;
		read_tmp->next = tmp;
		q->last = tmp;
	}

}

CBT_Node* dequeue(queue* q) {
	queue_element* tmp;
	

	if (q->first == NULL)return NULL;
	if (q->first == q->last) {
		tmp = q->first;
		q->first = NULL;
		q->last = NULL;
		return tmp->elemnt;
	}
	tmp = q->first;
	q->first = tmp->next;
	return tmp->elemnt;
}