#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct {
	int x;
	int y;
	int flag;
	double ang_distance;
}city;

void* input_city_data();
void merge(void* data, int left, int right);
void merge_sort(void* data, int left, int right);
void find_nearest_point(city* point, int initial_point, int end_point, double fuel);
void initialize_flag(city* point);

void main() {
	city* data;
	double total_length = 0.0;
	double tmp_length;
	int i;
	data = input_city_data();



	merge_sort(data, 0, 99);
	find_nearest_point(data, 0, 99, 200.0);
	initialize_flag(data);
	find_nearest_point(data, 0, 99, 400.0);
	initialize_flag(data);
	find_nearest_point(data, 0, 99, 600.0);
	initialize_flag(data);
	find_nearest_point(data, 0, 99, 800.0);
	initialize_flag(data);
	find_nearest_point(data, 0, 99, 1000.0);
	initialize_flag(data);
	find_nearest_point(data, 0, 99, 1500.0);

	

	/****************************
		variation�� ���� �������߿���
		���� ����� ��.
		�߰��Ǹ� flag�� 1��.


		->����
		������ ������ �����ϰ� �� ���� �����߿���
		�Ÿ��� ���� ����� ���� ����
		

		->����
		1. end to end a0(0, 0)-a100(100, 100)�������� ���� �����̿� �ִ� ���ϳ��� ã��, �� ���� a1�̶��ϸ�
		2. ���� a0, a1, a100 �� �̾��� ����
		3. a0�� a1���̿� ���� ª�� ���ϳ��� ã�Ƽ� �������� �ձ�
		4. fuel, ������ �������� �ִٸ� 2������ ���� loop
	****************************/
}
void initialize_flag(city* point) {
	int i;
	for (i = 1; i < 99; i++) {
		point[i].flag = 0;
	}
}

void find_nearest_point(city* point, int initial_point, int end_point, double fuel) {
	int i, j , k;
	int current_point_number;
	int index_set[100] = { -1 };
	int tmp_index = -1;
	double tmp_length;
	double current_length = 0;
	double tmp_current_length = 0;
	double first_length;
	double second_length;
	double tmp_sum_length;
	index_set[0] = 0;
	index_set[1] = 99;
	current_point_number = 2;
	while (1) {
		tmp_length = 999999;
		for (k = 0; k < current_point_number - 1; k++) {
			initial_point = index_set[k];
			end_point = index_set[k + 1];
			
			for (i = 1; i < 99; i++) {
				first_length = sqrt(pow(point[i].x - point[initial_point].x, 2) + pow(point[i].y - point[initial_point].y, 2));
				second_length = sqrt(pow(point[end_point].x - point[i].x, 2) + pow(point[end_point].y - point[i].y, 2));
				tmp_sum_length = first_length + second_length;
			
				if (tmp_sum_length < tmp_length && point[i].flag == 0) {
					tmp_length = tmp_sum_length;
					tmp_index = i;
	
				}
			}
		}
		
		point[tmp_index].flag = 1;

		index_set[current_point_number] = 99;
		for (j = current_point_number - 1; j >= 0; j--) {
			if (index_set[j] < tmp_index) {
				index_set[j + 1] = tmp_index;
				break;
			}
			else {
				index_set[j + 1] = index_set[j];
			}
		}
		
		current_point_number++;
		tmp_current_length = 0;
		for (k = 0; k < current_point_number - 1; k++) {
			tmp_current_length += sqrt(pow(point[index_set[k+1]].x - point[index_set[k]].x, 2) + pow(point[index_set[k + 1]].y - point[index_set[k]].y, 2));
		}
		if (tmp_current_length > fuel) {
			index_set[j] = -1;
			break;
		}
		
		current_length = tmp_current_length;
		
	}
	printf("%.1f %.3f\n", fuel, current_length);
	for (j = 0; j < current_point_number; j++) {
		if (index_set[j] == -1)continue;
		printf("%3d %3d\n", point[index_set[j]].x, point[index_set[j]].y);
	}
	printf("\n\n\n");
}


void merge_sort(void* data, int left, int right) {
	if (left < right) {
		merge_sort(data, left, (right + left) / 2);
		merge_sort(data, (right + left) / 2 + 1, right);
		merge(data, left, right);
	}
}

void merge(void* data, int left, int right) {
	int sub_left, sub_right, mid, target_index, i;
	city* read;
	city tmp_data[100];
	read = (city*)data;
	sub_left = left;
	target_index = left;
	mid = (right + left) / 2;
	sub_right = mid + 1;
	while (sub_left <= mid && sub_right <= right) {
		if (read[sub_left].x < read[sub_right].x) {
			tmp_data[target_index++] = read[sub_left++];
		}
		else {
			tmp_data[target_index++] = read[sub_right++];
		}
	}
	while(sub_left <= mid)tmp_data[target_index++] = read[sub_left++];
	while(sub_right <= right)tmp_data[target_index++] = read[sub_right++];

	for (i = left; i < target_index; i++)read[i] = tmp_data[i];
}

void* input_city_data() {
	city* tmp;
	int tmp_num_x;
	int tmp_num_y;
	int i = 0;
	char tmp_num[100];
	tmp = (city*)malloc(sizeof(city) * 100);//
	FILE* fp;
	fp = fopen("hw5ex1.txt", "r");
	fgets(tmp_num, sizeof(tmp_num), fp);
	fgets(tmp_num, sizeof(tmp_num), fp);

	i = 1;
	tmp[0].x = 0;
	tmp[0].y = 0;
	tmp[0].flag = 1;
	tmp[99].x = 100;
	tmp[99].y = 100;
	tmp[99].flag = 1;
	while (!feof(fp)) {
		fscanf(fp, "%d", &tmp_num_x);
		fscanf(fp, "%d", &tmp_num_y);
		if (tmp_num_x == 100 && tmp_num_y == 100)break;
		tmp[i].x = tmp_num_x;
		tmp[i].y = tmp_num_y;
		tmp[i].flag = 0;
		/*******************************
			��(n��° ����)�� 
			(0,0)���� (100, 100) ���� ������ �Ÿ�
		*******************************/
		tmp[i].ang_distance = abs(1 * tmp[i].x - 1 * tmp[i].y) / sqrt(2);

		if (tmp[i].x == 100)break;
		i++;
	}
	return tmp;

}