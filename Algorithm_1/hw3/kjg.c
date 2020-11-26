/* Binary search tree using doubly-linked lists
 * COMP319 Algorithms, Fall 2019
 * School of Electronics Engineering, Kyungpook National University
 * Instructor: Gil-Jin Jang
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MEASURE_TIME	// to measure time



 /////////////////////////////////////////////////////////////
 // DATA STRUCTURE:
 // binary tree node definition using doubly linked lists
 // key is a string of a fixed length
 // KEYLENGTH	length of the key
 // BULK_SIZE	key is hidden in the "BULK"
 //	to retrieve key, we have to dig into the "BULK"
 //	so accessing key takes average "BULK_SIZE"/2 searches
 //	this is INTENTIONALLY to add extra overhead for search
 //	your program should reduce the number of key accesses at your best
 /////////////////////////////////////////////////////////////
#define KEYLENGTH	3
#define BULK_SIZE	4096
//#define BULK_SIZE	65536



struct BTNode {
	char bulk[BULK_SIZE];	// null character to be added
	struct BTNode* left, * right;	// binary tree: left and right children
};


typedef struct {
	struct BTNode* element;
	struct BTNode* forward;
	struct BTNode* backward;
	int slash;
}linked_list_element;

typedef struct{
	struct linked_list_element* first;
	struct linked_list_element* end;
	int size;
}queue;

typedef struct {
	struct BTNode* element;
	char* key;
}linked_array;

queue* enqueue(queue* q1, struct BTNode* bst, int level);
queue* end_dequeue(queue* q1);
int check_slash(queue* q1, int level);
struct BTNode* same_check(queue* q1,struct BTNode* bst);
struct BTNode* split_index(int left, int right, struct BTNode** array_str);


/////////////////////////////////////////////////////////////
// GIVEN: functions for binary tree node 
// name and parameters only
// implementations are moved after "main" function
/////////////////////////////////////////////////////////////

const char* getkey(struct BTNode* a);
// return value: char array of KEYLENGTH+1 (+1 for '\0' character)
//  key is hidden in "bulk", so use the following function to
//  read key string of length KEYLENGTH
//  it will make BULK_SIZE/2 searches on average
//  so try to use it as rarely as possible

int setkey(struct BTNode* a, const char kw[]);
// return value: 0 for failure (NULL a), 1 for success
//  the following function hides a string "kw" of KEYLENGTH
//  by randomly selecting the location to save key

int copykey(struct BTNode* dst, struct BTNode* src)
{
	return setkey(dst, getkey(src));
}
// copies the key of one node to the other
// very simple, single line, so implementation is given here

int comparekey(struct BTNode* a, struct BTNode* b);
// return value: (by character comparison)
//  -1 if a's key < b's key
//  0 if a's key == b's key
//  +1 if a's key > b's key
//  may be needed for binary search tree search and build-up

struct BTNode* generate_btnode(const char kw[]);
// return value: pointer to a single BTNode (left/right are NULL)
//  generates a node for binary tree

void free_bt_recursive(struct BTNode* bt);
// frees a binary tree

struct BTNode* copy_bt_recursive(struct BTNode* bt);
// return value: pointer to the root of the copy of the given binary tree "bt"

struct BTNode* insert_left_bcnode(
	struct BTNode* parent, struct BTNode* newPtr);
//  adds a node to the left of a BTNode parent
//  it will be used to generate a left-half binary tree
//  (LHBT, all rights are NULL)
// pre-condition: left pointer to the new node should be NULL
// to store the left pointer to the parent node
// return value: parent if the given parent is not NULL; newPtr if parent NULL

struct BTNode* readkeys_textfile_LHBT(const char infile[], int* pN);
// File I/O: read key words from the given file
// and generate a binary tree which is left-half
// (all right children are NULL)


double logB(double x, double base);
struct BTNode* partition_q(struct BTNode** left, struct BTNode** right, struct BTNode* lhbt);
void add_to_tail(struct BTNode* head, struct BTNode* tail, struct BTNode* element);

/////////////////////////////////////////////////////////////
// FILL 1: generate a binary search tree using insertion
/////////////////////////////////////////////////////////////
struct BTNode* insert_to_BST_leaf(struct BTNode* bst, struct BTNode* newPtr)
{
	if (bst == NULL) return newPtr;	// new bst as the input node
	else if (newPtr == NULL) return bst;	// nothing to add
	else {
		if (comparekey(bst, newPtr) < 0) {
			/* FILL */
			bst->right = insert_to_BST_leaf(bst->right, newPtr);
		}
		else {
			bst->left = insert_to_BST_leaf(bst->left, newPtr);
			/* FILL */
		}
	}
	return bst;
}

