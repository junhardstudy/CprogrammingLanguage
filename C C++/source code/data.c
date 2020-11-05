#include "dataset.h"




void storeData(struct food_category **food, struct food_category **bob, struct food_category **gook, struct food_category **jjige, struct food_category **banchan, struct food_category **bread_meal, struct food_category **noodle) {
	
	/**********************************************

		������ �߰��ϰ�, ī�װ� ���� �з��ϰ� 
		���� ����Ʈ�� �ڷḦ �����մϴ�.

		������ ī�װ��� �� ������ ������ �ִ�����
		���� �̸��� �����ͷ� ������ �ֽ��ϴ�.

	***********************************************/

		NODE *tmp, *new_node, *new_node_sub;
		
		new_node = (NODE *)malloc(sizeof(NODE));
		new_node->link = NULL;
		tmp = *food;

		
		scanf("%s%d%d", new_node->food_name, &(new_node->price), &(new_node->calorie));
		
		
		if (tmp == NULL) {
			//�� ���� ����Ʈ�� ù ��° ��带 ����
			*food = new_node;
		}

		else {
			while (tmp->link != NULL) {
				tmp = tmp->link;
			}
			tmp->link = new_node;
		}
		
	
		/*****************���� �з�**************************/
		
			if (strstr(new_node->food_name, "��") != NULL) {

				
				tmp = *bob;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);
				if (tmp == NULL) {
					//�� ���� ����Ʈ�� ù ��° ��带 ����
					*bob = new_node_sub;
				}
				
				else {
					
					while (tmp->link != NULL) {
						tmp = tmp->link;
						
					}
					
					
					tmp->link = new_node_sub;
					
				}
				

			}
			else if (strstr(new_node->food_name, "����") != NULL) {
				tmp = *noodle;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
				
					*noodle = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}
			}
			else if (strstr(new_node->food_name, "��") != NULL) {
				tmp = *gook;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
				
					*gook = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}

			}
			else if (strstr(new_node->food_name, "�") != NULL) {
				tmp = *jjige;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
				
					*jjige = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}

			}
			else if (strstr(new_node->food_name, "�佺Ʈ") != NULL || strstr(new_node->food_name, "������ġ") != NULL || strstr(new_node->food_name, "��") != NULL) {
				tmp = *bread_meal;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);

				if (tmp == NULL) {
				
					*bread_meal = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}

			}
			else {//������, ������ ������ �� �ְ� ���� ������ �� ������ �������� ���ΰ� ������
			
				tmp = *banchan;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);
				
				if (tmp == NULL) {
				
					*banchan = new_node_sub;
				}

				else {
					while (tmp->link != NULL) {
						tmp = tmp->link;
					}
					tmp->link = new_node_sub;
				}
			
			}
			
		

}

