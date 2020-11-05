# 개요

* 한 학기 동안 배운 내용을 바탕으로 만든 project 입니다.

* 식단을 랜덤으로 짜주는 프로그램입니다.

* 식단을 랜덤으로 짤 때, 필요한 음식들의 이름을 가지고 밥, 국, 면, 빵, 찌개등등의 카테고리로 분류한다음 중복된 음식이 없도록 식단을 생성합니다.

* 또한 하루전에 나왔던 음식이 다음날에는 나오지 않도록 하여 식단이 물리는 상황을 방지하였습니다.

* gotoxy()함수를 이용해 캘린더 형식으로 식단을 넘겨 볼 수 있습니다.

* 식단 데이터들은 구조체이며, 전체 자료 구조는 링크드 리스트 형태 입니다.

***

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
	