struct BTNode* generate_BST_by_insertion(struct BTNode* lhbt)
{
	/* FILL */
	/* (hint: use insert_to_BST_leaf repeatedly) */
	struct BTNode* tmp = NULL;
	struct BTNode* bst = NULL;
	while (lhbt != NULL) {
		tmp = lhbt;
		lhbt = lhbt->left;
		tmp->left = NULL;
		bst = insert_to_BST_leaf(bst, tmp);
	}
	return bst;
}

/////////////////////////////////////////////////////////////
// FILL 2: PRINT
/////////////////////////////////////////////////////////////
int print_LHBT(FILE* fp, struct BTNode* lhbt)
// prints left-half binary tree
// ___-___-___
// INPUT
//   fp: file pointer for the output file, stdout for monitor output
//   lhbt: left-half binary tree (right pointers are all null)
// RETURNs number of NODES in the list
{
	int num_nodes;

	num_nodes = 0;
	while (lhbt) {
		if (lhbt->right != NULL) {	// check if left-half
			fprintf(stderr, "Non-left-half binary tree for %s\n", __FUNCTION__);
			break;
		}
		else {
			fprintf(fp, "%s", getkey(lhbt));
			if (lhbt->left != NULL) fprintf(fp, "-");
		}
		num_nodes++;
		lhbt = lhbt->left;
	}

	fprintf(fp, "\n");	// change the line at the end

	return num_nodes;
}

int print_BST_sortedorder(FILE* fp, struct BTNode* bst, int level)
// prints a binary search tree nodes by a single line
// in a SORTED ORDER
// (hint: inorder traversal)
// INPUT
//   fp: file pointer for the output file, stdout for monitor output
//   bst: root node of the BST, should satisfy the property of
//      binary search tree, left <= center < right
//   level: level of the root node, starting from 0 (empty)
//      if it is unnecessary, do not have to use it
// RETURNs number of NODES in the list
{
	/* GJ: you may fill out the *FILL* lines, or completely rewrite */
	int count;	// to count the number of nodes
	char* tmp;

	count = 0;
	if (bst != NULL) {
		level++;	// root node of the current subtree exists

		/* FILL: print left subtree */
		count += print_BST_sortedorder(fp, bst->left, level);

		// center node

		fprintf(fp, "%s ", getkey(bst));
		
		
		count++;

		/* FILL: print right subtree */
		count += print_BST_sortedorder(fp, bst->right, level);
	}

	// change the line once - only at the bst node
	if (level <= 1) fprintf(fp, "\n");

	return count;
}
int h1 = 0;
int print_BST_right_center_left(FILE* fp, struct BTNode* bst, int level)
// prints a binary search tree, rotated by 270 degrees
// Note: key's length is fixed to KEYLENGTH, so there are
// (KEYLENGTH+1)*level spaces. For examples,
//         999
//     777
//         555
// 333
//     222
//         111
// INPUT
//   (same as print_BST_sortedorder)
// RETURNs HEIGHT-1 of the printed tree (2 in the above example)
//   (hint: printing order is right -> center -> left
//    carefully count the number of spaces)
{
	/* FILL */
	level++;
	
	int i = 0;
	int tmp = level;
	if (bst->right != NULL) {
		tmp = print_BST_right_center_left(fp, bst->right, level);
	}
	for (i = 0; i < level-1; i++)printf("   ");
	printf("%s\n", getkey(bst));
	if (level > h1)h1 = level;
	if (bst->left != NULL) {
		tmp = print_BST_right_center_left(fp, bst->left, level);
	}
	
	return h1;
}

