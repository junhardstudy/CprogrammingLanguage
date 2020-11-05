#include "dataset.h"


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







				}
					break;
				
			case 62://저장하기/ 불러오기

				system("cls");
				system("mode con:cols=142 lines=15");
				drawSquare(2, 2);
				gotoxy(1, 3);
				printf("식단을 저장하시려면 1번을");
				gotoxy(1, 4);
				printf("식단을 불러오시려면 2번을 눌러주세요^^7");
				
				gotoxy(1, 6);
				printf("이전 메뉴로 가시려면 백스페이스(뒤로가기)를 눌러주세요.");
				keyboard_value = getch();

				switch (keyboard_value) {
				case 49://식단과 음식파일 저장
					
					system("mode con:cols=142 lines=15");
					drawSquare(2, 2);
					gotoxy(1, 3);
					if (not_draw_condition == 1) {
						//식단을 생성하지 않고 저장하려는 예외 사항 고려
						printf("저장하시려면 식단을 먼저 생성 해 주세요!");
						gotoxy(1, 5);
						printf("3초후 메인화면으로 돌아갑니다. \n");
						Sleep(1000);
						gotoxy(1, 5);
						printf("2");
						Sleep(1000);
						gotoxy(1, 5);
						printf("1");
						Sleep(1000);
						continue;
					}
					printf("저장하실 파일의 이름을 적어주세요\n");
					gotoxy(1, 4);
					scanf("%s", saved_file_name);
					strcpy(saved_food_file_name, saved_file_name);
					fflush(stdin);
					strcat(saved_file_name, ".bin");
					strcat(saved_food_file_name, "_food.bin");

					writeAtFile(saved_file_name, cal_meal, 2);
					writeAtFile(saved_food_file_name, food, 1);

					gotoxy(1, 5);
					printf("저장했습니다!");
					gotoxy(1, 6);
					printf("3초후 메인화면으로 돌아갑니다. \n");
					Sleep(1000);
					gotoxy(1, 6);
					printf("2");
					Sleep(1000);
					gotoxy(1, 6);
					printf("1");
					Sleep(1000);

					system("mode con:cols=143 lines=50");
					drawTable(2, 2);
					index_right = 0;
					drawData(cal_meal, &index_right, &index_left);

					break;

				case 50://식단과 음식파일 불러오기
					
					system("mode con:cols=142 lines=15");
					drawSquare(2, 2);
					gotoxy(1, 3);
					printf("불러올 파일의 이름을 적어주세요\n");
					gotoxy(1, 4);
					scanf("%s", saved_file_name);
					strcpy(saved_food_file_name, saved_file_name);
					fflush(stdin);
					strcat(saved_file_name, ".bin");
					strcat(saved_food_file_name, "_food.bin");

					remover_LinkedList(&food);
					remover_LinkedList(&bob);
					remover_LinkedList(&banchan);
					remover_LinkedList(&gook);
					remover_LinkedList(&jjige);
					remover_LinkedList(&noodle);
					remover_LinkedList(&bread_meal);
					//읽기 전에 메모리에 적재되어 있던 연결리스트는 다 지워야함.
					
					readFrBinFile(saved_file_name, cal_meal, 2);
					readFrBinFile(saved_food_file_name, &food, 1);
					
					
					if (food != NULL) {//데이터를 정상적으로 읽었다면
						not_draw_condition = 0;





						distributeFood(food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);
						
						system("mode con:cols=143 lines=50");
						drawTable(2, 2);
						index_right = 0;
						drawData(cal_meal, &index_right, &index_left);
						
					}
					else {//데이터를 못 읽음
						system("mode con:cols=142 lines=15");
						drawSquare(2, 2);
						gotoxy(1, 3);
						printf("해당 파일이 없거나 프로그램상에 문제가 있어 파일을\n");
						gotoxy(1, 4);
						printf("읽어 올 수 없습니다.... \n");
						gotoxy(1, 5);
						printf("3초후 메인화면으로 돌아갑니다. \n");
						Sleep(1000);
						gotoxy(1, 5);
						printf("2");
						Sleep(1000);
						gotoxy(1, 5);
						printf("1");
						Sleep(1000);

						not_draw_condition = 1;
						continue;
					}
					
					
					break;
				default:;
				}


				break;
			case 63://종료하기
				
				if (not_draw_condition == 0) {
					writeAtFile("recently.bin", cal_meal, 2);
					writeAtFile("recently_food.bin", food, 1);

					remover_LinkedList(&food);
					remover_LinkedList(&bob);
					remover_LinkedList(&banchan);
					remover_LinkedList(&gook);
					remover_LinkedList(&jjige);
					remover_LinkedList(&noodle);
					remover_LinkedList(&bread_meal);
					
				}
				//사용자가 식단을 안 짜고 바로 프로그램을 종료 하는 경우
				//데이터를 저장하지 말아야함.

				system("cls");
				gotoxy(1, 1);
				printf("프로그램을 종료합니다.");
				Sleep(1500);
				exit(0);
				break;
			default: continue;
			}

		}


	
		
	} 

	



	
}


