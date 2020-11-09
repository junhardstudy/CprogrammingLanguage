#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	struct q_elements* start;
	struct q_elements* end;
	int size;
}queue;

typedef struct {
	int* vertex;
	int* next;
}q_elements;

typedef struct {
	int** adj_matrix;
	struct adj_list* vertex_list;
	int* flag;
}graph;

typedef struct {
	struct s_element* top;
	int size;
}stack;

typedef struct {
	int* vertex;
	struct s_element* next;
}s_element;

typedef struct {
	struct adj_list* next_vertex;
	int* vertex;
	void* data;
	struct arc* Arc;
	int flag;
	int weight;
}adj_list;

typedef struct {
	struct vertex* first;
}adj_list_graph;
//////////////////////////////////////////////////////////////////////
typedef struct {
	int count;
	struct Vtx* first;

}GRAPH;

typedef struct {
	struct Vtx* next;
	void* data;
	int indegree;
	int outdegree;
	short flag;
	struct Arc* arc;
}Vtx;

typedef struct{
	struct Vtx* destination;
	struct Arc* nextArc;
	int weight;
}Arc;

typedef struct {
	struct STACK_element* top;
	int size;
}STACK;

typedef struct {
	void* next;
	void* data;
}STACK_element;

typedef struct {
	struct QUEUE_element* first;
	struct QUEUE_element* end;
	int size;

}QUEUE;

typedef struct {
	void* next;
	void* data;
}QUEUE_element;

typedef struct {
	void** vertex;//vertex들은 배열로 간주
	int number_of_vertex;
}MST;

typedef struct {
	void* first_vertex;
	void* second_vertex;
}VA;


int** make_adj_matrix();
void enqueue(queue* q, int vertex);
int dequeue(queue* q);
void print_BFT(graph* g1, int vertex);
void print_DFT(graph* g1, int vertex);
int pop(stack* s);
void push(stack* s, int vertex);
void make_adj_list(adj_list* adl, int** adj_matrix);
GRAPH* make_adj_list_graph(int vertexNumber, int, char*);
void* DEQ(QUEUE* q);
void ENQ(QUEUE* q, void* data);
void print_BFT_list(GRAPH* g, int vertex);
void print_DFT_list(adj_list* g2, int vertex);
void PUSH_stack(STACK* s, void* data);
void* POP_stack(STACK* s);

void* prim_algo(void* graph, int VtxNumber);

int main() {
	FILE* fp;
	int count = 0;
	int i, j, k, l;
	char first[1];
	char second[1];
	fp = fopen("input.txt", "r");
	//input으로 첫번째는 vertex의 개수를 나타냅니다.
	//
	int starting;
	int** adj_matrix;
	char space;
	char tmp;
	int total;
	char* tmp_str;
	int** test;
	adj_list* adj_test;
	graph* g1;
	graph* g3;
	adj_list* g2;
	GRAPH* test_gr = NULL;
	GRAPH* g5 = NULL;
	Vtx* read_test;


	g1 = (graph*)malloc(sizeof(graph));
	g3 = (graph*)malloc(sizeof(graph));
	g1->flag = (int*)malloc(sizeof(int) * 8);
	g2 = (adj_list*)malloc(sizeof(adj_list) * 8);
	g3->flag = (int*)malloc(sizeof(int) * 8);


	for (i = 0; i < 8; i++) {
		g1->flag[i] = 0;//flag 초기화
		(g2+i)->flag = 0;
		g3->flag[i] = 0;
	}
	g3->vertex_list = (adj_list*)malloc(sizeof(adj_list) * 8);
	
	
	
	adj_matrix = make_adj_matrix();
	g1->adj_matrix = adj_matrix;

	
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++)printf("%d ",g1->adj_matrix[i][j]);
		printf("\n");
	}
	printf("\n\n");


	test_gr = make_adj_list_graph(8, 0, "input.txt");
	printf("\n\n");
	printf("breadth first traverse(using adjancy_matrix) : ");
	print_BFT(g1, 0);//0은 A부터 시작합니다.(B = 1, C =2 ...)
	printf("\n");
	for (i = 0; i < 8; i++)g1->flag[i] = 0;//방문 끝나면 다시 flag 초기화
	printf("depth first traverse(using adjancy_matrix) : ");
	print_DFT(g1, 0);
	printf("\n");
	for (i = 0; i < 8; i++)g1->flag[i] = 0;
	printf("\n");
	
	printf("breadth first traverse(using adjancy_list) : ");
	print_BFT_list(test_gr, 0);
	printf("\n");
	printf("depth first traverse(using adjancy_list) : ");
	print_DFT_list(test_gr, 0);
	printf("\n\n");
	
	
	/*************************************************************************
	3~4번 문제 시작
	*************************************************************************/

	//g5 = make_adj_list_graph(6, 1, "input_weighted.txt");
	g5 = make_adj_list_graph(6, 1, "input_weighted.txt");
	printf("\n\n");
	printf("Minimum spanning tree\n\n");
	prim_algo(g5, 6);
	

	return 7;
}

