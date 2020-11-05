#include "dataset.h"


void main() {
	int i, index_right = 0, index_left;//index�� cal_meal�� ��� ǥ���ؾ� ���� �˷��� ��ġ
	int keyboard_value = 0, not_draw_condition;
	char tmp_foodname[16];
	char saved_file_name[21], saved_food_file_name[21];
	int std_weight, work;

	
	system("mode con:cols=143 lines=50");
	system("title �Ĵ�ǥ");

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
	fp = fopen("recently.bin", "rb");//������ ���α׷��� ���� �������� 
		//�� �� �����ϱ� ������ �������Ҵ� �Ĵ��� �ҷ� �ɴϴ�.

	if (fp && file_food_name) {//������ ���α׷��� ������״ٸ�...
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
			printf("ó���̽Ű���?");
			gotoxy(1, 4);
			printf("���ο� �Ĵ��� ¥�ų� �ڽ��� ü�߿� �´� ���� ���� Į�θ� �Ĵ��� © �� �ֽ��ϴ�!");
			gotoxy(1, 5);
			printf("������ �ִ� �Ĵ��� �ҷ����÷��� F4Ű, ���ο� �Ĵ��� ¥�÷��� F1 Ű��, ��Į�θ� �Ĵ��� ¥�÷��� F2Ű�� �����ּ���^^7");

		}
		if (keyboard_value == 8 && not_draw_condition == 0) {
			system("mode con:cols=143 lines=50");
			index_right = 0;
			drawTable(2, 2);
			drawData(cal_meal, &index_right, &index_left);
		}

	
		keyboard_value = getch();
		
	
	
		
		if (keyboard_value == 224 ) {//ȭ��ǥ Ű ���� ���
			keyboard_value = getch();
			system("mode con:cols=143 lines=50");
			if (not_draw_condition == 1)continue;//ǥ���ϰ��� �� �����Ͱ� ������ ȭ��ǥ �Է��� �޾Ƶ� �����ϵ��� ����
			switch (keyboard_value) {
			case 77:
				system("cls");
				drawTable(2, 2);
				drawData(cal_meal, &index_right, &index_left);
				//������
				break;
			case 75:
				system("cls");
				drawTable(2, 2);
				drawData_left(cal_meal, &index_right, &index_left);
				//����
				break;
			default: continue;

			}
		}

		else {//���� �޴� ��ư
			
			switch (keyboard_value) {
			case 59://���� �Ĵ� ¥��
				not_draw_condition = 0;
				system("mode con:cols=143 lines=50");
				free(cal_meal);
				cal_meal = (struct meal *)malloc(sizeof(struct meal) * 365);
				input_data(cal_meal, bob, gook, jjige, banchan, bread_meal, noodle);
				drawTable(2, 2);
				index_right = 0;
				drawData(cal_meal, &index_right, &index_left);
				break;

			case 60://�ǰ��� ¥��
				not_draw_condition = 0;
				
				free(cal_meal);
				cal_meal = (struct meal *)malloc(sizeof(struct meal) * 365);

				system("mode con:cols=142 lines=15");
				drawSquare(2, 2);
				gotoxy(1, 3);
				printf("���� �Ϸ� ���� ���� ���� Į�θ��� �������� �Ĵ��� ����ϴ�.");
				gotoxy(1, 4);
				printf("ǥ�� ü�߰� �۾����� �Է��Ͻø� �ش� Į�θ��̸��� �Ĵ��� �����帳�ϴ�.");
				gotoxy(1, 5);
				printf("ǥ�� ü���� �Է����ּ��� : ");
				scanf("%d", &std_weight);
				system("cls");

				system("mode con:cols=142 lines=15");
				drawSquare(2, 2);
				gotoxy(1, 3);
				printf("�Ϸ� ��ü Ȱ����(�۾����� �����ּ���).");
				gotoxy(1, 4);
				printf("��� ����� �������(30~32)");
				gotoxy(1, 5);
				printf("�Ϸ� �� �νð� ��� �ϴ� ���(33~36)");
				gotoxy(1, 6);
				printf("���� ��ü �뵿�� �ϴ� ���(37~42)");
				gotoxy(1, 7);
				printf("�������� �������(43~)");
				gotoxy(1, 8);
				printf("�Ϸ� Ȱ������ ? : ");
				scanf("%d", &work);


				system("mode con:cols=143 lines=50");
				input_healthy_data((std_weight*work)/2, cal_meal, bob, gook, jjige, banchan, bread_meal, noodle);
				drawTable(2, 2);
				index_right = 0;
				drawData(cal_meal, &index_right, &index_left);
				break;

			case 61://���� �˻�, �߰��� ����
				while (1) {

					
					system("mode con:cols=142 lines=15");
					drawSquare(2, 2);
					gotoxy(1, 3);
					printf("������ �˻��Ͻ÷��� 1��");
					gotoxy(1, 4);
					printf("������ �����Ͻ÷��� 2��");
					gotoxy(1, 5);
					printf("������ �߰��Ͻ÷��� 3�� �����ּ���^^7");

					gotoxy(1, 8);
					printf("���� �޴��� ���÷��� �齺���̽�(�ڷΰ���)�� �����ּ���.");


					keyboard_value = getch();
					system("cls");
					drawSquare(2, 2);
					if (keyboard_value == 8)break;//�޴� �˻�/�߰�/���� �޴� ����������
					switch (keyboard_value) {
					case 49: {//1���� ���� ���

						gotoxy(1, 3);
						printf("ã���� �ϴ� ������ �̸� : ");
						scanf("%s", tmp_foodname);
						find_food_propertise(food, tmp_foodname);
					}
							 break;
					case 50: {//2���� ���� ���

						gotoxy(1, 3);
						printf("������� �ϴ� ������ �̸� : ");
						scanf("%s", tmp_foodname);
						i = remover_FoodName(&food, tmp_foodname);
						//i�� ���� �����Դϴ�.
						//���������� �����͸� ��������1��, �ƴϸ� 0���� �����ϴ�.
						if (i == 1) {
							remover_LinkedList(&bob);
							remover_LinkedList(&banchan);
							remover_LinkedList(&gook);
							remover_LinkedList(&jjige);
							remover_LinkedList(&noodle);
							remover_LinkedList(&bread_meal);

							distributeFood(food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);

							gotoxy(1, 4);
							printf("�ش� ������ ��Ͽ��� �������ϴ�!");
							gotoxy(1, 5);
							printf("3���� ���� �߰�/�˻�/���� ȭ������ ���ư��ϴ�. \n");
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
					case 51: {//3���� ���� ���

						gotoxy(1, 3);
						printf("�߰��� ������ �̸�, ����, Į�θ������� �Է����ּ���.\n");
						gotoxy(1, 4);
						storeData(&food, &bob, &gook, &jjige, &banchan, &bread_meal, &noodle);
						


					}
							 break;


					
					default:;


					}







				}
					break;
				
			case 62://�����ϱ�/ �ҷ�����

				system("cls");
				system("mode con:cols=142 lines=15");
				drawSquare(2, 2);
				gotoxy(1, 3);
				printf("�Ĵ��� �����Ͻ÷��� 1����");
				gotoxy(1, 4);
				printf("�Ĵ��� �ҷ����÷��� 2���� �����ּ���^^7");
				
				gotoxy(1, 6);
				printf("���� �޴��� ���÷��� �齺���̽�(�ڷΰ���)�� �����ּ���.");
				keyboard_value = getch();

				switch (keyboard_value) {
				case 49://�Ĵܰ� �������� ����
					
					system("mode con:cols=142 lines=15");
					drawSquare(2, 2);
					gotoxy(1, 3);
					if (not_draw_condition == 1) {
						//�Ĵ��� �������� �ʰ� �����Ϸ��� ���� ���� ���
						printf("�����Ͻ÷��� �Ĵ��� ���� ���� �� �ּ���!");
						gotoxy(1, 5);
						printf("3���� ����ȭ������ ���ư��ϴ�. \n");
						Sleep(1000);
						gotoxy(1, 5);
						printf("2");
						Sleep(1000);
						gotoxy(1, 5);
						printf("1");
						Sleep(1000);
						continue;
					}
					printf("�����Ͻ� ������ �̸��� �����ּ���\n");
					gotoxy(1, 4);
					scanf("%s", saved_file_name);
					strcpy(saved_food_file_name, saved_file_name);
					fflush(stdin);
					strcat(saved_file_name, ".bin");
					strcat(saved_food_file_name, "_food.bin");

					writeAtFile(saved_file_name, cal_meal, 2);
					writeAtFile(saved_food_file_name, food, 1);

					gotoxy(1, 5);
					printf("�����߽��ϴ�!");
					gotoxy(1, 6);
					printf("3���� ����ȭ������ ���ư��ϴ�. \n");
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

				case 50://�Ĵܰ� �������� �ҷ�����
					
					system("mode con:cols=142 lines=15");
					drawSquare(2, 2);
					gotoxy(1, 3);
					printf("�ҷ��� ������ �̸��� �����ּ���\n");
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
					//�б� ���� �޸𸮿� ����Ǿ� �ִ� ���Ḯ��Ʈ�� �� ��������.
					
					readFrBinFile(saved_file_name, cal_meal, 2);
					readFrBinFile(saved_food_file_name, &food, 1);
					
					
					if (food != NULL) {//�����͸� ���������� �о��ٸ�
						not_draw_condition = 0;





						distributeFood(food, &bob, &gook, &banchan, &jjige, &bread_meal, &noodle);
						
						system("mode con:cols=143 lines=50");
						drawTable(2, 2);
						index_right = 0;
						drawData(cal_meal, &index_right, &index_left);
						
					}
					else {//�����͸� �� ����
						system("mode con:cols=142 lines=15");
						drawSquare(2, 2);
						gotoxy(1, 3);
						printf("�ش� ������ ���ų� ���α׷��� ������ �־� ������\n");
						gotoxy(1, 4);
						printf("�о� �� �� �����ϴ�.... \n");
						gotoxy(1, 5);
						printf("3���� ����ȭ������ ���ư��ϴ�. \n");
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
			case 63://�����ϱ�
				
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
				//����ڰ� �Ĵ��� �� ¥�� �ٷ� ���α׷��� ���� �ϴ� ���
				//�����͸� �������� ���ƾ���.

				system("cls");
				gotoxy(1, 1);
				printf("���α׷��� �����մϴ�.");
				Sleep(1500);
				exit(0);
				break;
			default: continue;
			}

		}


	
		
	} 

	



	
}