int h2 = 0;
int print_BST_1(FILE* fp, struct BTNode* bst, int level)
// prints a binary search tree, rotated by 270 degrees, with less lines
//  1) center and right are in the same line
//  2) left subtree is below the center
//  3) right is connected by '/' and left by '+'
// Note: key's length is fixed to KEYLENGTH,
// so left and right begins at (KEYLENGTH+1)*level+1
// 333/777/999
//        +555
//    +222
//        +111
// (or)
// 100/400/800/900
//                +900
//            +800
//                +500/700
//    +000
// INPUT and OUPUT
//   (same as print_BST_right_center_left)
//   (hint: printing order is center -> right -> left)
{
	/* FILL */
	int i = 0;
	if (bst == NULL)return -1;
	printf("%s", getkey(bst));
	if (level + 1 > h2)h2 = level + 1;
	level++;
	if (bst->right != NULL) {
		printf("/");
		print_BST_1(fp, bst->right, level);
	}
	if (bst->left != NULL)printf("\n");
	
	if (bst->left != NULL) {
		for (i = 0; i < level; i++) {
			printf("   ");
			if (i < level-1)printf(" ");
		}
		printf("+");
		
		print_BST_1(fp, bst->left, level);
		
	}
	return h2;
}

int print_BST_2(FILE* fp, struct BTNode* bst, int level, queue *q1)
// same as print_BST_1 except vertical line from center to left
// 100/400/800/900
//    |       |   +900
//    |       +800
//    |           +500/700
//    +000
// Hint: stack or some extra variables may help.
//       static variable can be used as well
//       You may add additional parameter to the function if necessary
{
	/* FILL */
	int i = 0;
	if (bst == NULL)return -1;
	printf("%s", getkey(bst));
	level++;
	//if (bst == same_check(q1)) end_dequeue(q1);
	if (bst->right != NULL && bst->left != NULL)enqueue(q1, bst, level-1);
	if (bst->right != NULL) {
		printf("/");
		print_BST_2(fp, bst->right, level, q1);
	}
	if (bst->left != NULL)printf("\n");
	if (same_check(q1, bst) == 1) end_dequeue(q1);
	
	
	if (bst->left != NULL) {
		for (i = 0; i < level; i++) {
			printf("   ");
			if (i < level - 1) {
				if (check_slash(q1, i+1) == 1)printf("|");
				else printf(" ");
			}
		}
		printf("+");
		print_BST_2(fp, bst->left, level, q1);
	}
	
}
struct BTNode* same_check(queue *q1, struct BTNode* bst) {
	linked_list_element* tmp;
	linked_list_element* tmp_2;
	if (q1->first == NULL) {
		
		return -1;
	}
	tmp_2 = q1->end;
	tmp = q1->end;
	//printf("\n%d %d %d\n", bst, tmp->element, tmp_2->element);
	if (bst == tmp->element) {
		return 1;
	}
	else {
		return -1;
	}
	
}

queue* enqueue(queue* q1, struct BTNode *bst, int level) {
	linked_list_element* tmp = (linked_list_element*)malloc(sizeof(linked_list_element));
	linked_list_element* l_tmp;

	tmp->element = bst;
	tmp->forward = NULL;
	tmp->backward = NULL;
	tmp->slash = level + 1;

	if (q1->end == NULL && q1->first == NULL) {
		q1->first = tmp;
		q1->end = tmp;
		q1->size++;
		return q1;
	}
	else {
		l_tmp = q1->end;
		l_tmp->backward = tmp;
		tmp->forward = l_tmp;
		q1->size++;
		q1->end = tmp;
		return q1;
	}
}
queue* end_dequeue(queue* q1) {
	linked_list_element* tmp;
	linked_list_element* prev;
	if (q1->first == q1->end) {
		free(q1->first);
		q1->first = NULL;
		q1->end = NULL;
		q1->size = 0;
	}
	if (q1->first == NULL) {
		return NULL;
	}
	tmp = q1->end;
	if (q1->end != q1->first) {
		prev = tmp->forward;
		prev->backward = NULL;
		free(q1->end);
		q1->end = prev;
		(q1->size)--;
	}
	else {
		free(q1->first);
		q1->first = NULL;
		q1->end = NULL;
		(q1->size)--;
	}
	return q1;
}