int** make_adj_matrix() {
	FILE* fp;
	fp = fopen("input.txt", "r");
	int** adj_matrix;
	int** read_matrix;
	int number_of_vertex;
	char space;
	char tmp;
	int i, j, k, l, count;

	fscanf(fp, "%d", &number_of_vertex);
	fscanf(fp, "%c", &space);
	

	read_matrix = (int**)malloc(sizeof(int) * 9);
	adj_matrix = (int**)malloc(sizeof(int)*number_of_vertex);
	for (i = 0; i < 9; i++) 
		*(read_matrix + i) = (int**)malloc(sizeof(int) * 2);

	for (i = 0; i < number_of_vertex; i++) 
		*(adj_matrix + i) = (int*)malloc(sizeof(int) * number_of_vertex);
	
	for (i = 0; i < number_of_vertex; i++) {
		for (j = 0; j < number_of_vertex; j++)adj_matrix[i][j] = 0;
	}

	i = 0;
	j = 0;
	while (!feof(fp)) {
		fscanf(fp, "%c", &tmp);
		read_matrix[i][j] = tmp - 'A';
		j++;
		fscanf(fp, "%c", &space);
		fscanf(fp, "%c", &tmp);
		read_matrix[i][j] = tmp - 'A';
		fscanf(fp, "%c", &space);

		i++;
		j = 0;
	}
	
	for (count = 0, i = 0, j = 0, k = 0, l = 0; count < number_of_vertex; count++) {
		i = read_matrix[k][l];
		l++;
		j = read_matrix[k][l];

		adj_matrix[i][j] = 1;
		l = 0;
		k++;
		
	
	}
	free(read_matrix);
	fclose(fp);
	


	return adj_matrix;
}

void print_BFT(graph* g1, int vertex) {
	queue* q1;
	q1 = (queue*)malloc(sizeof(queue));
	int i = 0;
	q1->start = NULL;
	q1->end = NULL;
	q1->size = 0;

	enqueue(q1, vertex);
	printf("%c ", vertex + 'A');

	while (q1->size != 0) {
	
		vertex = dequeue(q1);
		
		for (i = vertex; i < 8; i++) {
			if (g1->flag[i] == 0 && g1->adj_matrix[vertex][i] == 1) {
				g1->flag[i] = 1;
				enqueue(q1, i);
				printf("%c ", i + 'A');
			}
		}

	}

}
void print_DFT(graph* g1, int vertex) {
	int i = 0;
	stack* s1;
	s1 = (stack*)malloc(sizeof(stack));
	s1->size = 0;
	s1->top = NULL;

	push(s1, vertex);
	

	while(s1->size !=0){
		
		vertex = pop(s1);
		printf("%c ", vertex + 'A');
		for (i = 0; i < 8; i++) {
			if (g1->flag[i] == 0 && g1->adj_matrix[vertex][i] == 1) {
				g1->flag[i] = 1;
				push(s1, i);
			}
		}
	}
	
}

void enqueue(queue* q, int vertex) {
	q_elements* tmp;
	q_elements* read;
	tmp = (q_elements*)malloc(sizeof(q_elements));
	tmp->vertex = (int*)malloc(sizeof(int));
	*(tmp->vertex) = vertex;
	tmp->next = NULL;
	if (q->start == NULL) {
		q->start = tmp;
		q->end = tmp;
		++(q->size);

	}
	else {
		read = q->end;
		read->next = tmp;
		q->end = tmp;
		++(q->size);
		
	}
}

