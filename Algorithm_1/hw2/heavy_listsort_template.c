/* Directions: complete the code by filling in "FILL" parts
 *   adding functions and variables is allowed
 *   do not change print and file load/save
 *   do not use your compiler-specific libraries
 * Note: TIME in seconds is measured
 * FILL parts: insertion and merge sort on heavy linked lists
 */

/* Insertion sort and merge sort on Heavy Linked Lists
 * COMP319 Algorithms, Fall 2019
 * School of Electronics Engineering, Kyungpook National University
 * Instructor: Gil-Jin Jang
 */

#include <stdio.h>
#include <stdlib.h>

#define MEASURE_TIME    // to measure execution time

/////////////////////////////////////////////
// to compute execution time in seconds
/////////////////////////////////////////////
#ifdef MEASURE_TIME
#include<time.h>
/* time measurement example */
/*
clock_t start, end;
double cpu_time_used;

start = clock();
... // Do the work.
end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
*/

/* from GJANG: not sure if the above works with Windows */
#endif
struct LHNode* merget_list(struct LHNode* left, struct LHNode* right);
/////////////////////////////////////////////////////////////
// common functions for handling arrays
/////////////////////////////////////////////////////////////
long *readkeys_textfile( const char infile[], int *pN )
  // returns an array of long integers, with its size stored in
  // the memory indicated by integer pointer variable pN
  // the retured memory should freed by the caller
{
  long *A, tmp;
  int i;
  FILE *fp;

  // check for input file name
  if ( infile == NULL ) {
    fprintf(stderr, "NULL file name\n");
    return NULL;
  }

  // check for file existence
  fp = fopen(infile,"r");
  if ( !fp ) {
    fprintf(stderr, "cannot open file %s\n",infile);
    return NULL;
  }
  else {
    // check for number of elements
    if ( fscanf(fp, "%d", pN) != 1 || *pN <= 0 ) {
      fprintf(stderr, "cannot read number of elements %s\n",infile);
      return NULL;
    }
    else {
      A = (long*)malloc(sizeof(long)*(*pN));
      for (i=0; i<(*pN); i++) {
	if ( fscanf(fp, "%ld", &tmp) != 1 ) {
	  fprintf(stderr, "cannot read value at %d/%d\n",i+1,(*pN));
	  *pN = i;	// read data items
	  return A;
	}
	else A[i] = tmp;
      }
    }
    fclose(fp);
    return A;
  }
}

/////////////////////////////////////////////////////////////
// functions for handling linked lists
/////////////////////////////////////////////////////////////
#define LOAD_SIZE	4096
struct LHNode {	// update: item type chagned to long, variable name to key
  long key;
  struct LHNode *next;
  long ManyItems[LOAD_SIZE];
};

struct LHNode *generateLHNode(long key)
{
  struct LHNode *tmp;
  int i;

  tmp = (struct LHNode*) malloc(sizeof(struct LHNode));
  tmp->key = key;
  tmp->next = NULL;	// bugfix on 190924

  // fill ManyItems with the key
  for (i=0; i<LOAD_SIZE; i++) tmp->ManyItems[i] = key;

  return tmp;
}

struct LHNode *insert_head(struct LHNode *head, struct LHNode *newPtr)
{
  if ( newPtr == NULL ) return head;	// Nothing to add
  else {
    newPtr->next = head;
    return newPtr;
  }
}

struct LHNode *insert_next(struct LHNode *prev, struct LHNode *newPtr)
{
  //struct LHNode *cur;	// unnecessary 190924
  if ( newPtr == NULL ) return prev;	// Nothing to add
  else if ( prev == NULL ) return insert_head(NULL, newPtr);
  else {
    //cur = prev->next;	// unnecessary, so removed, on 190924
    //newPtr->next = cur;	// unnecessary, so removed, on 190924
    newPtr->next = prev->next;
    prev->next=newPtr;
    return newPtr;
  }
}

long pick_random_item( struct LHNode *pH )
  // pick an item from HeavyItem randomly
  // to check if items are maintained correctly
  // if key is changed only, values in the itmes may not match key
{
  return pH->ManyItems[rand()%LOAD_SIZE];
}

/////////////////////////////////////////////////////////////
// functions for heavy load of items
void traverse_print_random_item(struct LHNode *L)
{
  struct LHNode *cur;
  printf("[");
  for (cur=L ; cur != NULL ; cur = cur->next ) {
    //printf("%ld ",cur->key);
    printf("%ld ",pick_random_item(cur));
  }
  printf("]\n");
}

