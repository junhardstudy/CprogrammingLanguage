import java.util.*;

class ArrayTest{
	public static void main(String [] args){
		int [] scores1 = {1, 5, 3, 6, 3, 7};//�迭�� ���� ������ �̹� ������ ��Ȳ������ {}�� �ʱ�ȭ
		int [] scores2 = new int[5];//�ʱ�ȭ�� �Ǿ� ���� ������ �迭�� ���� ������ �̹� ������ �迭 ����
		int sum = 0;
		
		Scanner S = new Scanner(System.in);
	/*	
		for(int i = 0; i < scores1.length; i++)
			System.out.println(scores1[i]);
		
		for(int i = 0; i < scores2.length; i++){
			System.out.print(i+1 + "��° �л��� ���� : ");
			scores2[i] = S.nextInt();
			sum += scores2[i];
			
		}
		System.out.println(scores2.length + "���� �л��鿡 ���� ����� "+ sum/(double)scores2.length);
		*/
		
		System.out.print("�� ��? : ");
		Car [] myCar = new Car[S.nextInt()];
		
		
		
		Car [] myCar2 = {new Car("abc", 2011), new Car("bcd", 2013), new Car("cde", 2014)};//�̷��Ե� ����
		
		for(int i = 0 ; i < myCar2.length; i++){
			if(i == 1)myCar2[i].name = "���Ϻ�";
		}//�Ʒ��� ���� ǥ�� ����

		
		
		for(int i = 0 ; i < myCar2.length; i++){
			System.out.println(myCar2[i].name);
		}//�Ʒ��� ���� ǥ�� ����
		for(Car myCartmp: myCar2){
			myCartmp.name = "reset";
			System.out.println(myCartmp.name);
		}
		
		
	}
}

class Car{
	String name;
	int year;
	
	Car(){}
	Car(String name, int year){
		this.name = name;
		this.year = year;
	}
}