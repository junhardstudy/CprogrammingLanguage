#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_table 10000

/**************************************************************************

	hashing의 경우 "(정수 * 2exp(2))/해쉬 테이블 최대 크기" 입니다.
	collision의 경우 linked_list를 이용한 chaining으로 해결 하였습니다.

**************************************************************************/
typedef struct {
	int key;
	struct hash* next;
}hash;

typedef struct {
	int value;
	struct hash_elements* next;
}hash_elements;

void print_data(void* data, int number);
void* make_rand_arr_data(int number);
void selection_sort(void* data, int number);
void insertion_sort(void* data, int number);
void bubble_sort(void* data, int number);
void delete_data(void* data, int number);
void merge_sort(void* sorted, void* data, int first, int last);
void merge(int* sorted, int* data, int left, int right);
void merge_sort(void* sorted, void* data, int left, int right);
void copy_data(void* original, void* duplicated, int number);
int partition(int* data, int left, int right);
void quick_sort(int* data, int left, int right);
void bin_search(int* data, int number, int target_data);
void hash_problem(int* data, int num);
void find_item(hash_elements* table, int data);
void push_hash(hash_elements* table, int* data);


void main() {
	int* arr;
	int* sorted;
	int* duplicated_data;
	int* for_search;
	int target_data;
	int num = 100 + rand()%51;
	sorted = (int*)malloc(sizeof(int) * num);
	duplicated_data = (int*)malloc(sizeof(int) * num);

	//problem1. binary, and hash search
	for_search = make_rand_arr_data(num);

	printf("\n===================bineary search=====================\n");
	printf("current data : ");
	print_data(for_search, num);
	printf("plz enter th number for search(using binary search) : ");
	scanf("%d", &target_data);
	quick_sort(for_search, 0, num - 1);
	bin_search(for_search, num, target_data);

	printf("\n===================hash search=====================\n");
	delete_data(for_search, num);
	for_search = make_rand_arr_data(num);
	printf("current data : ");
	print_data(for_search, num);
	hash_problem(for_search, num);
	delete_data(for_search, num);


	//problem2.insertion, selection, bubble, merge, and quick sort
	arr = make_rand_arr_data(num);
	selection_sort(arr, num);
	printf("\n");
	insertion_sort(arr, num);
	printf("\n");
	bubble_sort(arr, num);
	printf("\n");

	printf("=========Merge Sort============\n");
	copy_data(arr, duplicated_data, num);
	printf("before sort : ");
	print_data(duplicated_data, num);
	merge_sort(sorted, duplicated_data, 0, num - 1);
	printf("after sort : ");
	print_data(duplicated_data, num);

	printf("=========Merge Sort============\n");
	copy_data(arr, duplicated_data, num);
	printf("before sort : ");
	print_data(duplicated_data, num);
	quick_sort(duplicated_data, 0, num - 1);
	printf("after sort : ");
	print_data(duplicated_data, num);

}
void copy_data(void* original, void* duplicated, int number) {
	memcpy(duplicated, original, sizeof(original) * number);
}

void* make_rand_arr_data(int number) {
	int* arr;
	int i;
	arr = (int*)malloc(sizeof(int) * number);
	srand((unsigned)time(NULL));

	for (i = 0; i < number; i++) {
		arr[i] = rand() % 100 + 1;
	}
	return arr;

}

void print_data(void* data, int number) {
	int i;
	int* read;
	read = (int*)data;
	for (i = 0; i < number; i++)printf("%d ", read[i]);
	printf("\n");
}

void hash_problem(int* data, int num) {//num은 데이터 개수
	hash_elements* table;
	int i, j, k;
	int keyboard_sel;
	table = (hash_elements*)malloc(sizeof(hash_elements) * max_table);
	for (i = 0; i < max_table; i++) {
		table[i].value = 0;
		table[i].next = NULL;
	}//table initialize

	for (i = 0; i < num; i++) {
		push_hash(table, &data[i]);
	}
	while (1) {
		printf("검색할 정수를 입력하세요(음수, negative 입력은 종료) : ");
		scanf("%d", &keyboard_sel);
		if (keyboard_sel <= -1)break;
		else find_item(table, keyboard_sel);
	}



}

void find_item(hash_elements* table, int data) {
	int index;
	index = hashing(data);
	if (table[index].value == data)printf("해당 데이터는 존재합니다!\n");
	else printf("해당 데이터는 존재하지 않습니다!\n");
}

void push_hash(hash_elements* table, int* data) {
	int index;
	hash_elements* read;
	hash_elements* new_hash;
	int i, j;
	index = hashing(*data);
	read = table + index;
	if (read->value == *data) {//index가 중복되는 경우, 즉 colision이 발생한 경우
		while (read->next != NULL)read = read->next;
		new_hash = (hash_elements*)malloc(sizeof(hash_elements));
		new_hash->value = *data;
		new_hash->next = NULL;
		read->next = new_hash;
	}
	else {
		table[index].value = *data;

	}
}


int hashing(int data) {
	return (data << 2) % max_table;
}




