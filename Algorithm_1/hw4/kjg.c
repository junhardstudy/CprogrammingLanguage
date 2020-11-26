#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	float benefit;
	int weight;
}item;

typedef struct {
	float benefit;
	float weight;
}new_item;




void** make_matrix(int*, int*);
void** problem_1(item* food, float** matrix, int knap_weight, int count);
int* find_item(int** matrix, int knap_weight, int count, item* food);
void problem_2(float**, int knap_weight, int count);
void problem_3(float**, int knap_weight, int count);

int main() {
	float** matrix;//DP���� ���� ������ ���̺��� matrix�� ����
	int* knap_weight;
	int* count;
	int* tmp;
	int i, j, k;
	item* food = NULL;
	knap_weight = (int*)malloc(sizeof(int));
	count = (int*)malloc(sizeof(int));
	*knap_weight = 0;
	*count = 0;

	matrix = make_matrix(knap_weight, count);
	problem_2(matrix, *knap_weight, *count);
	problem_3(matrix, *knap_weight, *count);

	return 0;
}

void** make_matrix(int* knap_weight, int* count) {
	float** B;
	int i, j = 0;
	int tmp_num;
	int weight;
	item* food;
	item tmp_food[100];
	FILE* fp;
	char tmp[5];
	fp = fopen("input.txt", "r");

	while (!feof(fp)) {
		fscanf(fp, "%d %d", &weight, &i);
		(*count)++;
		if (i == -1)break;
		tmp_food[j].benefit = (float)i;
		tmp_food[j].weight = weight;

		j++;

	}


	food = (item*)malloc(sizeof(int) * (*count));//count�� �ƴ� count + 1�� 3��° ������ duplicated���������� Ȱ���ϱ� ����
	B = (float**)malloc(sizeof(float*) * ((*count) + 1));
	for (i = 0; i <= *count; i++) {
		*(B + i) = (float*)malloc(sizeof(float) * ((weight)+1));//�� row, ����w ����

	}

	*knap_weight = weight;

	for (i = 0; i < *count - 1; i++) {
		(food + i)->benefit = tmp_food[i].benefit;
		(food + i)->weight = tmp_food[i].weight;
	}
	fclose(fp);

	fp = fopen("input.txt", "r");



	fclose(fp);







	for (i = 0; i <= *count; i++) {
		B[i][0] = 0.0;
	}
	for (i = 0; i <= *knap_weight; i++) {
		B[0][i] = 0.0;
	}

	fclose(fp);

	printf("\n");
	*count = *count - 1;

	B = problem_1(food, B, *knap_weight, *count);



	return B;



}

void** problem_1(item* food, float** matrix, int knap_weight, int count) {
	/***********************

	count�� ������ �����Դϴ�.
	matrix[��][��]

	************************/
	int i, w, k, j;


	for (i = 1; i <= count; i++) {//��
		for (w = 1; w <= knap_weight; w++) {//��
			if ((food + i - 1)->weight <= w) {
				if ((food + i - 1)->benefit + matrix[i - 1][w - (food + i - 1)->weight] > matrix[i - 1][w]) {
					matrix[i][w] = (food + i - 1)->benefit + matrix[i - 1][w - (food + i - 1)->weight];
				}
				else {
					matrix[i][w] = matrix[i - 1][w];
				}
			}
			else {
				matrix[i][w] = matrix[i - 1][w];
			}
		}

	}


	find_item(matrix, knap_weight, count, food);
	return matrix;
}

int* find_item(float** matrix, int knap_weight, int count, item* food) {
	/***********************************

		DP table�� ���� knapsack_problem�� �����ϴ�
		���� ����(item)���� ã����

	************************************/
	int* item_basket;//�賶�� ���� ����(index)�� ����� �־���
	int i, j, k, w, item_number;
	i = count;
	w = knap_weight;
	item_number = 0;
	item_basket = (int*)malloc(sizeof(int) * count);

	while (w != 0 || i != 0) {
		if (matrix[i][w] == matrix[i - 1][w]) {//������ �� ���� ���
			i = i - 1;
		}
		else {
			*(item_basket + item_number) = i;
			w = w - (food + i - 1)->weight;
			i = i - 1;
			item_number++;

		}

		if (matrix[i][w] == 0.0)break;

	}

	*(item_basket + item_number) = -1;
	printf("Output : \n");
	for (i = item_number - 1; i >= 0; i--) {
		printf("%d ", *(item_basket + i));
	}
	printf("%d\n", (int)matrix[count][knap_weight]);

	return item_basket;
}


