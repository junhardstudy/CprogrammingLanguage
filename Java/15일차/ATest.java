import java.util.*;

class ATest{
	public static void main(String [] args){
		Scanner S = new Scanner(System.in);
		int age;
		int divide;
		System.out.print("���� : ");
		try{
		age = S.nextInt();
		
		System.out.printf("����� ���̴� %d�� �Դϴ�.\n", age);
		
		System.out.print("what number divided ? :");
		divide = S.nextInt();
		
		System.out.printf("%d / %d = %d\n", age,divide, age/divide);
		/*
		}catch(Exception e){
			//� ���ܰ� �߻��ؼ� �������� �𸣱⶧���� ���� ó���� � ������ �ؾ����� �ۼ��ϱ� ����� : ����
		}
		*/
		}catch(InputMismatchException ime){
			System.out.print("wrong ���� !");
			return;
		}catch(ArithmeticException ae){
			System.out.print("not divide by zero!");
			return;
		}finally{
			System.out.println("�� ������ �ݵ�� �����");
		}
		
		

		
		
	}
}