int dequeue(queue* q) {
	int tmp_value;
	q_elements* tmp;
	if (q->size == 0)return NULL;
	else {
		tmp = q->start;
		tmp_value = *(tmp->vertex);
		q->start = tmp->next;
		free(tmp);
		--(q->size);
	}
	return tmp_value;
}

void push(stack* s, int vertex) {
	s_element* tmp;
	tmp = (s_element*)malloc(sizeof(s_element));
	tmp->vertex = (int*)malloc(sizeof(int));
	*(tmp->vertex) = vertex;
	tmp->next = NULL;

	if (s->size == 0) {
		s->top = tmp;
		++(s->size);
	}
	else {
		tmp->next = s->top;
		s->top = tmp;
		++(s->size);
	}
}

int pop(stack* s) {
	s_element* read;
	int value;
	if (s->top == NULL)return -1;
	
	read = s->top;
	if (s->size == 1) {
		read = s->top;
		value = *(read->vertex);
		free(s->top);
		s->top = NULL;
		(s->size) = 0;
	}
	else {
		read = s->top;
		value = *(read->vertex);
		s->top = read->next;
		free(read);
		(s->size)--;
	}
	return value;
}


//과제에서 내줫을때는 8개가 vertex로 가야함.
GRAPH* make_adj_list_graph(int vertexNumber, int exists_weight, char* file_name) {
	//undirected graph 형성
	//exists_weight == 0 이면, 가중치가 없는 그래프
	//exists_weight == 1 이면, 가중치가 있는 그래프
	GRAPH* g;
	Vtx* ver_tmp;
	Vtx* first_ver_tmp;
	Vtx* second_ver_tmp;
	Arc* only_read;
	Arc* arc_tmp;
	char get[5];
	char* data_tmp;
	char space[1];
	FILE* fp;
	int i, j, k, count;
	int weight;

	fp = fopen(file_name, "r");
	g = (GRAPH*)malloc(sizeof(GRAPH));
	ver_tmp = (Vtx*)malloc(sizeof(Vtx) * vertexNumber);
	for (i = 0; i < vertexNumber; i++) {
		(ver_tmp + i)->next = NULL;
		data_tmp = (char*)malloc(sizeof(char));
		*data_tmp = 'A' + i;
		(ver_tmp + i)->data = data_tmp;
		(ver_tmp + i)->indegree = 0;
		(ver_tmp + i)->outdegree = 0;
		(ver_tmp + i)->flag = 0;
		(ver_tmp + i)->arc = NULL;
	}//node, 즉 vertex를 vertex개수만큼 생성합니다.
	g->first = ver_tmp;

	//
	/*
	for (i = 0; i < vertexNumber; i++) {
		data_tmp = (ver_tmp + i)->data;
		printf("%d번째 %c\n", i + 1, *data_tmp);
	}
	*/
	//


	fgets(get, sizeof(get), fp);
	
	while (!feof(fp)) {
		fgets(get, sizeof(get), fp);
		i = get[0] - 'A';
		j = get[2] - 'A';
		if (exists_weight == 1) {
			fscanf(fp, "%d", &weight);
			fscanf(fp, "%c", &space);
		}
	
		
		first_ver_tmp = (ver_tmp + i);
		second_ver_tmp = (ver_tmp + j);
		if (first_ver_tmp->arc == NULL) {
			arc_tmp = (Arc*)malloc(sizeof(Arc));
			arc_tmp->destination = second_ver_tmp;
			arc_tmp->nextArc = NULL;
			if (exists_weight == 1)arc_tmp->weight = weight;
			first_ver_tmp->arc = arc_tmp;
		}
		else {
			//printf("done?\n\n");
			only_read = first_ver_tmp->arc;
			while (only_read->nextArc != NULL) {
				only_read = only_read->nextArc;
			}
			arc_tmp = (Arc*)malloc(sizeof(Arc));
			arc_tmp->destination = second_ver_tmp;
			arc_tmp->nextArc = NULL;
			if (exists_weight == 1)arc_tmp->weight = weight;
			only_read->nextArc = arc_tmp;
		}
		(first_ver_tmp->outdegree)++;
		
	}
	g->first = ver_tmp;
	
	//
	for (i = 0; i < vertexNumber; i++) {
		data_tmp = (ver_tmp + i)->data;
		printf("%d번째(괄호는 가중치) %c", i + 1, *data_tmp);
		first_ver_tmp = ver_tmp + i;
		if (first_ver_tmp->arc != NULL) {
			only_read = first_ver_tmp->arc;
			while (only_read != NULL) {
				second_ver_tmp = only_read->destination;
				data_tmp = second_ver_tmp->data;
				printf("-%c", *data_tmp);
				if (exists_weight == 1)printf("(%d)", only_read->weight);
				only_read = only_read->nextArc;
			}
			
		}
		printf("\n");
		
	}

	//
	fclose(fp);
	return g;
}


