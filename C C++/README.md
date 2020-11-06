# 개요

* 한 학기 동안 배운 내용을 바탕으로 만든 project 입니다.

* 식단을 랜덤으로 짜주는 프로그램입니다.

* 식단을 랜덤으로 짤 때, 필요한 음식들의 이름을 가지고 밥, 국, 면, 빵, 찌개등등의 카테고리로 분류한다음 중복된 음식이 없도록 식단을 생성합니다.

* 또한 하루전에 나왔던 음식이 다음날에는 나오지 않도록 하여 식단이 물리는 상황을 방지하였습니다.

* gotoxy()함수를 이용해 캘린더 형식으로 식단을 넘겨 볼 수 있습니다.

* 식단 데이터들은 구조체이며, 전체 자료 구조는 링크드 리스트 형태 입니다.

***

한 학기 교육과정에 대한 모든 내용이 들어가 있습니다.

1. 변수와 데이터 타입(char, int)

2. 분기문(if, switch-case)

3. 반복문(for, while)

4. 배열(char [])과 포인터

5. 함수, 함수인자

6. 구조체(struct)(이 프로젝트에서는 주로 구조체 포인터로 다룹니다.)

7. 파일 쓰기, 읽기와 같은 파일 처리

8. advance 주제(Linked list, gotoxy(), 검색)

# 소스코드

1. main_module.c

프로그램의 메인 로직을 중심으로 코딩을 하였습니다. 메인 로직은 사용자로부터 키보드 입력을 받고 대응하는 서브 루틴 함수들을 출력하는 형태입니다.

```c
void main() {
	int i, index_right = 0, index_left;//index는 cal_meal이 어디를 표현해야 할지 알려줄 위치
	int keyboard_value = 0, not_draw_condition;
	char tmp_foodname[16];
	char saved_file_name[21], saved_food_file_name[21];
	int std_weight, work;

	
	system("mode con:cols=143 lines=50");
	system("title 식단표");

	NODE *food, *bob, *gook, *banchan, *jjige, *bread_meal, *noodle;
	FILE *fp , *file_food_name;

	struct meal *cal_meal = (struct meal *)malloc(sizeof(struct meal) * 365);
	
	srand((unsigned int)time(NULL));

	food = NULL;
	bob = NULL;
	gook = NULL;
	banchan = NULL;
	jjige = NULL;
	bread_meal = NULL;
	noodle = NULL;
```

main함수에서 사용할 여러 제어 변수와 식단 데이터를 저장할 변수들이 선언되어 있습니다.


system() api함수를 통해 command window창을 143 X 50의 크기로 지정하고 창의 제목은 title 식단표로 하였습니다.


1년 단위로 식단을 생성하므로, 하루에 들어가는 식단 데이터를 저장할 사용자 정의 type 구조체 meal을 동적 메모리 할당으로 365개를 할당했습니다.


프로그램을 새로 시작할때 마다, 식단을 랜덤하게 형성해야 하므로 rand함수의 시드를 초기화하는 srand()함수를 콜하였습니다.
<br>
<br>
<br>

```c
readFrFile("menu.txt", &food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);
	
	file_food_name = fopen("recently_food.bin", "rb");
	fp = fopen("recently.bin", "rb");//이전에 프로그램을 실행 시켰으면 
		//그 때 종료하기 직전에 만들어놓았던 식단을 불러 옵니다.

	if (fp && file_food_name) {//이전에 프로그램을 실행시켰다면...
		readFrBinFile("recently.bin", cal_meal, 2);
		readFrBinFile("recently_food.bin", &food, 1);
		distributeFood(food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);
		
		
		system("cls");
		drawTable(2, 2);
		drawData(cal_meal, &index_right, &index_left);
		not_draw_condition = 0;
		
	}
	else {
		not_draw_condition = 1;
	}
```
menu.txt 파일을 읽어 들이고, 문자열내에 들어있는 특정 문자 패턴에 따라 밥, 국, 찌개, 반찬, 면을 분리하여 구조체 데이터에 저장하는 readFrFile()함수를 호출합니다.


recently_food.bin 파일과 recently.bin파일은 최근에 프로그램을 실행시켰다면, 최근에 저장한 음식 데이터와 식단 데이터를 불러오게 됩니다.




<br>
<br>
<br>