void input_data(struct meal *cal_meal, struct food_category *bob, struct food_category *gook, struct food_category *jjige, struct food_category *banchan, struct food_category *bread_meal, struct food_category *noodle)
{
	/******************************************************

		�Ĵ��� 3�� �ߺ��� ���� �ʰ� �ϸ鼭 1, 2, �Ǵ� 3����
		�� ���� �Ĵ��� ����� �Լ� �Դϴ�.

	*******************************************************/

	int i, j, k;//�ݺ��� ���� ����
	int percentage;//1, 2, 3�Ŀ� ���Ͽ� ������ ���� Ȯ��
	int tot;//3�� �ߺ��� ���� ���� ����
	int flag, compare_num;//3�� �ߺ��� ���� ���� ����
	
	
	time_t current;
	struct tm *cal_time;
	current = time(NULL);
	cal_time = localtime(&current);


	for (i = 0; i < 365; i++) {
		(cal_meal + i)->meal_calendary.year = cal_time->tm_year + 1900;
		(cal_meal + i)->meal_calendary.month = cal_time->tm_mon + 1;
		(cal_meal + i)->meal_calendary.day = cal_time->tm_mday;
		(cal_meal + i)->meal_calendary.mday = cal_time->tm_wday;
		current += 60 * 60 * 24;//�Ϸ� ����
		cal_time = localtime(&current);

		

	}//��¥ data & �޴� ���� �Է�

	
	//�ϴ� �ߺ� ���� ������� �ʰ� �޴��� �־������
	
	
	for (i = 0; i < 365; i++) {

		(cal_meal + i)->total_calories = 0;
		while (1) {
			percentage = rand() % 50;//1���� 20�ۼ�Ʈ Ȯ���� ������ �ϱ� ����
			flag = 0;
			if (percentage != 0) {
				(cal_meal + i)->meal_num = rand() % 2 + 2;
				switch ((cal_meal + i)->meal_num) {//3 �Ǵ� 2�� ¥�� �κ�
				case 3:
					if (rand() % 2 == 0) {
						strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
						strcpy((cal_meal + i)->meal_menu[1], (food_name(gook)));
						strcpy((cal_meal + i)->meal_menu[2], (food_name(banchan)));
					}
					else {
						strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
						strcpy((cal_meal + i)->meal_menu[1], (food_name(jjige)));
						strcpy((cal_meal + i)->meal_menu[2], (food_name(banchan)));

					}

					break;
				case 2:
					strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
					strcpy((cal_meal + i)->meal_menu[1], (food_name(jjige)));


					break;
				default:;
					
				}
			}
			else {//���Ͻ� ¥�� �κ�
				(cal_meal + i)->meal_num = 1;
				if (food_name_number(bread_meal) > 0 && food_name_number(noodle) > 0) {
					switch (rand() % 2 + 1) {
					case 1:strcpy((cal_meal + i)->meal_menu[0], (food_name(noodle)));
						break;
					case 2:strcpy((cal_meal + i)->meal_menu[0], (food_name(bread_meal)));
						break;
					default:;
						
					}
				}
				
			}

			/*********�ߺ� �޴� üũ**********/

			if (i == 0)break;

			//3�������� ��
			if (i == 1)compare_num = 2;//��°���� ù°���� ��, �� �Ϸ縸 ���ϸ��
			else if (i == 2)compare_num = 1;//���� ��°���� ��Ʋ�� ���ϸ� ��
			else compare_num = 0;//�������� 3�� �Ĵ� �ߺ��� �� ������


			for (tot = 1; tot <= 3 - compare_num; tot++) {
				
				for (j = 0; j < (cal_meal + i)->meal_num; j++) {
					for (k = 0; k < (cal_meal + i - tot)->meal_num; k++) {
						if (strcmp((cal_meal + i)->meal_menu[j], (cal_meal + i - tot)->meal_menu[k]) == 0)
						{
							flag = 1;//�ߺ��� ������ �˷��� ����
							break;//�ߺ� �߰�
						}
					}
					if (flag == 1)break;//�ߺ� �߰�

				}
				if (flag == 1)break;//�ᱹ �ߺ� �߰�
				
			}





			if (flag == 0)break;//���������� �ߺ��� ������ Ȯ��
		}
	}
	
		
	//�� ����ü�� �޷��� ��� ��ġ���� ǥ���ϱ� ���ؼ� ��ġ���� ��, ���� �������� �����մϴ�..
	for (i = 0; i < 365; i++) {
		(cal_meal + i)->x = 2+ 20*(((cal_meal + i)->meal_calendary.day - 1) % 7);//�Ϸ� �����Ҷ����� x��ǥ���� ����
		(cal_meal + i)->y = 3 + 9 * (((cal_meal + i)->meal_calendary.day - 1) / 7);	//������ ���� �� ���� y��ǥ���� �ϳ� ����
	
	}
	
	
}