int check_slash(queue *q1, int level) {
	linked_list_element* read;

	if (q1->first == NULL)return -1;
	read = q1->first;
	while (read != NULL) {
		if (read->slash == level)return 1;
		else read = read->backward;
	}
	return -1;

}


/////////////////////////////////////////////////////////////
// FILL 3: Conversion of an BST to a complete BST
/////////////////////////////////////////////////////////////

struct BTNode* BST_to_completeBST(struct BTNode* bst, int numNodes, struct BTNode** array_str)
	// convert a BST to complete BST (minimum height, filling in left first)
	// INPUT
	//   bst: root node of the BST, should satisfy the property of
	//      binary search tree, left <= center < right
	//   numNodes: number of nodes in the bst
	//      if not necessary in your implementation, do not have to use it
	// RETURNs a COMPLETE BST 
	// (hint: using extra memory (arrays or lists) may help,
	//  array's rule for parent-child, sorted list, etc.)
{
	/* FILL */

	
	queue* q;
	int i = 0;
	int j = 0;
	int k = 0;
	int cur;
	int n;
	int need_right_node;
	//linked_array* tmp;
	struct BTNode* pre;
	struct BTNode* after;
	struct BTNode* sorted_lhbt;
	struct BTNode* tmp;
	struct BTNode** test;
	

	n = (int)logB(numNodes, 2.0) - 1;
	need_right_node = (int)pow(2, n) - 1;
	printf("\nneeded right node : %d, %d\n", need_right_node, n);
	printf("center node = %s\n", getkey(*(array_str + numNodes - 1 - need_right_node)));
	cur = numNodes - 1 - need_right_node;

	for (i = 0; i < numNodes ; i++) {
		tmp = *(array_str + i);
		tmp->right = NULL;
		tmp->left = NULL;
	}
	tmp->left = NULL;
	tmp->right = NULL;

	


	tmp = split_index(0, numNodes, array_str);
	printf("\n\n---------test----------\n\n");
	print_BST_1(stdout, tmp, 0);
	printf("\n\n-----------test_done------------\n\n");
	return *(array_str);
	
}
struct BTNode* split_index(int left, int right, struct BTNode** array_str) {
	int pivot_index = 0;
	int n;
	int need_right_node;
	
	n = (int)logB(right - left + 1, 2.0) - 1;
	need_right_node = (int)pow(2, n) - 1;
	pivot_index = (right - left )-1 - need_right_node;
	printf("center = %d\n", pivot_index);
	/*
	pivot_index 구하기
	*/

	if (right -left > 1) {
		(*(array_str + pivot_index))->left = split_index(left, pivot_index - 1, array_str);
		(*(array_str + pivot_index))->right = split_index(pivot_index+1,right, array_str);
	}
	printf("%s\n", getkey(*(array_str + pivot_index)));
	return *(array_str + pivot_index);
}


struct BTNode* make_sorted_array(struct BTNode* bst, struct BTNode** array_str, int* key_index) {
	
	if (bst->left != NULL)make_sorted_array(bst->left, array_str, key_index);
	*(array_str + *key_index)  = bst;
	++(*key_index);
	if (bst->right != NULL)make_sorted_array(bst->right, array_str, key_index);

}
double logB(double x, double base) { 
	return log(x) / log(base);
}