void problem_2(float** matrix, int knap_weight, int count) {
	/**********************************************************
		(0 <= k <= n)
		knap_weight = knap_weight - ������ ������ ���� ������ ����(��, �ݿø� �Ǽ� ������)
		count = count - 1;
		-> item* bread[k]��°�� �����ϰ� DP table�� ����
		-> matrix[knap_weight][count]�̶� ������ ������ ���� ������ �հ谡 ���� ū�� ä��


	**********************************************************/

	int i, j, k, w, bi, wi;
	float tmp_max;
	int flag = 0;
	int tmp_index;
	int tmp_weight;
	int target_index;
	int halfed_index;
	int item_basket[10000];
	int answer[10000];
	new_item* original;
	FILE* fp;
	new_item tmp_toy;
	original = (new_item*)malloc(sizeof(new_item) * count);
	fp = fopen("input.txt", "r");
	for (i = 0; i < count; i++) {
		fscanf(fp, "%f %f", &(original[i].weight), &(original[i].benefit));
	}
	fclose(fp);
	target_index = 0;
	tmp_max = 0.0;
	while (1) {
		if (target_index > count - 1)break;
		tmp_weight = (int)(original[target_index].weight / 2.0 + 0.5);// �ݿø� ���ֱ�
		tmp_weight = knap_weight - tmp_weight;
	


		w = tmp_weight;



		for (i = 1, k = 0; i <= count - 1; i++, k++) {//��
			if (k == target_index)k++;//������ ���� ������ ������� ����.

			//printf("k = %d, i = %d\n", k, i);
			wi = original[k].weight;
			for (w = 1; w <= tmp_weight; w++) {//��

				if (wi <= w) {
					bi = original[k].benefit + matrix[i - 1][w - wi];

					if (bi > matrix[i - 1][w]) {
						matrix[i][w] = bi;
					}
					else {
						matrix[i][w] = matrix[i - 1][w];
					}
				}
				else {
					matrix[i][w] = matrix[i - 1][w];
				}
			}

		}
		/*
		for (i = 0; i <= tmp_weight; i++) {
			for (j = 0; j <= count - 1; j++)printf("%2f ", matrix[j][i]);
			printf("\n");
		}
		*/
		i = tmp_weight + 1;
		j = count;
		if (tmp_max < matrix[j - 1][i - 1] + (original[target_index].benefit) / 2.0) {
			tmp_max = matrix[j - 1][i - 1] + (original[target_index].benefit) / 2.0;
			halfed_index = target_index;
			w = tmp_weight;
			i = count - 1;
			tmp_index = 0;

			k = i + 1;
		

			while (w > 0 || i != 0) {
				k--;
	

				if (matrix[i][w] == matrix[i - 1][w]) {//������ �� ���� ���
					i = i - 1;
				}
				else {
				
					if (target_index < k)  item_basket[tmp_index] = k + 1;
					else item_basket[tmp_index] = k;


					w = w - original[k].weight;
					i = i - 1;
					tmp_index++;



				}
	
				if (i == 0)break;
				if (matrix[i][w] == 0.0)break;


			}

		}



		target_index++;
	}
	printf("Output : \n");
	halfed_index = halfed_index + 1;
	for (i = tmp_index - 1; i >= 0; i--) {
		if (halfed_index < item_basket[i] && flag == 0) {
			printf("%d*0.5 %d ", halfed_index, item_basket[i]);
			flag = 1;
		}
		else {
			printf("%d ", item_basket[i]);
		}
	}

	printf("%.1f\n", tmp_max);

}