void input_healthy_data(int std_calorie, struct meal *cal_meal, struct food_category *bob, struct food_category *gook, struct food_category *jjige, struct food_category *banchan, struct food_category *bread_meal, struct food_category *noodle)
{
	/**************************************************

		��Į�θ��Ĵ��� ������ִ� �Լ��Դϴ�.

		�Ĵܿ� ����ִ� ������ �� Į�θ��� ����
		��� �� ǥ�� Į�θ� std_calorie�� ���� 
		�ʰ� �Ĵ��� ¥�ִ� �Լ��Դϴ�.
		
	***************************************************/

	int i, j, k;//�ݺ��� ���� ����
	int percentage;//1, 2, 3�Ŀ� ���Ͽ� ������ ���� Ȯ��
	int tot;//3�� �ߺ��� ���� ���� ����
	int flag, compare_num;//3�� �ߺ��� ���� ���� ����


	time_t current;
	struct tm *cal_time;
	current = time(NULL);
	cal_time = localtime(&current);


	for (i = 0; i < 365; i++) {
		(cal_meal + i)->meal_calendary.year = cal_time->tm_year + 1900;
		(cal_meal + i)->meal_calendary.month = cal_time->tm_mon + 1;
		(cal_meal + i)->meal_calendary.day = cal_time->tm_mday;
		(cal_meal + i)->meal_calendary.mday = cal_time->tm_wday;
		current += 60 * 60 * 24;//�Ϸ� ����
		cal_time = localtime(&current);



	}//��¥ data & �޴� ���� �Է�


	//�ϴ� �ߺ� ���� ������� �ʰ� �޴��� �־������


	for (i = 0; i < 365; i++) {


		while (1) {
			
			(cal_meal + i)->total_calories = 0;

			percentage = rand() % 50;//1���� 20�ۼ�Ʈ Ȯ���� ������ �ϱ� ����
			flag = 0;
			if (percentage != 0) {
				(cal_meal + i)->meal_num = rand() % 2 + 2;
				switch ((cal_meal + i)->meal_num) {//3 �Ǵ� 2�� ¥�� �κ�
				case 3:
					if (rand() % 2 == 0) {
						strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
						(cal_meal + i)->total_calories += food_calories(bob, (cal_meal + i)->meal_menu[0]);

						strcpy((cal_meal + i)->meal_menu[1], (food_name(gook)));
						(cal_meal + i)->total_calories += food_calories(gook, (cal_meal + i)->meal_menu[1]);

						strcpy((cal_meal + i)->meal_menu[2], (food_name(banchan)));
						(cal_meal + i)->total_calories += food_calories(banchan, (cal_meal + i)->meal_menu[2]);


					}
					else {
						strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
						(cal_meal + i)->total_calories += food_calories(bob, (cal_meal + i)->meal_menu[0]);

						strcpy((cal_meal + i)->meal_menu[1], (food_name(jjige)));
						(cal_meal + i)->total_calories += food_calories(jjige, (cal_meal + i)->meal_menu[1]);

						strcpy((cal_meal + i)->meal_menu[2], (food_name(banchan)));
						(cal_meal + i)->total_calories += food_calories(banchan, (cal_meal + i)->meal_menu[2]);



					}
					break;

				case 2:
					strcpy((cal_meal + i)->meal_menu[0], (food_name(bob)));
					(cal_meal + i)->total_calories += food_calories(bob, (cal_meal + i)->meal_menu[0]);

					strcpy((cal_meal + i)->meal_menu[1], (food_name(jjige)));
					(cal_meal + i)->total_calories += food_calories(jjige, (cal_meal + i)->meal_menu[1]);


					break;
				default:;
				}
			}
			else {//���Ͻ� ¥�� �κ�
				(cal_meal + i)->meal_num = 1;
				if (food_name_number(bread_meal) > 0 && food_name_number(noodle) > 0) {
					switch (rand() % 2 + 1) {
					case 1:
						strcpy((cal_meal + i)->meal_menu[0], (food_name(noodle)));
						(cal_meal + i)->total_calories += food_calories(noodle, (cal_meal + i)->meal_menu[0]);
						break;

					case 2:strcpy((cal_meal + i)->meal_menu[0], (food_name(bread_meal)));
						(cal_meal + i)->total_calories += food_calories(bread_meal, (cal_meal + i)->meal_menu[0]);
						break;

					default:;
					}
				}

			}
		

			


			/*********�ߺ� �޴� üũ**********/
			
			if (i == 0 && ((cal_meal + i)->total_calories < std_calorie))break;

			//3�������� ��
			if (i == 1)compare_num = 2;//��°���� ù°���� ��, �� �Ϸ縸 ���ϸ��
			else if (i == 2)compare_num = 1;//���� ��°���� ��Ʋ�� ���ϸ� ��
			else compare_num = 0;//�������� 3�� �Ĵ� �ߺ��� �� ������


			for (tot = 1; tot <= 3 - compare_num; tot++) {

				for (j = 0; j < (cal_meal + i)->meal_num; j++) {
					for (k = 0; k < (cal_meal + i - tot)->meal_num; k++) {
						if (strcmp((cal_meal + i)->meal_menu[j], (cal_meal + i - tot)->meal_menu[k]) == 0)
						{
							flag = 1;//�ߺ��� ������ �˷��� ����
							break;//�ߺ� �߰�
						}
					}
					if (flag == 1)break;//�ߺ� �߰�

				}
				if (flag == 1)break;//�ᱹ �ߺ� �߰�

			}





			if (flag == 0 && ((cal_meal + i)->total_calories < std_calorie))break;
			//���������� �ߺ��� ���� �ش��ϴ� Į�θ� �̸��� �Ĵ��� ����!
		}
	}


	//�� ����ü�� �޷��� ��� ��ġ���� ǥ���ϱ� ���ؼ� ��ġ���� ��, ���� �������� �����մϴ�..
	for (i = 0; i < 365; i++) {
		(cal_meal + i)->x = 2 + 20 * (((cal_meal + i)->meal_calendary.day - 1) % 7);//�Ϸ� �����Ҷ����� x��ǥ���� ����
		(cal_meal + i)->y = 3 + 9 * (((cal_meal + i)->meal_calendary.day - 1) / 7);	//������ ���� �� ���� y��ǥ���� �ϳ� ����

	}


}