/*
	QUEUE_element의 data는 vertex의 addr를 값으로 가집니다.
	
*/

void ENQ(QUEUE* q, void* data){
	QUEUE_element* tmp;
	QUEUE_element* read;
	tmp = (QUEUE_element*)malloc(sizeof(QUEUE_element));
	tmp->data = data;
	tmp->next = NULL;

	if (q->first == NULL && q->end == NULL) {
		q->first = tmp;
		q->end = tmp;
		q->size = 1;
	}
	else {
		read = q->end;
		read->next = tmp;
		q->end = tmp;
		++(q->size);
	}
	
}

void* DEQ(QUEUE* q) {
	void* tmp, * tmp2;


	if (q->first == NULL)return NULL;

	if (q->size == 1) {
		tmp = q->first;
		tmp = ((QUEUE_element*)tmp)->data;
		free(q->first);
		q->first = NULL;
		q->end = NULL;
		q->size = 0;
	}
	else {
		tmp = q->first;
		tmp = ((QUEUE_element*)tmp)->data;//vertex
		tmp2 = q->first;
		tmp2 = ((QUEUE_element*)tmp2)->next;
		free(q->first);
		q->first = tmp2;
		--(q->size);
	}
	return tmp;
}


void print_BFT_list(GRAPH* g, int vertex) {
	int i, j, k;
	QUEUE* q;
	char* read;
	Arc* arc_tmp;
	Vtx* tmp = g->first;//개개의 vertex는 행렬로 생각하면 됨.
	q = (QUEUE*)malloc(sizeof(QUEUE));
	q->end = NULL;
	q->first = NULL;
	
	//vertex자체를 큐에 저장
	ENQ(q, (tmp + vertex));
	(tmp + vertex)->flag = 1;
	
	while (q->size != 0) {
		tmp = DEQ(q);//vertex자체를 return
		read = tmp->data;
		printf("%c ", *read);
	
		arc_tmp = tmp->arc;
		while (arc_tmp != NULL) {//arc 간선에 연결되어있는 노드, or vertex를 큐에 저장
			tmp = arc_tmp->destination;
			if (tmp->flag == 1) {
				arc_tmp = arc_tmp->nextArc;
				continue;
			}
			ENQ(q, arc_tmp->destination);
			tmp->flag = 1;
			arc_tmp = arc_tmp->nextArc;
		}
	}

	tmp = g->first;
	for (i = 0; i < 8; i++) {
		(tmp + i)->flag = 0;
	}//출력이 끝나면 다시 flag 초기화
	
	
}

void print_DFT_list(GRAPH* g, int vertex) {
	//pop 하고 난 다음에 바로 출력
	int i;
	Vtx* tmp;
	Arc* arc_tmp;
	STACK* s;
	char* tmp_str;
	s = (STACK*)malloc(sizeof(STACK));
	s->size = 0;
	s->top = NULL;
	tmp = g->first;
	tmp = tmp + vertex;
	PUSH_stack(s, tmp);//vertex자체가 stack에 들어가야함.
	tmp->flag = 1;
	while (s->size != 0) {
		tmp = POP_stack(s);
		tmp_str = tmp->data;
		printf("%c ", *tmp_str);
		tmp->flag = 1;
		//arc, 간선 개수만큼 vertex를 stack 저장
		//이미 access 한적있으면 flag == 1 조건으로 점프
		arc_tmp = tmp->arc;
		while (arc_tmp != NULL) {
			tmp = arc_tmp->destination;
			if (tmp->flag == 1) {
				arc_tmp = arc_tmp->nextArc;
				continue;
			}
			
			PUSH_stack(s, tmp);
			tmp->flag = 1;
			arc_tmp = arc_tmp->nextArc;
		}
	}

	tmp = g->first;
	for (i = 0; i < 8; i++) {
		(tmp + i)->flag = 0;
	}//출력이 끝나면 다시 flag 초기화

}