// the below list handling codes are not used.
// so commented out, but may use them
/*
struct LHNode *emptylist()
{
  return NULL;
}

struct LHNode *delete_head(struct LHNode *head)
{
  struct LHNode *cur;
  if ( head == NULL ) return NULL;	// empty, nothing to delete
  else {
    cur = head;
    head = head->next;
    cur->next = NULL;	 // not necessary, but just left
    free(cur);
    return head;
  }
}

struct LHNode *delete_next(struct LHNode *prev)
{
  struct LHNode *cur;
  if ( prev == NULL ) return NULL;	// empty from prev, nothing
  else {
    cur = prev->next;
    prev->next = cur->next;
    cur->next = NULL;	// not necessary
    free(cur);
    //cur = prev->next;	// not necessary here
    return prev;
  }
}

struct LHNode *lookup_recursive (long x, struct LHNode *L)
{
  if (L == NULL) return NULL;
  else if (x == L->key) return L;
  else return lookup_recursive(x, L->next);
}

struct LHNode *lookup_iterative (long x, struct LHNode *L)
{
  struct LHNode *cur;
  for (cur=L ; cur != NULL ; cur = cur->next ) {
    if ( x == cur->key ) return cur;
  }
  return NULL;
}
*/

void free_list_iterative (struct LHNode *L)
{
  struct LHNode *tmp;
  while ( L != NULL ) {
    tmp = L;
    L = L->next;	// every node access should be done before free()
    free(tmp);
  }
}

/////////////////////////////////////////////////////////////
// read a linked list from textfile
/////////////////////////////////////////////////////////////
struct LHNode *array2linkedlist(long A[], int N)
{
  struct LHNode *head, *cur, *prev;
  int i;

  head = NULL; prev = NULL;
  for (i=0; i<N; i++) {
    cur = generateLHNode(A[i]);
    prev = insert_next(prev,cur);
    if ( head == NULL ) head = prev;
  }

  return head;
}

struct LHNode *readkeys_textfile_linkedlist( const char infile[], int *pN )
  // read text file of integers:
  // number_of_intergers integer1 integer2 ...
  // then convert it to a linked list
  // returns a list list of struct LHNode, with its size stored in
  // the memory indicated by integer pointer variable pN
{
  struct LHNode *head;
  long *A;

  A = readkeys_textfile(infile, pN);
  if ( A != NULL && *pN > 0 ) {
    head = array2linkedlist(A,*pN);
    free(A);
    return head;
  }
  else return NULL;	// failed
}

void savekeys_textfile_linkedlist( const char outfile[],
    struct LHNode *head, int N )
  // save the given linked list to file whose name given by outfile[]
{
  FILE *fp;

  // check for output filename
  if ( outfile == NULL ) {
    fprintf(stderr, "NULL file name\n");
    return;
  }

  // check for file existence
  fp = fopen(outfile,"w");
  if ( !fp ) {
    fprintf(stderr, "cannot open file for write %s\n",outfile);
  }
  else {
    // save number of elements
    fprintf(fp, "%d\n",N);
    for (; head; head = head->next ) fprintf(fp, "%ld ", head->key);
    fprintf(fp,"\n");
    fclose(fp);
  }
}


/////////////////////////////////////////////////////////////
// linked list insertion sort
/////////////////////////////////////////////////////////////
/* GJ: may add any additional functions */

struct LHNode *list_insertion_sort ( struct LHNode *head )
{
	/* GJ: FILL */
	struct LHNode* read_node;
	struct LHNode* target_node;
	struct LHNode* tmp;
	struct LHNode* prev_tmp;
	struct LHNode* sorted_Node;
	struct LHNode* sorted_head;
	long tmp_min;
	sorted_head = NULL;
	prev_tmp = head;
	read_node = prev_tmp->next;



	if (read_node == NULL) {
		sorted_Node = prev_tmp;
		return sorted_Node;
	}//only left one elemnet.


	tmp = head;
	tmp_min = head->key;
	target_node = read_node;