void find_food_propertise(NODE *food, char *target) {

	/**********************************

	ã���� �ϴ� ������ �̸��� �Է��ϸ� 
	������ Į�θ��� ������ ǥ������

	***********************************/

	NODE *tmp, *prev;
	tmp = food;
	prev = tmp;



	if (strcmp(tmp->food_name, target) == 0) {
		gotoxy(1, 5);
		printf("���� �̸� : %s\n", tmp->food_name);
		gotoxy(1, 6);
		printf("Į�θ� : %d(kal)\n", tmp->calorie);
		gotoxy(1, 7);
		printf("���� : %d��\n", tmp->price);
		gotoxy(1, 8);
		printf("����Ϸ��� �ƹ�Ű�� ��������.");
		getch();
		fflush(stdin);
		return;
	}

	if (tmp == NULL) {
		gotoxy(1, 3);
		printf("�ش� �����̸��� ã�� �� �����ϴ�. �ش� ���Ŀ� ���� ������ ������\n");
		gotoxy(1, 4);
		printf("���Ŀ� ���ؼ� ������ �߰� �� ���ô°� �����?\n");
		gotoxy(1, 5);
		printf("3���� ����ȭ������ ���ư��ϴ�. \n");
		Sleep(1000);
		gotoxy(1, 5);
		printf("2");
		Sleep(1000);
		gotoxy(1, 5);
		printf("1");
		Sleep(1000);
		return;
	}

	while (1) {

		if (tmp == NULL) {
			gotoxy(1, 3);
			printf("�ش� �����̸��� ã�� �� �����ϴ�. �ش� ���Ŀ� ���� ������ ������\n");
			gotoxy(1, 4);
			printf("���Ŀ� ���ؼ� ������ �߰� �� ���ô°� �����?\n");
			gotoxy(1, 5);
			printf("3���� ����ȭ������ ���ư��ϴ�. \n");
			Sleep(1000);
			gotoxy(1, 5);
			printf("2");
			Sleep(1000);
			gotoxy(1, 5);
			printf("1");
			Sleep(1000);
			return;
		}


		if (strcmp(tmp->food_name, target) == 0) {
			gotoxy(1, 5);
			printf("���� �̸� : %s\n", tmp->food_name);
			gotoxy(1, 6);
			printf("Į�θ� : %d(kal)\n", tmp->calorie);
			gotoxy(1, 7);
			printf("���� : %d��\n", tmp->price);
			gotoxy(1, 8);
			printf("����Ϸ��� �ƹ�Ű�� ��������.");
			getch();
			fflush(stdin);
			return;


		}
		else {
			prev = tmp;
			tmp = tmp->link;
		}
	}
	gotoxy(2, 8);
	printf("����Ϸ��� �ƹ�Ű�� ��������.");


}