void PUSH_stack(STACK* s, void* data) {//vertex(Vtx라 명심해놨음) address를 data로
	STACK_element* tmp;
	STACK_element* prev;
	tmp = (STACK_element*)malloc(sizeof(STACK_element));
	tmp->data = data;
	tmp->next = NULL;

	if (s->size == 0) {
		s->top = tmp;
	}
	else {
		tmp->next = s->top;
		s->top = tmp;

	}
	++(s->size);
}


void* POP_stack(STACK* s) {//vertx address를 return
	STACK_element* tmp;
	void* tmp_data;
	if (s->size == 0)return NULL;

	tmp = s->top;
	tmp_data = tmp->data;
	s->top = tmp->next;
	free(tmp);
	--(s->size);
	return tmp_data;
}

/***********************************************************************

prim algorithm
arc의 weight값 기준으로 최저값 찾음
이 때 vertex의 flag가 0이면(flag가 1이면 연결되어있음)
해당 vertex와 연결되어있는데 arc선택해서

minimum spanning tree 집합으로 옮김
옮긴 vertex의 flag는 1로.

최소 arc는 minimum spanning tree집합에 속해있는 원소(vertex들로부터 찾음)


***********************************************************************/

void* prim_algo(void* graph, int VtxNumber) {
	//graph는 vertex를 참조할수 있는 어떠한 자료형들로 이루어져있으면 됨
	//여기선 인접 리스트로 이루어진 그래프가 argument로....
	//참조할때는 graph->first가 'A' vertex를 가르킴
	//graph->first[1]은 'B' vertex
	int count;
	int min_tmp;
	Vtx* min_vertex;
	Vtx* from_vertex;
	Vtx* read;
	Vtx* access;
	Vtx* access2;
	Vtx* destination;
	MST* mst1;
	Arc* arc_tmp;
	Arc* min_arc;
	VA* va_read;
	VA* vertex_with_arc;
	char* str_tmp;
	int i;
	int total = 0;


	Vtx* test;
	char* test_str;
	mst1 = (MST*)malloc(sizeof(MST));
	mst1->vertex = (Vtx**)malloc(sizeof(Vtx)*VtxNumber);
	vertex_with_arc = (VA*)malloc(sizeof(VA)*(VtxNumber -1 ));
	mst1->number_of_vertex = 0;
	
	read = ((GRAPH*)graph)->first;

	*(mst1->vertex) = read;
	++(mst1->number_of_vertex);
	read->flag = 1;

	while (mst1->number_of_vertex < VtxNumber) {
		count = 0;
		min_tmp = 999999; 
		from_vertex = NULL;

		//MST에서 최저 weight를 가진 arc와 연결된 vertex(아직 연결되지 않은) 찾기
		while (count < mst1->number_of_vertex) {
			read = *(mst1->vertex + count);
			arc_tmp = read->arc;
			
			//destination = arc_tmp->destination;
			while (arc_tmp != NULL) {
				destination = arc_tmp->destination;
				if (arc_tmp->weight < min_tmp && destination->flag == 0) {
					min_tmp = arc_tmp->weight;
					min_arc = arc_tmp;
					from_vertex = read;
				}
				arc_tmp = arc_tmp->nextArc;
				
				
			}
			count++;
		}
		*(mst1->vertex + count) = min_arc->destination;

		test = from_vertex;
		test_str = test->data;
		printf("%c-",*test_str);

		test = min_arc->destination;
		test_str = test->data;
		printf("%c\n", *test_str);

		access = min_arc->destination;
		access->flag = 1;
		
		access = *(mst1->vertex +(count - 1));

		access = from_vertex;
	

		
		
		
		++(mst1->number_of_vertex);
		
	}

	
	

	
}