	while (head->next != NULL) {

		while (read_node != NULL) {
			if (tmp_min > read_node->key) {
				tmp_min = read_node->key;
				target_node = read_node;
				prev_tmp = tmp;

			}

			tmp = read_node;
			read_node = read_node->next;
		}//find_minimum_value


		if (sorted_head == NULL) {//for insertion first elemnet
			sorted_Node = target_node;
			prev_tmp->next = target_node->next;
			sorted_Node->next = NULL;
			sorted_head = sorted_Node;
		}
		else if (target_node == head) {//head에서 최소값 발견했을때
			head = target_node->next;
			sorted_Node->next = target_node;
			sorted_Node = sorted_Node->next;
			sorted_Node->next = NULL;

		}
		else {//insertion sort head < target_node > tail
			prev_tmp->next = target_node->next;
			sorted_Node->next = target_node;
			sorted_Node = sorted_Node->next;
			sorted_Node->next = NULL;
		}
		prev_tmp = head;
		read_node = prev_tmp->next;
		tmp = head;
		tmp_min = head->key;
		target_node = head;


	}
	sorted_Node->next = head;
	head = NULL;
	sorted_Node = sorted_Node->next;
	sorted_Node->next = NULL;
	return sorted_head;
}


/////////////////////////////////////////////////////////////
// linked list merge sort
/////////////////////////////////////////////////////////////
/* GJ: may add any additional functions */

struct LHNode *list_array_merge_sort( struct LHNode **head_array, int N )
{
	/* GJ: FILL */
	int mid, left_index, right_index, tmp;
	int i, j;
	while (N != 1) {
		mid = N / 2;
		left_index = 0;
		right_index = mid + N % 2;
		tmp = right_index;
		for (; left_index < mid; left_index++, right_index++)*(head_array + left_index) = merget_list(*(head_array + left_index), *(head_array + right_index));
		N = tmp;
	}

	return *head_array;
}

struct LHNode* merget_list(struct LHNode* left, struct LHNode* right) {
	struct LHNode* target_node;
	if (left == NULL)return right;
	if (right == NULL)return left;

	if (left->key < right->key) {
		target_node = left;
		left->next = merget_list(left->next, right);
	}
	else {
		target_node = right;
		right->next = merget_list(left, right->next);
	}
	return target_node;
}
/////////////////////////////////////////////////////////////

/* File name by Argument input -> scanf read
 * Input file name can be typed in the terminal
 * Update on 9/24: element size is changed to long,
 * to distinguish array index easily
 * in struct Node, item -> key, Node -> LHNode
 * Update on 9/25: file reading is moved to a function readkeys_textfile()
 */
int main()
{
  int i, numElements;
  struct LHNode *head;

  /* for file name, max length 1023 including path */
  char infile[1024], outfile[1024];
  int method;	// which sorting method

  // required for mergesort
  struct LHNode **H;

#ifdef MEASURE_TIME
  clock_t start, end;
  double cpu_time_used;
#endif

  /* file name given by keyboard */
  printf("Input file name? ");
  scanf("%s",infile);
  printf("Output file name? ");
  scanf("%s",outfile);

  printf("Method (1: insertion, 2: merge)? ");
  scanf("%d",&method);

#ifdef MEASURE_TIME
  start = clock();
#endif

  /* read text file of integers:
   * number_of_intergers integer1 integer2 ...
   * then convert it to a linked list */
  head = readkeys_textfile_linkedlist(infile, &numElements);

  if ( head != NULL ) {
    // print all if not too many
    if ( numElements < 100 )	// GJ: comment out this line to always display
    {
      traverse_print_random_item(head);
      printf("%d Loaded\n", numElements);
    }

    switch ( method ) {
      case 1:	// insertion sort
	head = list_insertion_sort(head);
	break;
      case 2:	// merge sort
	// change linked list to individual list items,
	// and save their pointers to an array of LHNode* types
	H = (struct LHNode**) malloc(sizeof(struct LHNode*)*numElements);
	for (i=0; i<numElements; i++, head=head->next) H[i] = head;

	// have to isolate list items later
	for (i=0; i<numElements; i++) H[i]->next=NULL;

	head = list_array_merge_sort(H,numElements);
	break;
      default:
	break;
    }

    // print out results, if not too many
    if ( numElements < 100 )	// GJ: comment out this line to always display
      traverse_print_random_item(head);

    // save results
    savekeys_textfile_linkedlist(outfile, head, numElements);

    // once allocated, should be freed after use
    free_list_iterative(head);
  }

#ifdef MEASURE_TIME
  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("TIME %.5f seconds\n",cpu_time_used);
#endif

  return 0;
}