/////////////////////////////////////////////////////////////
// FILL 4: generate binary search tree from a left-half binary tree
// using quick sort
/////////////////////////////////////////////////////////////
struct BTNode* generate_BST_quicksort_basic(struct BTNode* lhbt)
	// gerate a BST using quick sort algorithm
	// the resultant tree should be identical to generate_BST_by_insertion
{
	/* FILL */
	struct BTNode* pivot_node;
	struct BTNode* left_subtree = NULL;
	struct BTNode* right_subtree = NULL;
	pivot_node = lhbt;
	if (lhbt != NULL && lhbt->left != NULL) {
		pivot_node = partition_q(&left_subtree, &right_subtree, lhbt);
		pivot_node->left = generate_BST_quicksort_basic(left_subtree);
		pivot_node->right = generate_BST_quicksort_basic(right_subtree);
		return pivot_node;
	}
	return lhbt;
}

struct BTNode* partition_q(struct BTNode** left, struct BTNode** right, struct BTNode *lhbt) {
	struct BTNode* pivot_Node = lhbt;
	struct BTNode* LB; 
	struct BTNode* RB;
	struct BTNode* LT;
	struct BTNode* RT;
	struct BTNode* tmp = NULL;

	LB = NULL;
	LT = NULL;
	RB = NULL;
	RT = NULL;
	lhbt = lhbt->left;
	//pivot_Node->left = NULL;//to make isolation
	while (lhbt != NULL) {
		tmp = lhbt;
		lhbt = lhbt->left;
		tmp->left = NULL;
		if (comparekey(tmp, pivot_Node) <= 0) {
			add_to_tail(&LB, &LT, tmp);
		}
		else {
		
			add_to_tail(&RB, &RT, tmp);
		}
	}
	*left = LB;
	*right = RB;
	return pivot_Node;
}

void add_to_tail(struct BTNode** head, struct BTNode** tail, struct BTNode* element) {
	if (*head == NULL && *tail == NULL) {

		*head = element;
		*tail = element;
	}
	else {
		(*tail)->left = element;
		(*tail) = (*tail)->left;
		(*tail)->right = NULL;
	}
}

struct BTNode* generate_BST_quicksort_advanced(struct BTNode* lhbt)
	// challenge: try to reduce the height using quick sort algorithm
{
	/* FILL */
}