void selection_sort(void* data, int number) {
	int* dup_data;
	int min_data;
	int min_index;
	int tmp_value;
	int i, j;
	dup_data = (int*)malloc(sizeof(int) * number);
	memcpy(dup_data, data, sizeof(int) * number);
	printf("=========Selection Sort============\n");
	printf("before sort : ");
	print_data(dup_data, number);

	for (i = 0; i < number - 1; i++) {
		min_index = i;
		min_data = dup_data[i];
		for (j = i+ 1; j < number; j++) {
			if (min_data > dup_data[j]) {
				min_data = dup_data[j];
				min_index = j;
			}//최소값, 그에 해당하는 index찾기
		}
		tmp_value = dup_data[i];
		dup_data[i] = dup_data[min_index];
		dup_data[min_index] = tmp_value;
	}//값 교환하기

	printf("after sort : ");
	print_data(dup_data, number);


	delete_data(dup_data, number);
}

void insertion_sort(void* data, int number) {
	int* dup_data;
	int min_data;
	int min_index;
	int tmp_value;
	int i, j;
	dup_data = (int*)malloc(sizeof(int) * number);
	memcpy(dup_data, data, sizeof(int) * number);
	printf("=========Insertion Sort============\n");
	printf("before sort : ");
	print_data(dup_data, number);

	for (i = 0; i < number; i++) {
		tmp_value = dup_data[i];
		min_index = i;
		for (j = i - 1; j >= 0; j--) {
			if (tmp_value > dup_data[j]) {//주)dup_data[i] > dup_data[j] 아님, dup_data[i]는 dup_data[j + 1] = dup_data[j]때문에 바뀜.
				min_index = j + 1;
				break;
			}//넣을 공간 발견
			else {
				dup_data[j + 1] = dup_data[j];//한칸씩 밀기
				min_index = j;
			}
			
		}
		dup_data[min_index] = tmp_value;
	
	}
	printf("after sort : ");
	print_data(dup_data, number);
	delete_data(dup_data, number);
	
}
void bubble_sort(void* data, int number) {
	int* dup_data;
	int min_data;
	int min_index;
	int tmp_value;
	int i, j;
	dup_data = (int*)malloc(sizeof(int) * number);
	memcpy(dup_data, data, sizeof(int) * number);
	printf("============Bubble Sort============\n");
	printf("before sort : ");
	print_data(dup_data, number);

	for (i = 0; i < number - 1; i++) {
		for (j = number - 1; j > i; j--) {
			if (dup_data[j - 1] > dup_data[j]) {
				tmp_value = dup_data[j - 1];
				dup_data[j - 1] = dup_data[j];
				dup_data[j] = tmp_value;
			}//bubble
		}
	}//flow
	printf("after sort : ");
	print_data(dup_data, number);
	delete_data(dup_data, number);
}

void merge_sort(void* sorted, void* data, int left, int right) {

	if (left < right) {//recursion을 중단시킬 조건문
		merge_sort(sorted, data, left, (left + right) / 2);
		merge_sort(sorted, data, (left + right )/ 2 + 1, right);
		merge(sorted, data, left, right);
	}

}
void merge(int* sorted, int* data, int left, int right) {
	int mid;
	int sub_left, sub_right, sorted_index;
	int i, j, k;
	mid = (right + left) / 2;
	sub_left = left;
	sub_right = mid + 1;
	sorted_index = left;


	while (sub_left <= mid && sub_right <= right) {
		if (data[sub_left] < data[sub_right]) {
			sorted[sorted_index++] = data[sub_left++];
		}
		else {
			sorted[sorted_index++] = data[sub_right++];
		}
	}
	if (sub_left <= mid) 
		for(;sub_left<=mid;sub_left++)sorted[sorted_index++] = data[sub_left];

	if(sub_right <= right)
		for(;sub_right<=right;sub_right++)sorted[sorted_index++] = data[sub_right];

	for (i = left; i <= right; i++)data[i] = sorted[i];
	

}

void quick_sort(int* data, int left, int right) {
	int pivot;
	if(left <= right) {
		pivot = partition(data, left, right);
		quick_sort(data, left, pivot - 1);
		quick_sort(data, pivot + 1, right);
	}
}
int partition(int* data, int left, int right) {
	int pivot = left;
	int sub_left;
	int tmp_value;
	int sub_right;
	int target_index;
	target_index = left;
	sub_left = left + 1;
	sub_right = right;

	while (sub_left <= sub_right) {
		while (data[pivot] >= data[sub_left] && sub_left <= right){
			sub_left++;
		}
		while (data[pivot] <= data[sub_right] && sub_right >= (left + 1)){
			sub_right--;
		}
		if (sub_left <= sub_right){
			tmp_value = data[sub_left];
			data[sub_left] = data[sub_right];
			data[sub_right] = tmp_value;
		}
	}
	tmp_value = data[left];
	data[left] = data[sub_right];
	data[sub_right] = tmp_value;
	return sub_right;
}

void bin_search(int* data, int number, int target_data) {
	int left, right, mid;
	left = 0;
	right = number;
	while (left <= right) {
		mid = (right + left) / 2;
		if (data[mid] > target_data) {
			right = mid-1;
		}
		else if (data[mid] < target_data) {
			left = mid + 1;
		}
		else {
			printf("%d데이터가 존재합니다!\n", target_data);
			return;
		}

	}
	printf("data가 존재하지 않습니다!\n");
}


void delete_data(void* data, int number) {
	int i;	
	free((int*)data);
}