import java.util.*;

class I{
	public static void main(String [] args){
		//������ �Ѹ��� ����
		Dog myDog = new Dog();
		Scanner S = new Scanner(System.in);
		
		while(true){
			if(myDog.full < 6){
				System.out.print("���� �����, �� �ֱ� : ");
				myDog.eat(S.nextInt());
			}
			else{
				System.out.println("���� �������� " + myDog.full);
				myDog.play();
				break;
			}
			
			
			
		
		}
	


	/*
		System.out.println("���� ���� ������ : " + myDog.full);
		System.out.printf("���� ���� �̸� : %s", myDog.name);
		myDog.play();
		myDog.eat(5);
		
		
		Dog Second_Dog = new Dog(10, "Ǫ��");
		System.out.println("���ο� �������� ��������"+ Second_Dog.full +" �̸� �̸��� " + Second_Dog.name);
	*/
	
		
	}
}