/////////////////////////////////////////////////////////////
// main function 
/////////////////////////////////////////////////////////////
#define MAXLINE	1024
int main()
{
	int i = 0;
	int* key_index;
	struct BTNode* tmp;
	struct BTNode** array_str;
	queue* q1;
	int numWords;	// number of words 
	//int wordLen;	// word length: number of characters per word
	struct BTNode* root, * bst1, * bst2;
	int numNodes, lev;	// level of the tree

	/* for file name, max length 1023 including path */
	char line[MAXLINE];
	char infile[MAXLINE], outfile[MAXLINE];
	FILE* fp;

#ifdef MEASURE_TIME
	clock_t start, end;
	double cpu_time_used;
#endif

	/* input file name given by keyboard */
	memset(line, 0, sizeof(char) * MAXLINE);	// clear the buffer
	fprintf(stderr, "Input file name? ");
	fgets(line, MAXLINE, stdin);
	if (strlen(line) == 0 || sscanf(line, "%s", infile) != 1) {
		fprintf(stderr, "cannot read input file name from '%s'\n", line);
		exit(0);
	}

	/* output file name: enter for standard out */
	memset(line, 0, sizeof(char) * MAXLINE);	// clear the buffer
	fprintf(stderr, "Output file name? ");
	fgets(line, MAXLINE, stdin);
	if (strlen(line) == 0 || sscanf(line, "%s", outfile) != 1) {
		fprintf(stderr, "cannot read output file name from '%s'\n", line);
		fprintf(stderr, "output to stdout\n");
		fp = stdout;
		memset(outfile, 0, sizeof(char) * MAXLINE);	// clear the buffer
	}
	else {
		/* open output file pointer */
		fp = fopen(outfile, "w");
		if (fp == NULL) {
			fprintf(stderr, "cannot open file '%s' for write\n", outfile);
			fprintf(stderr, "output to stdout\n");
			fp = stdout;
		}
	}

	/* read text file of integers:
	 * number_of_intergers integer1 integer2 ...
	 * then convert it to a linked list */
	root = readkeys_textfile_LHBT(infile, &numWords);

#ifdef MEASURE_TIME
	start = clock();
#endif

	if (root != NULL) {

		// prints input
		fprintf(fp, "=====================================\n");
		numNodes = print_LHBT(fp, root);
		fprintf(fp, "total %d nodes\n", numNodes);
		array_str = (struct BTNode*)malloc(sizeof(struct BTNode)*numNodes);
		key_index = (int*)malloc(sizeof(int));
		*key_index = 0;

		// BST construction by simple insertion
		// keep root unchanged
		bst1 = generate_BST_by_insertion(copy_bt_recursive(root));
		
		fprintf(fp, "=====================================\n");
		numNodes = print_BST_sortedorder(fp, bst1, 0);
		fprintf(fp, "total %d nodes (sorted)\n", numNodes);
		fprintf(fp, "=====================================\n");

		printf("\n\n");

		lev = print_BST_right_center_left(fp, bst1, 0);
		fprintf(fp, "BST height %d\n", lev);
		fprintf(fp, "=====================================\n");

		printf("\n\n");

		lev = print_BST_1(fp, bst1, 0);
		fprintf(fp, "BST height %d\n", lev);
		fprintf(fp, "=====================================\n");

		q1 = (queue*)malloc(sizeof(queue));
		q1->end = NULL;
		q1->first = NULL;
		q1->size = 0;
		printf("\n\n");
		lev = print_BST_2(fp, bst1, 0, q1);
		fprintf(fp, "BST height %d\n", lev);
		fprintf(fp, "=====================================\n");
		free(q1);
	
		
		//bst1 = BST_to_completeBST(bst1, numNodes);
		
		make_sorted_array(bst1,array_str , key_index);
		
		/*
		lev = print_BST_2(fp, bst1, 0, q1);
		*/
		//fprintf(fp, "BST height %d\n", lev);

		// BST using quick sort, pivot as left, basic
		
		bst2 = generate_BST_quicksort_basic(copy_bt_recursive(root));
		//lev = print_BST_2(fp, bst2, 0);
		printf("\n\n\n\n");
		printf("아래 두개는 quick_sort 첫번째 문제에 대해서 print1과 print2로 표시만 했습니다. complete bst는 아닙니다.\n\n");
		lev = print_BST_1(fp, bst2, 0);
		printf("\n\n\n\n");
		q1 = (queue*)malloc(sizeof(queue));
		q1->end = NULL;
		q1->first = NULL;
		q1->size = 0;
		print_BST_2(fp, bst2, 0, q1);
		printf("\n\n\n\n");
		fprintf(fp, "BST by QUICKSORT, height %d\n", lev);
		fprintf(fp, "=====================================\n");
		free(q1);
	
		/*
		// BST using quick sort, advanced, to reduce height
		bst2 = generate_BST_quicksort_advanced(copy_bt_recursive(root));
		lev = print_BST_2(fp, bst2, 0);
		fprintf(fp, "BST by QUICKSORT (advanced), height %d\n", lev);
		fprintf(fp, "=====================================\n");
		*/
		free_bt_recursive(root);
		free_bt_recursive(bst1);
		free_bt_recursive(bst2);

		
	}

#ifdef MEASURE_TIME
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	fprintf(fp, "TIME %.5f seconds\n", cpu_time_used);
#endif

	if (fp != NULL && fp != stdout) fclose(fp);
	return 0;
}


/////////////////////////////////////////////////////////////
// implementation: functions for binary tree node 
/////////////////////////////////////////////////////////////

const char* getkey(struct BTNode* a)
{
	int i;
	for (i = 0; i < BULK_SIZE - KEYLENGTH; i++) {
		if (a->bulk[i] != '\0') return a->bulk + i;
	}
	return NULL;	// not found
}