int food_calories(NODE *food, char *target) {

	/********************************
		
		�ش� �����̸�(char *target)��
		������ �ִ� ������ Į�θ�����
		��ȯ �� �ִ� �Լ� �Դϴ�.
	
	********************************/

	NODE *tmp, *prev;
	tmp = food;
	prev = tmp;

	if (strcmp(tmp->food_name, target) == 0) {
		
		return tmp->calorie;
	}
	

	while (1) {


		if (strcmp(tmp->food_name, target) == 0) {
			return tmp->calorie;


		}
		else {
			prev = tmp;
			tmp = tmp->link;
		}
	}

	return 0;
}


char* food_name(NODE *food) {

	/********************************

	�ش� ī�װ��� �ִ� ���ĵ��߿���
	�������� �ϳ��� ��ȯ���ִ� �Լ�
	
	********************************/

	int count = 0, rand_i, i;//���(����) ����
	NODE *tmp;


	tmp = food;
	count = food_name_number(tmp);
	
	
	rand_i = rand() % count;
	for (i = 0; i < rand_i; i++) {
		tmp = tmp->link;
	}
	return tmp->food_name;

}


int food_name_number(NODE *food) {

	/***********************

	�ش� ī�װ�ȭ�� ������ 
	��ִ��� �˷��ִ� �Լ�

	************************/

	int count = 0;
	NODE *tmp;


	tmp = food;
	while (1) {
		if (tmp == NULL) {
			break;
		}
		else {
			count++;
			tmp = tmp->link;
		}
	}
	
	return count;

}

int remover_FoodName(NODE **p, char *target) {

	/******************************************

		target���� ���� ���� �̸��� �ش��ϴ�
		��带 �����ϴ� �Լ��Դϴ�.
		���������� �����͸� �����ϸ� 1��
		�ƴϸ� 0�� ���� �ݴϴ�.

	******************************************/
	NODE *tmp, *prev;
	tmp = *p;
	prev = tmp;

	if (strcmp(tmp->food_name, target) == 0) {
		*p = tmp->link;
		free(tmp);
		return 1;
	}

	while (tmp != NULL) {
		

		if (strcmp(tmp->food_name, target) == 0) {
			//�ش� ������ �߰��ߴٸ� ����� �ش� ī�װ��� �ٸ� ���� node�� ����
			prev->link = tmp->link;
			free(tmp);
			return 1;


		}
		else {
			prev = tmp;
			tmp = tmp->link;
		}
	}
	gotoxy(1, 4);
	printf("�ش� ������ �����ϴ�!");
	gotoxy(1, 5);
	printf("3���� ����ȭ������ ���ư��ϴ�. \n");
	Sleep(1000);
	gotoxy(1, 5);
	printf("2");
	Sleep(1000);
	gotoxy(1, 5);
	printf("1");
	Sleep(1000);
	system("cls");
	return 0;
	
}

void remover_LinkedList(NODE **p) {
	
	/**************************************

		���Ḯ��Ʈ p�� �Ҵ�� ���� �޸𸮸�
		�����ϴ� �Լ� �Դϴ�.

	**************************************/

	NODE *tmp, *cur;
	tmp = *p;

	while (tmp != NULL) {
		cur = tmp->link;
		free(tmp);
		tmp = cur;
	}
	*p = NULL;

}