void problem_3(float** matrix, int knap_weight, int count) {
	int weight, i, j, duplicated_index, w, bi, wi;
	int k;
	int tmp_index;
	int tmp_minus;
	int doubled_index;
	int* tmp_basket;
	item* toy;
	item* duplicated;
	float tmp_max;

	FILE* fp;
	tmp_basket = (int*)malloc(sizeof(int) * count);
	duplicated = (item*)malloc(sizeof(item) * (count + 1));
	toy = (item*)malloc(sizeof(item) * (count + 1));

	fp = fopen("input.txt", "r");
	j = 0;

	for (j = 0; j < count; j++) {
		fscanf(fp, "%d %d", &wi, &bi);
		if (bi == -1)break;
		(duplicated + j)->benefit = bi;
		(duplicated + j)->weight = wi;

	}

	
	tmp_max = matrix[count][knap_weight];
	duplicated_index = 1;
	doubled_index = 1;

	while (1) {
	

		/************************************

		step1. dp table �����

		*************************************/

		for (i = 1, k = 1; i <= count + 1; i++) {//��

			
			wi = (duplicated + k - 1)->weight;
			for (w = 1; w <= knap_weight; w++) {//��

				if (wi <= w) {
					bi = (duplicated + k - 1)->benefit + matrix[i - 1][w - wi];

					if (bi > matrix[i - 1][w]) {
						matrix[i][w] = bi;
					}
					else {
						matrix[i][w] = matrix[i - 1][w];
					}
				}
				else {
					matrix[i][w] = matrix[i - 1][w];
				}
			}
			if (i != duplicated_index)k++;
		}
		

		/**************************************

			step2. ���ؼ� ���� dp table�� B[count][knap_weight]�� �ִ� benefit
				   ���� ũ�� ���� �ƴϸ� �����ϰ� ���� ��ƾ

		**************************************/
	
		if (tmp_max < matrix[count + 1][knap_weight]) {
			doubled_index = duplicated_index;
			tmp_max = matrix[count + 1][knap_weight];
			w = knap_weight;
			i = count + 1;
			tmp_index = 0;
		
			k = i;
			while (w > 0 || i != 0) {
				k--;
		

				if (matrix[i][w] == matrix[i - 1][w]) {//������ �� ���� ���
					i = i - 1;
				}
				else {
				
					if (k == doubled_index) {
						*(tmp_basket + tmp_index) = k;
						*(tmp_basket + tmp_index + 1) = k;
						tmp_index++;
					}
					else {
						*(tmp_basket + tmp_index) = k;
					}
					w = w - (duplicated + k - 1)->weight;
					i = i - 1;
					tmp_index++;



				}
		
				if (i == 0)break;
				if (matrix[i][w] == 0.0)break;


			}

		}


		duplicated_index++;
		if (duplicated_index > count)break;
	}
	i = 0;
	doubled_index = 0;
	tmp_minus = 0;

	while (i < tmp_index - 1) {
		if (*(tmp_basket + i) == *(tmp_basket + i + 1)) {
			doubled_index = i + 1;
		}
		i++;
	}//2��� index ã��
	printf("Output : \n");
	for (j = tmp_index - 2; j >= 0; j--) {
		if (j > 0 && tmp_basket[j] == tmp_basket[j - 1]) {
			printf("%dx2 ", tmp_basket[j]);
			j--;
		}
		else {
			printf("%d ", *(tmp_basket + j));
		}
	}
	/*
	for (j = tmp_index - 1; j >= 0; j--) {
		if (doubled_index == j) {
			printf("%dx2 ", *(tmp_basket + j));
			j--;//�ѹ� �ǳ� ���
			tmp_minus = 1;

		}
		else {
			printf("%d ", *(tmp_basket + j) - tmp_minus);
		}

	}
	*/
	printf("%d\n", (int)tmp_max);
	printf("\n");
	//printf("probelm3 : %d\n", (int)tmp_max);
	//printf("doubled index : %d\n", doubled_index);
}
