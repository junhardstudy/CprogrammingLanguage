#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#pragma warning(disable: 4996)


typedef struct food_category NODE;//모든 음식들은 연결 리스트 자료구조 형식을 취함.


void drawData(struct meal *, int *, int*);
void drawData_left(struct meal *, int *, int*);
void gotoxy(int, int);
void drawMenu();
void drawTable(int, int);
void input_data(struct meal *, struct food_category *, struct food_category *, struct food_category *, struct food_category *, struct food_category *, struct food_category *);
void storeData(struct food_category **, struct food_category **, struct food_category **, struct food_category **, struct food_category **, struct food_category **, struct food_category **);
void drawSquare(int , int );
void storeDataAsNode(NODE **);
char* food_name(NODE *);
int food_name_number(NODE *);
void remover_LinkedList(NODE **);
int remover_FoodName(NODE **, char *);
void readFrFile(char * filename, NODE **food, NODE **bob, NODE **gook, NODE **banchan, NODE **jjige, NODE **bread_meal, NODE **noodle);
int food_calories(NODE *food, char *target);
void writeAtFile(char * filename, void *data, int switch_num);
void find_food_propertise(NODE *, char *);
void distributeFood(NODE *food, NODE **bob, NODE **gook, NODE **banchan, NODE **jjige, NODE **bread_meal, NODE **noodle);
void readFrBinFile(char * filename, NODE **data, int switch_num);

void input_healthy_data(int std_calorie, struct meal *cal_meal, struct food_category *bob, struct food_category *gook, struct food_category *jjige, struct food_category *banchan, struct food_category *bread_meal, struct food_category *noodle);


struct date {
	int year, month, day, mday;
};

struct meal {
	struct date meal_calendary;
	int meal_num;//메뉴 개수
	char meal_menu[4][16];
	int total_calories;
	int x, y;

};

struct food_category {
	//int num;//해당 카테고리화 된 음식의 개수
	char food_name[19];//음식이름은 최대 9자까지만...
	int calorie;
	int price;
	struct food_category *link;//자기 참조 구조체
};

struct blankcoord
{
	int x, y;

};

/*
struct blankcoord blank[31] = {
		{2,3}, {22, 3}, {42, 3}, {62, 3}, {82, 3}, {102, 3}, {122, 3},
		{2,12}, {22, 12}, {42, 12}, {62, 12}, {82, 12}, {102, 12}, {122, 12},
		{2,21}, {22, 21}, {42, 21}, {62, 21}, {82, 21}, {102, 21}, {122, 21},
		{2,30}, {22, 30}, {42, 30}, {62, 30}, {82, 30}, {102, 30}, {122, 30},
		{2,39}, {22, 39}, {42, 39}
};*/
//X and Y coordinate in decarte for each blanks.