```c
	while(1){
		if (not_draw_condition == 1) {
			system("mode con:cols=142 lines=15");
			drawSquare(2, 2);
			gotoxy(1, 3);
			printf("처음이신가요?");
			gotoxy(1, 4);
			printf("새로운 식단을 짜거나 자신의 체중에 맞는 권장 섭취 칼로리 식단을 짤 수 있습니다!");
			gotoxy(1, 5);
			printf("기존에 있는 식단을 불러오시려면 F4키, 새로운 식단을 짜시려면 F1 키를, 저칼로리 식단을 짜시려면 F2키를 눌러주세요^^7");

		}
		if (keyboard_value == 8 && not_draw_condition == 0) {
			system("mode con:cols=143 lines=50");
			index_right = 0;
			drawTable(2, 2);
			drawData(cal_meal, &index_right, &index_left);
		}

	
		keyboard_value = getch();
		
	
	
		
		if (keyboard_value == 224 ) {//화살표 키 누른 경우
			keyboard_value = getch();
			system("mode con:cols=143 lines=50");
			if (not_draw_condition == 1)continue;//표현하고자 할 데이터가 없으면 화살표 입력을 받아도 무시하도록 설정
			switch (keyboard_value) {
			case 77:
				system("cls");
				drawTable(2, 2);
				drawData(cal_meal, &index_right, &index_left);
				//오른쪽
				break;
			case 75:
				system("cls");
				drawTable(2, 2);
				drawData_left(cal_meal, &index_right, &index_left);
				//왼쪽
				break;
			default: continue;

			}
		}

```
프로그램이 돌아가는 주요 부분입니다.

전체 로직은 특정 종료조건을 만족하기 전까지는 무한루프를 돌면서 사용자의 입력을 받습니다.

not_draw_condition이라는 flag 변수값을 통해서 사용자가 처음으로 프로그램을 실행했다면 recently.bin 파일이 없으므로 도움말을 화면에 표시해줍니다.

```c
if (keyboard_value == 8 && not_draw_condition == 0)
```
백스페이스 키를 누르고, not_draw_condition 이라면

화면에 나타내는 전처리 조건 및 과정을 끝내고나면, 사용자로부터 화살표 키 값을 입력받습니다.
만약, 식단값을 생성하지 않았거나, 최근에 프로그램을 실행시킨적이 없다면 continue를 수행하여 화살표 키보드를 눌러도 계속 도움말 초기화면만 표시하도록 하였습니다.

```c
if (not_draw_condition == 1)continue;
```

반대로 표시할 식단 데이터가 있다면 drawTable()함수를 호출하여 캘린더를 커맨드 윈도우에 표시하고, drawData()함수를 통해 식단 데이터들을 알맞게 표시해줍니다.
1년 식단만 표시되야 하므로, 해당년도 1월에서 왼쪽키를 누르면 해당년도 12월로 돌아가야 하기 때문에 index_left와 index_right변수를 사용합니다.

캘린더 라운딩 사진

여기서 주의할 점이 getch()함수를 호출하게 되면 화살표의 경우 버퍼에는 224아스키코드값이 공통으로 저장됩니다. 따라서 getch() 리턴 값이 244라면 getch() 함수를 
한번 더 호출하여 해당 화살표키가 오른쪽인지, 왼쪽인지 구분하게 됩니다.

화살표 방향키 아스키 코드값 확인 사진

```c
else {//여긴 메뉴 버튼
			
			switch (keyboard_value) {
			case 59://랜덤 식단 짜기
				not_draw_condition = 0;
				system("mode con:cols=143 lines=50");
				free(cal_meal);
				cal_meal = (struct meal *)malloc(sizeof(struct meal) * 365);
				input_data(cal_meal, bob, gook, jjige, banchan, bread_meal, noodle);
				drawTable(2, 2);
				index_right = 0;
				drawData(cal_meal, &index_right, &index_left);
				break;

			case 60://건강식 짜기
				not_draw_condition = 0;
				
				free(cal_meal);
				cal_meal = (struct meal *)malloc(sizeof(struct meal) * 365);

				system("mode con:cols=142 lines=15");
				drawSquare(2, 2);
				gotoxy(1, 3);
				printf("성인 하루 일일 권장 섭취 칼로리를 기준으로 식단을 만듭니다.");
				gotoxy(1, 4);
				printf("표준 체중과 작업량을 입력하시면 해당 칼로리미만의 식단을 보여드립니다.");
				gotoxy(1, 5);
				printf("표준 체중을 입력해주세요 : ");
				scanf("%d", &std_weight);
				system("cls");

				system("mode con:cols=142 lines=15");
				drawSquare(2, 2);
				gotoxy(1, 3);
				printf("하루 신체 활동량(작업량을 적어주세요).");
				gotoxy(1, 4);
				printf("평소 운동량이 적은사람(30~32)");
				gotoxy(1, 5);
				printf("하루 한 두시간 운동을 하는 사람(33~36)");
				gotoxy(1, 6);
				printf("힘든 육체 노동을 하는 사람(37~42)");
				gotoxy(1, 7);
				printf("전문적인 운동선수는(43~)");
				gotoxy(1, 8);
				printf("하루 활동량은 ? : ");
				scanf("%d", &work);


				system("mode con:cols=143 lines=50");
				input_healthy_data((std_weight*work)/2, cal_meal, bob, gook, jjige, banchan, bread_meal, noodle);
				drawTable(2, 2);
				index_right = 0;
				drawData(cal_meal, &index_right, &index_left);
				break;
				
```
여기서부터는 키보드 방향키가 아닌 아래와 같은 기능을 하는 키보드 버튼을 눌렀을 경우에 대해 switch-case문으로 처리하는 부분입니다.

