//�������� ��ų�(������ > 6) ���������� �� �ֱ�(������ <=6)
//�������� ��ų� ���������� �� �ֱ�
//������ ��ü => ������ Ŭ����(���赵)

//��ĳ�� ��ü => ��ĳ�� Ŭ����(���赵)�� ���� ������
//Scanner S = new Scanner(System.in);


class Dog{//������ ���赵
		//��������� ������ �־�� �� �Ӽ��� ������ ���
		//�߻�ȭ�� ��ħ:���α׷����� �ʿ��� �Ӽ��� ���۸��� ����(�߻�ȭ)
		//�Ӽ�: �ʵ�(���⼱ full�� name�̶�� �ʵ尡 ����)
		//�ʵ�� ���� �ʱ�ȭ�� ���� �ʴ´ٸ� �ڷ����� �´��� 0���� �ʱ�ȭ ��.
		
		
		int full;
		String name;
		int num;
		//������ : Ư���� �޼ҵ�� ��ü�� �����Ҷ��� ȣ�� ������ �޼ҵ�, �޼ҵ� ��� ������ ��ȯ Ÿ���� ������ Ŭ���� �̸��� ����
		
		Dog(){}//������: �Ű������� ���� ������; ����Ʈ ������;
		
		
		Dog(int i, String s){
			full = i;
			name = s;
		}//�¾�� �̸��� �������� �����ϴ� ������
		
		
		
		//����: �޼ҵ�� �ۼ�
		
		//�Ʒ��� ��� �޼ҵ�
		void play(){
			//��� ����
			System.out.println("����ִ�.");
			full--;
		}
		//�Դ� �޼ҵ�
		void eat(int food){
			//food������ŭ ������ ������Ű��, �߸Ծ��ٰ� ���
			if(food <= 0)System.out.println("no food;;");
			else {
				full += food;
				System.out.println("�߸���");
			}
			
		}
		
		void eatwhatfood(String food_foodname, int num){
			if(food_foodname.length() <= 0){
				System.out.print("���� ������ ���ڶ�!");
				return;
			}
			else System.out.printf("%s(��)�� %d�� ����\n", food_foodname, num);
			
		}
		
		
	
}