int setkey(struct BTNode* a, const char kw[])
{
	int pos;
	if (a != NULL) {
		// fill with 0
		memset(a->bulk, 0, sizeof(char) * BULK_SIZE);

		// find position randomly to store KEYLENGTH+1 characters
		pos = rand() % (BULK_SIZE - KEYLENGTH);
		if (kw != NULL) memcpy(a->bulk + pos, kw, sizeof(char) * KEYLENGTH);
		a->bulk[pos + KEYLENGTH] = '\0';	// to make it a C string

		// success
		return 1;
	}
	else return 0;
}

struct BTNode* generate_btnode(const char kw[])
{
	struct BTNode* tmp;

	tmp = (struct BTNode*)malloc(sizeof(struct BTNode));
	setkey(tmp, kw);

	// initial left and right children for the generated leaf node
	tmp->left = tmp->right = NULL;

	return tmp;
}

void free_bt_recursive(struct BTNode* bt)
{
	if (bt != NULL) {
		free_bt_recursive(bt->left);
		free_bt_recursive(bt->right);
		free(bt);
	}
}

struct BTNode* copy_bt_recursive(struct BTNode* bt)
{
	struct BTNode* dup;

	if (bt != NULL) {
		dup = (struct BTNode*) malloc(sizeof(struct BTNode));
		copykey(dup, bt);
		dup->left = copy_bt_recursive(bt->left);
		dup->right = copy_bt_recursive(bt->right);
	}
	else dup = NULL;
	return dup;
}

struct BTNode* insert_left_bcnode(struct BTNode* parent, struct BTNode* newPtr)
{
	if (parent == NULL) return newPtr;	// no parent
	else if (newPtr == NULL) return parent;	// Nothing to add
	else if (newPtr->left != NULL) {
		fprintf(stderr, "cannot add a node with non-null left tree\n");
		return parent;
	}
	else {
		newPtr->left = parent->left;
		parent->left = newPtr;
		return newPtr;	// returning new node as a new parent
	}
}

// static: internal use only
static int _compare_n_char(const char a[], const char b[], int L)
{
	int i;
	for (i = 0; i < L; i++) {
		if (a[i] < b[i]) return -1;
		else if (a[i] > b[i]) return 1;
		else continue;	// to next character
	}
	return 0;
}

int comparekey(struct BTNode* a, struct BTNode* b)
{
	return _compare_n_char(getkey(a), getkey(b), KEYLENGTH);
}

/////////////////////////////////////////////////////////////
// File I/O
/////////////////////////////////////////////////////////////
struct BTNode* readkeys_textfile_LHBT(const char infile[], int* pN)
	// read key words from the given file
	// and generate a binary tree which is skewed to the left 
	// (all right children are NULL)
{
	struct BTNode* root, * cur, * tmp;
	char word[1024];
	FILE* fp;
	int i;

	// check for input file name
	if (infile == NULL) {
		fprintf(stderr, "NULL file name\n");
		return NULL;
	}

	// check for file existence
	fp = fopen(infile, "r");
	if (!fp) {
		fprintf(stderr, "cannot open file %s\n", infile);
		return NULL;
	}

	// check for number of keys
	if (fscanf(fp, "%d", pN) != 1 || *pN <= 0) {
		fprintf(stderr, "File %s: ", infile);
		fprintf(stderr, "number of keys cannot be read or or wrong\n");
		fclose(fp);
		return NULL;
	}

	/*
	// check for number of characters per key
	if ( fscanf(fp, "%d", pL) != 1 || *pL <= 0 ) {
	  fprintf(stderr, "File %s: ",infile);
	  fprintf(stderr, "number of characters per key cannot be read or or wrong\n");
	  fclose(fp);
	  return NULL;
	}
	*/

	// reading keys
	root = cur = tmp = NULL;
	for (i = 0; i < (*pN); i++) {
		if (fscanf(fp, "%s", word) != 1) {
			fprintf(stderr, "cannot read a word at %d/%d\n", i + 1, (*pN));
			*pN = i;	// number of read keys so far
			break;
		}
		else {
			//check_and_correct_word(word, KEYLENGTH);

			// generate a new node
			tmp = generate_btnode(word);

			if (root == NULL) root = cur = tmp;
			else cur = insert_left_bcnode(cur, tmp);
		}
	}

	return root;
}