1. F1 : 랜덤 식단 짜기

2. F2 : 저칼로리 식단

3. F3 : 음식 추가/삭제

4. F4 : 저장/불러오기

5. F5 : 종료하기


아스키 코드값이 59인 F1키를 눌렀을 경우, 랜덤 식단을 짜게 됩니다.
동적할당을 통해 365개의 식단을 저장할 사용자 정의 구조체 공간을 할당하였고, 실질적으로 랜덤 식단을 짜주는 input_data()함수를 호출합니다.

아스키 코드값이 60인 F2키를 눌렀을 경우, 성인 하루 일일 권장 섭취 칼로리를 기준으로 건강식단을 만듭니다.
사용자로부터 표준 체중, 일일 활동량을 입력 받아 계산한 후 건강 식단을 만드는 input_healthy_data()함수를 호출하여 식단 데이터들을 만듭니다.
마찬가지로 여기에서도 동적할당으로 365개의 식단 데이터 크기를 배정받습니다.
<br>
<br>
<br>


```c
			case 61://음식 검색, 추가및 삭제
				while (1) {

					
					system("mode con:cols=142 lines=15");
					drawSquare(2, 2);
					gotoxy(1, 3);
					printf("음식을 검색하시려면 1을");
					gotoxy(1, 4);
					printf("음식을 삭제하시려면 2를");
					gotoxy(1, 5);
					printf("음식을 추가하시려면 3을 눌러주세요^^7");

					gotoxy(1, 8);
					printf("이전 메뉴로 가시려면 백스페이스(뒤로가기)를 눌러주세요.");


					keyboard_value = getch();
					system("cls");
					drawSquare(2, 2);
					if (keyboard_value == 8)break;//메뉴 검색/추가/삭제 메뉴 빠져나가기
					switch (keyboard_value) {
					case 49: {//1번을 누른 경우

						gotoxy(1, 3);
						printf("찾고자 하는 음식의 이름 : ");
						scanf("%s", tmp_foodname);
						find_food_propertise(food, tmp_foodname);
					}
							 break;
					case 50: {//2번을 누른 경우

						gotoxy(1, 3);
						printf("지우고자 하는 음식의 이름 : ");
						scanf("%s", tmp_foodname);
						i = remover_FoodName(&food, tmp_foodname);
						//i는 제어 변수입니다.
						//성공적으로 데이터를 지웠으면1을, 아니면 0값을 가집니다.
						if (i == 1) {
							remover_LinkedList(&bob);
							remover_LinkedList(&banchan);
							remover_LinkedList(&gook);
							remover_LinkedList(&jjige);
							remover_LinkedList(&noodle);
							remover_LinkedList(&bread_meal);

							distributeFood(food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);

							gotoxy(1, 4);
							printf("해당 음식을 목록에서 지웠습니다!");
							gotoxy(1, 5);
							printf("3초후 음식 추가/검색/삭제 화면으로 돌아갑니다. \n");
							Sleep(1000);
							gotoxy(1, 5);
							printf("2");
							Sleep(1000);
							gotoxy(1, 5);
							printf("1");
							Sleep(1000);
						}
					}
							 break;
					case 51: {//3번을 누른 경우

						gotoxy(1, 3);
						printf("추가할 음식의 이름, 가격, 칼로리순으로 입력해주세요.\n");
						gotoxy(1, 4);
						storeData(&food, &bob, &gook, &jjige, &banchan, &bread_meal, &noodle);
					}
							 break;		
					default:;
					}
```


2. data.c

메인 메뉴들이 적혀있는 음식 파일 menu.txt를 읽어들이고, 이를 구조체 형식으로 바꿉니다.
구조체 데이터들을 이용하여 랜덤 식단과 건강 식단 생성, 새로운 식단 추가 또는 제거, text와 bin형태의 파일로 저장하는 함수들이 정의되어 있습니다.

여기서 생성된 식단들은 링크드 리스트형식으로 관리됩니다.
즉, 12월달에 생성된 각각의 일별 식단들이 링크드 리스트의 노드에 대응됩니다.
 
3. display.c

command window에 보여주는 함수들이 정의되어 있습니다.
사용자가 필요로 하는 기능들을 메인 메뉴형식으로 나타내고, 식단을 캘린더 형식으로 표현해주며, 사용자가 다음 또는 이전달의 식단을 보기 위해 키보드의 방향키를 누르면
그에 맞게 식단을 다시 출력해줍니다.

4. dataset.h
 
정의된 함수에 대한 프로토타입 함수 선언부와 user type 구조체의 정의가 명시되어 있습니다.
여기서 각 식단들이 어떤 형태의 구조체를 가지는지 확인할 수 있습니다.


# C Programming Language

### 1. Dynamic allocation
	동적할당과 관련해서 실수하기 쉬운 부분,
	main에서 동적으로 생성된 변수들을 다른 함수가 처리할 때 저지르기 쉬운 실수 등을 정리


### 2. Void pointer
	


### 3. Generic programming
	