void readFrFile(char * filename, NODE **food, NODE **bob, NODE **gook, NODE **banchan, NODE **jjige, NODE **bread_meal, NODE **noodle) {

	/************************************
	����(txt)�κ��� �����͸� �о 
	���Ŀ� ���� ���Ḯ��Ʈ �ڷ� ���� ����

	���Ͽ��� �����̸� ���� Į�θ� ������
	�����Ͱ� ����Ǿ� �־�� �մϴ�.
	************************************/

	FILE *fp;
	NODE *new_node, *tmp_1 ,*new_node_sub ,*tmp;

	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("�ش� ������ �����ϴ�!\n");
		return;
	}

	tmp_1 = *food;
	while (!feof(fp)) {
		new_node = (NODE *)malloc(sizeof(NODE));
		new_node->link = NULL;
		fscanf(fp, "%s %d %d", new_node->food_name, &new_node->price, &new_node->calorie);

		if (tmp_1 == NULL) {
			*food = new_node;
			tmp_1 = new_node;
			
		}
		else {
			tmp_1->link = new_node;
			tmp_1 = tmp_1->link;
		}


		/*******************************************

			���� ī�װ��� ���Ŀ� ���Ͽ� 
			���� ī�װ��� ��, ����, ��, �, ����,
			���Ŀ� ���Ͽ� ���� ����Ʈ�� ���� �ϴ� �κ�
			�Դϴ�.

		*******************************************/
		new_node_sub = (NODE *)malloc(sizeof(NODE));
		new_node_sub->link = NULL;
		strcpy(new_node_sub->food_name, new_node->food_name);
		new_node_sub->calorie = new_node->calorie;
		new_node_sub->price = new_node->price;


		if (strstr(new_node->food_name, "��") != NULL) {
			tmp = *bob;
		

			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
				*bob = new_node_sub;
			}

			else {

				while (tmp->link != NULL) {
					tmp = tmp->link;

				}


				tmp->link = new_node_sub;
	
			}


		}
		else if (strstr(new_node->food_name, "����") != NULL) {
			tmp = *noodle;


			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
				*noodle = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}
		}
		else if (strstr(new_node->food_name, "��") != NULL) {
			tmp = *gook;


			if (tmp == NULL) {
				*gook = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else if (strstr(new_node->food_name, "�") != NULL) {
			tmp = *jjige;

			if (tmp == NULL) {
				*jjige = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else if (strstr(new_node->food_name, "�佺Ʈ") != NULL || strstr(new_node->food_name, "������ġ") != NULL || strstr(new_node->food_name, "��") != NULL) {
			tmp = *bread_meal;


			if (tmp == NULL) {
				*bread_meal = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else {
			tmp = *banchan;


			if (tmp == NULL) {
				*banchan = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}//������, ������ ������ �� �ְ� ���� ������ �� ������ �������� ���ΰ� ������

	}
	fclose(fp);

}


void writeAtFile(char * filename, void *data, int switch_num) {

	/*******************************************

		data�� ���� ������ bin.�������� 
		�����ϴ� �Լ��Դϴ�.

		switch_num���� ���� �Ĵ��� �������� ������
		�������� �����մϴ�.
			
	*******************************************/

	int i , j;
	FILE *fp;
	NODE *tmp;//���� �̸��̸�, �����̸��� ������ �� ����� ����
	struct meal *meal_tmp;//�Ĵ��� �����ϰ��� �� ��� ����� ����

	fp = fopen(filename, "wb");

	if (switch_num == 1) {//���� ī�װ�(���� ����Ʈ)�� �����ϰ��� �ϴ� ���
		tmp = (NODE *)data;
		
		while (tmp != NULL) {
			

			fwrite(tmp, sizeof(NODE), 1, fp);
			tmp = tmp->link;
		}
	}
	
	else {//�Ĵ��� �����ϰ��� �ϴ� ���
		meal_tmp = (struct meal *)data;
		fwrite(meal_tmp, sizeof(struct meal), 365, fp);

	}
	

	fclose(fp);
}
void readFrBinFile(char * filename, NODE **data, int switch_num) {

	/*******************************************

		data�� bin.�������� ����� ���� �����͸�
		�����ϴ� �Լ��Դϴ�.

		switch_num ���� 1�̸� NODE ����ü�� ���ؼ�
		���Ḯ��Ʈ�� �о� ����, 1�� �ƴϸ� �Ĵܿ�
		���ؼ� ���� �о� �ɴϴ�.

		����) �б� ���� ���� ����Ʈ �� ���
		data�� �ּҴ� NULL�� ����Ű�� �־��
		�մϴ�. NULL�� �ƴ� ��� �ش� ������ 
		���� ���� ����Ʈ�� �����ϰ� �����Ƿ�
		remover_LinkedList()�� ȣ���� ���Ḯ��Ʈ��
		���� �ϴ��� �ƴϸ� ó�� ���� ���� ����Ʈ��
		����� �մϴ�.

	*******************************************/
	
	int i, j, check;
	FILE *fp;
	NODE *read_tmp, *tmp;//���� �̸��̸�, �����̸��� ������ �� ����� ����
	struct meal *meal_tmp;//�Ĵ��� �����ϰ��� �� ��� ����� ����

	fp = fopen(filename, "rb");
	
	if (fp == NULL) {
		return;
	}
	
	if (switch_num == 1) {//���� ī�װ��� �����ϰ��� �ϴ� ���
		
		*data = NULL;
		tmp = *data;
		while (1) {
			
			read_tmp = (NODE *)malloc(sizeof(NODE));
			check = fread(read_tmp, sizeof(NODE), 1, fp);

			if (!check)break;//�� �̻� �о� �� �����Ͱ��� ������

			if (tmp == NULL) {
			
				*data = read_tmp;
				tmp = read_tmp;
			}
			else {
		
				tmp->link = read_tmp;
				tmp = tmp->link;
			}
			

		}
		
	}

	else {//�Ĵ��� �����ϰ��� �ϴ� ���
		meal_tmp = (struct meal *)data;
	
		fread(meal_tmp, sizeof(struct meal), 365, fp);

		
	}


	fclose(fp);

}

void distributeFood(NODE *food, NODE **bob, NODE **gook, NODE **banchan, NODE **jjige, NODE **bread_meal, NODE **noodle) {
	/*******************************************

		���Ḯ��Ʈ food�� ���Ͽ� ���� ���� ī�װ��� �з���
		���Ŀ� ���Ͽ� ���Ḯ��Ʈ �����ϴ� �Լ��Դϴ�.

	*******************************************/
	
	
	NODE *new_node_sub, *tmp, *tmp_category, *new_node;
	tmp_category = food;
	*bob = NULL;
	*gook = NULL;
	*banchan = NULL;
	*jjige = NULL;
	*noodle = NULL;
	*bread_meal = NULL;

	

	while (tmp_category != NULL) {

		new_node_sub = (NODE *)malloc(sizeof(NODE));
		new_node_sub->link = NULL;
		strcpy(new_node_sub->food_name, tmp_category->food_name);
		new_node_sub->calorie = tmp_category->calorie;
		new_node_sub->price = tmp_category->price;

		
		if (strstr(new_node_sub->food_name, "��") != NULL) {
			tmp = *bob;


			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
				*bob = new_node_sub;
			}

			else {

				while (tmp->link != NULL) {
					tmp = tmp->link;

				}


				tmp->link = new_node_sub;

			}


		}
		else if (strstr(new_node_sub->food_name, "����") != NULL) {
			tmp = *noodle;


			if (tmp == NULL) {
				//�� ���� ����Ʈ�� ù ��° ��带 ����
				*noodle = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}
		}
		else if (strstr(new_node_sub->food_name, "��") != NULL) {
			tmp = *gook;


			if (tmp == NULL) {
				*gook = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else if (strstr(new_node_sub->food_name, "�") != NULL) {
			tmp = *jjige;

			if (tmp == NULL) {
				*jjige = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else if (strstr(new_node_sub->food_name, "�佺Ʈ") != NULL || strstr(new_node_sub->food_name, "������ġ") != NULL || strstr(new_node_sub->food_name, "��") != NULL) {
			tmp = *bread_meal;


			if (tmp == NULL) {
				*bread_meal = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}
		else {
			tmp = *banchan;


			if (tmp == NULL) {
				*banchan = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}

		}


		tmp_category = tmp_category->link;
	}
	

}