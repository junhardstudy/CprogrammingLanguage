#include "dataset.h"




void storeData(struct food_category **food, struct food_category **bob, struct food_category **gook, struct food_category **jjige, struct food_category **banchan, struct food_category **bread_meal, struct food_category **noodle) {
	
	/**********************************************

		음식을 추가하고, 카테고리 별로 분류하고 
		연결 리스트로 자료를 형성합니다.

		각각의 카테고리는 몇 종류의 음식이 있는지와
		음식 이름을 데이터로 가지고 있습니다.

	***********************************************/

		NODE *tmp, *new_node, *new_node_sub;
		
		new_node = (NODE *)malloc(sizeof(NODE));
		new_node->link = NULL;
		tmp = *food;

		
		scanf("%s%d%d", new_node->food_name, &(new_node->price), &(new_node->calorie));
		
		
		if (tmp == NULL) {
			//빈 연결 리스트면 첫 번째 노드를 연결
			*food = new_node;
		}

		else {
			while (tmp->link != NULL) {
				tmp = tmp->link;
			}
			tmp->link = new_node;
		}
		
	
		/*****************음식 분류**************************/
		
			if (strstr(new_node->food_name, "밥") != NULL) {

				
				tmp = *bob;
				new_node_sub = (NODE *)malloc(sizeof(NODE));
				new_node_sub->link = NULL;
				strcpy(new_node_sub->food_name, new_node->food_name);
				if (tmp == NULL) {
					//빈 연결 리스트면 첫 번째 노드를 연결
					*bob = new_node_sub;
				}
				
				else {
					
					while (tmp->link != NULL) {
						tmp = tmp->link;
						
					}
					
					
					tmp->link = new_node_sub;
					
				}
				

			}
			else if (strstr(new_node->food_name, "국수") != NULL) {
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
			else if (strstr(new_node->food_name, "국") != NULL) {
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
			else if (strstr(new_node->food_name, "찌개") != NULL) {
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
			else if (strstr(new_node->food_name, "토스트") != NULL || strstr(new_node->food_name, "샌드위치") != NULL || strstr(new_node->food_name, "빵") != NULL) {
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
			else {//반찬임, 반찬은 구분할 수 있게 해줄 음운이 안 보여서 마지막에 놔두게 좋을듯
			
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

		식단이 3일 중복이 되지 않게 하면서 1, 2, 또는 3식이
		들어간 랜덤 식단을 만드는 함수 입니다.

	*******************************************************/

	int i, j, k;//반복문 제어 변수
	int percentage;//1, 2, 3식에 대하여 각각이 나올 확률
	int tot;//3일 중복에 관한 제어 변수
	int flag, compare_num;//3일 중복에 관한 제어 변수
	
	
	time_t current;
	struct tm *cal_time;
	current = time(NULL);
	cal_time = localtime(&current);


	for (i = 0; i < 365; i++) {
		(cal_meal + i)->meal_calendary.year = cal_time->tm_year + 1900;
		(cal_meal + i)->meal_calendary.month = cal_time->tm_mon + 1;
		(cal_meal + i)->meal_calendary.day = cal_time->tm_mday;
		(cal_meal + i)->meal_calendary.mday = cal_time->tm_wday;
		current += 60 * 60 * 24;//하루 증가
		cal_time = localtime(&current);

		

	}//날짜 data & 메뉴 개수 입력

	
	//일단 중복 조건 고려하지 않고 메뉴만 넣었을경우
	
	
	for (i = 0; i < 365; i++) {

		(cal_meal + i)->total_calories = 0;
		while (1) {
			percentage = rand() % 50;//1식이 20퍼센트 확률로 나오기 하기 위함
			flag = 0;
			if (percentage != 0) {
				(cal_meal + i)->meal_num = rand() % 2 + 2;
				switch ((cal_meal + i)->meal_num) {//3 또는 2식 짜는 부분
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
			else {//단일식 짜는 부분
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

			/*********중복 메뉴 체크**********/

			if (i == 0)break;

			//3일전까지 비교
			if (i == 1)compare_num = 2;//둘째날은 첫째날과 비교, 즉 하루만 비교하면됨
			else if (i == 2)compare_num = 1;//따라서 셋째날은 이틀을 비교하면 됨
			else compare_num = 0;//나머지는 3일 식단 중복이 안 나오게


			for (tot = 1; tot <= 3 - compare_num; tot++) {
				
				for (j = 0; j < (cal_meal + i)->meal_num; j++) {
					for (k = 0; k < (cal_meal + i - tot)->meal_num; k++) {
						if (strcmp((cal_meal + i)->meal_menu[j], (cal_meal + i - tot)->meal_menu[k]) == 0)
						{
							flag = 1;//중복이 있음을 알려줄 변수
							break;//중복 발견
						}
					}
					if (flag == 1)break;//중복 발견

				}
				if (flag == 1)break;//결국 중복 발견
				
			}





			if (flag == 0)break;//최종적으로 중복이 없음을 확인
		}
	}
	
		
	//각 구조체를 달력의 어느 위치인지 표시하기 위해서 위치값을 월, 일을 기준으로 저장합니다..
	for (i = 0; i < 365; i++) {
		(cal_meal + i)->x = 2+ 20*(((cal_meal + i)->meal_calendary.day - 1) % 7);//하루 증가할때마다 x좌표값이 증가
		(cal_meal + i)->y = 3 + 9 * (((cal_meal + i)->meal_calendary.day - 1) / 7);	//일주일 지날 때 마다 y좌표값이 하나 증가
	
	}
	
	
}


void input_healthy_data(int std_calorie, struct meal *cal_meal, struct food_category *bob, struct food_category *gook, struct food_category *jjige, struct food_category *banchan, struct food_category *bread_meal, struct food_category *noodle)
{
	/**************************************************

		저칼로리식단을 만들어주는 함수입니다.

		식단에 들어있는 음식의 총 칼로리의 합이
		계산 한 표준 칼로리 std_calorie를 넘지 
		않게 식단을 짜주는 함수입니다.
		
	***************************************************/

	int i, j, k;//반복문 제어 변수
	int percentage;//1, 2, 3식에 대하여 각각이 나올 확률
	int tot;//3일 중복에 관한 제어 변수
	int flag, compare_num;//3일 중복에 관한 제어 변수


	time_t current;
	struct tm *cal_time;
	current = time(NULL);
	cal_time = localtime(&current);


	for (i = 0; i < 365; i++) {
		(cal_meal + i)->meal_calendary.year = cal_time->tm_year + 1900;
		(cal_meal + i)->meal_calendary.month = cal_time->tm_mon + 1;
		(cal_meal + i)->meal_calendary.day = cal_time->tm_mday;
		(cal_meal + i)->meal_calendary.mday = cal_time->tm_wday;
		current += 60 * 60 * 24;//하루 증가
		cal_time = localtime(&current);



	}//날짜 data & 메뉴 개수 입력


	//일단 중복 조건 고려하지 않고 메뉴만 넣었을경우


	for (i = 0; i < 365; i++) {


		while (1) {
			
			(cal_meal + i)->total_calories = 0;

			percentage = rand() % 50;//1식이 20퍼센트 확률로 나오기 하기 위함
			flag = 0;
			if (percentage != 0) {
				(cal_meal + i)->meal_num = rand() % 2 + 2;
				switch ((cal_meal + i)->meal_num) {//3 또는 2식 짜는 부분
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
			else {//단일식 짜는 부분
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
		

			


			/*********중복 메뉴 체크**********/
			
			if (i == 0 && ((cal_meal + i)->total_calories < std_calorie))break;

			//3일전까지 비교
			if (i == 1)compare_num = 2;//둘째날은 첫째날과 비교, 즉 하루만 비교하면됨
			else if (i == 2)compare_num = 1;//따라서 셋째날은 이틀을 비교하면 됨
			else compare_num = 0;//나머지는 3일 식단 중복이 안 나오게


			for (tot = 1; tot <= 3 - compare_num; tot++) {

				for (j = 0; j < (cal_meal + i)->meal_num; j++) {
					for (k = 0; k < (cal_meal + i - tot)->meal_num; k++) {
						if (strcmp((cal_meal + i)->meal_menu[j], (cal_meal + i - tot)->meal_menu[k]) == 0)
						{
							flag = 1;//중복이 있음을 알려줄 변수
							break;//중복 발견
						}
					}
					if (flag == 1)break;//중복 발견

				}
				if (flag == 1)break;//결국 중복 발견

			}





			if (flag == 0 && ((cal_meal + i)->total_calories < std_calorie))break;
			//최종적으로 중복이 없고 해당하는 칼로리 미만의 식단을 생성!
		}
	}


	//각 구조체를 달력의 어느 위치인지 표시하기 위해서 위치값을 월, 일을 기준으로 저장합니다..
	for (i = 0; i < 365; i++) {
		(cal_meal + i)->x = 2 + 20 * (((cal_meal + i)->meal_calendary.day - 1) % 7);//하루 증가할때마다 x좌표값이 증가
		(cal_meal + i)->y = 3 + 9 * (((cal_meal + i)->meal_calendary.day - 1) / 7);	//일주일 지날 때 마다 y좌표값이 하나 증가

	}


}


void find_food_propertise(NODE *food, char *target) {

	/**********************************

	찾고자 하는 음식의 이름을 입력하면 
	음식의 칼로리와 가격을 표시해줌

	***********************************/

	NODE *tmp, *prev;
	tmp = food;
	prev = tmp;



	if (strcmp(tmp->food_name, target) == 0) {
		gotoxy(1, 5);
		printf("음식 이름 : %s\n", tmp->food_name);
		gotoxy(1, 6);
		printf("칼로리 : %d(kal)\n", tmp->calorie);
		gotoxy(1, 7);
		printf("가격 : %d원\n", tmp->price);
		gotoxy(1, 8);
		printf("계속하려면 아무키나 누르세요.");
		getch();
		fflush(stdin);
		return;
	}

	if (tmp == NULL) {
		gotoxy(1, 3);
		printf("해당 음식이름을 찾을 수 없습니다. 해당 음식에 대한 정보가 없으니\n");
		gotoxy(1, 4);
		printf("음식에 대해서 정보를 추가 해 보시는건 어떤가요?\n");
		gotoxy(1, 5);
		printf("3초후 메인화면으로 돌아갑니다. \n");
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
			printf("해당 음식이름을 찾을 수 없습니다. 해당 음식에 대한 정보가 없으니\n");
			gotoxy(1, 4);
			printf("음식에 대해서 정보를 추가 해 보시는건 어떤가요?\n");
			gotoxy(1, 5);
			printf("3초후 메인화면으로 돌아갑니다. \n");
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
			printf("음식 이름 : %s\n", tmp->food_name);
			gotoxy(1, 6);
			printf("칼로리 : %d(kal)\n", tmp->calorie);
			gotoxy(1, 7);
			printf("가격 : %d원\n", tmp->price);
			gotoxy(1, 8);
			printf("계속하려면 아무키나 누르세요.");
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
	printf("계속하려면 아무키나 누르세요.");


}

int food_calories(NODE *food, char *target) {

	/********************************
		
		해당 음식이름(char *target)을
		가지고 있는 음식의 칼로리값을
		반환 해 주는 함수 입니다.
	
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

	해당 카테고리에 있는 음식들중에서
	무작위로 하나를 반환해주는 함수
	
	********************************/

	int count = 0, rand_i, i;//노드(음식) 개수
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

	해당 카테고리화된 음식이 
	몇개있는지 알려주는 함수

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

		target으로 받은 음식 이름에 해당하는
		노드를 삭제하는 함수입니다.
		성공적으로 데이터를 삭제하면 1을
		아니면 0을 돌려 줍니다.

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
			//해당 음식을 발견했다면 지우고 해당 카테고리의 다른 음식 node를 연결
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
	printf("해당 음식은 없습니다!");
	gotoxy(1, 5);
	printf("3초후 메인화면으로 돌아갑니다. \n");
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

		연결리스트 p에 할당된 동적 메모리를
		해제하는 함수 입니다.

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
	파일(txt)로부터 데이터를 읽어서 
	음식에 대한 연결리스트 자료 구조 형성

	파일에는 음식이름 가격 칼로리 순으로
	데이터가 저장되어 있어야 합니다.
	************************************/

	FILE *fp;
	NODE *new_node, *tmp_1 ,*new_node_sub ,*tmp;

	fp = fopen(filename, "rt");
	if (fp == NULL) {
		printf("해당 파일은 없습니다!\n");
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

			상위 카테고리인 음식에 대하여 
			하위 카테고리인 밥, 반찬, 국, 찌개, 국수,
			빵식에 대하여 연결 리스트를 형성 하는 부분
			입니다.

		*******************************************/
		new_node_sub = (NODE *)malloc(sizeof(NODE));
		new_node_sub->link = NULL;
		strcpy(new_node_sub->food_name, new_node->food_name);
		new_node_sub->calorie = new_node->calorie;
		new_node_sub->price = new_node->price;


		if (strstr(new_node->food_name, "밥") != NULL) {
			tmp = *bob;
		

			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*bob = new_node_sub;
			}

			else {

				while (tmp->link != NULL) {
					tmp = tmp->link;

				}


				tmp->link = new_node_sub;
	
			}


		}
		else if (strstr(new_node->food_name, "국수") != NULL) {
			tmp = *noodle;


			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*noodle = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}
		}
		else if (strstr(new_node->food_name, "국") != NULL) {
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
		else if (strstr(new_node->food_name, "찌개") != NULL) {
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
		else if (strstr(new_node->food_name, "토스트") != NULL || strstr(new_node->food_name, "샌드위치") != NULL || strstr(new_node->food_name, "빵") != NULL) {
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

		}//반찬임, 반찬은 구분할 수 있게 해줄 음운이 안 보여서 마지막에 놔두게 좋을듯

	}
	fclose(fp);

}


void writeAtFile(char * filename, void *data, int switch_num) {

	/*******************************************

		data에 대한 정보를 bin.형식으로 
		저장하는 함수입니다.

		switch_num값에 따라 식단을 저장할지 음식을
		저장할지 결정합니다.
			
	*******************************************/

	int i , j;
	FILE *fp;
	NODE *tmp;//음식 이름이면, 음식이름을 저장할 때 사용할 변수
	struct meal *meal_tmp;//식단을 저장하고자 할 경우 사용할 변수

	fp = fopen(filename, "wb");

	if (switch_num == 1) {//음식 카테고리(연결 리스트)를 저장하고자 하는 경우
		tmp = (NODE *)data;
		
		while (tmp != NULL) {
			

			fwrite(tmp, sizeof(NODE), 1, fp);
			tmp = tmp->link;
		}
	}
	
	else {//식단을 저장하고자 하는 경우
		meal_tmp = (struct meal *)data;
		fwrite(meal_tmp, sizeof(struct meal), 365, fp);

	}
	

	fclose(fp);
}
void readFrBinFile(char * filename, NODE **data, int switch_num) {

	/*******************************************

		data에 bin.형식으로 저장된 파일 데이터를
		저장하는 함수입니다.

		switch_num 값이 1이면 NODE 구조체에 대해서
		연결리스트를 읽어 오고, 1이 아니면 식단에
		대해서 값을 읽어 옵니다.

		주의) 읽기 전에 연결 리스트 일 경우
		data의 주소는 NULL을 가리키고 있어야
		합니다. NULL이 아닐 경우 해당 변수에 
		대해 연결 리스트를 형성하고 있으므로
		remover_LinkedList()를 호출해 연결리스트를
		해제 하던가 아니면 처음 부터 연결 리스트가
		없어야 합니다.

	*******************************************/
	
	int i, j, check;
	FILE *fp;
	NODE *read_tmp, *tmp;//음식 이름이면, 음식이름을 저장할 때 사용할 변수
	struct meal *meal_tmp;//식단을 저장하고자 할 경우 사용할 변수

	fp = fopen(filename, "rb");
	
	if (fp == NULL) {
		return;
	}
	
	if (switch_num == 1) {//음식 카테고리를 저장하고자 하는 경우
		
		*data = NULL;
		tmp = *data;
		while (1) {
			
			read_tmp = (NODE *)malloc(sizeof(NODE));
			check = fread(read_tmp, sizeof(NODE), 1, fp);

			if (!check)break;//더 이상 읽어 올 데이터값이 없을때

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

	else {//식단을 저장하고자 하는 경우
		meal_tmp = (struct meal *)data;
	
		fread(meal_tmp, sizeof(struct meal), 365, fp);

		
	}


	fclose(fp);

}

void distributeFood(NODE *food, NODE **bob, NODE **gook, NODE **banchan, NODE **jjige, NODE **bread_meal, NODE **noodle) {
	/*******************************************

		연결리스트 food에 대하여 하위 연결 카테고리로 분류된
		음식에 대하여 연결리스트 구성하는 함수입니다.

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

		
		if (strstr(new_node_sub->food_name, "밥") != NULL) {
			tmp = *bob;


			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*bob = new_node_sub;
			}

			else {

				while (tmp->link != NULL) {
					tmp = tmp->link;

				}


				tmp->link = new_node_sub;

			}


		}
		else if (strstr(new_node_sub->food_name, "국수") != NULL) {
			tmp = *noodle;


			if (tmp == NULL) {
				//빈 연결 리스트면 첫 번째 노드를 연결
				*noodle = new_node_sub;
			}

			else {
				while (tmp->link != NULL) {
					tmp = tmp->link;
				}
				tmp->link = new_node_sub;
			}
		}
		else if (strstr(new_node_sub->food_name, "국") != NULL) {
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
		else if (strstr(new_node_sub->food_name, "찌개") != NULL) {
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
		else if (strstr(new_node_sub->food_name, "토스트") != NULL || strstr(new_node_sub->food_name, "샌드위치") != NULL || strstr(new_node_sub->food_name, "빵") != NULL) {
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