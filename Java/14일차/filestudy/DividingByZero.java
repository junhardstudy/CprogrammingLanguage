import java.util.*;

class DividingByZero{
	public static void main(String [] args)throws ArithmeticException{
		System.out.println("statement before method");
		div();
		System.out.println("statement after method");
		
	}
	
	static void div()throws ArithmeticException{
		Scanner S = new Scanner(System.in);
		int a, b;
		a = S.nextInt();
		b = S.nextInt();
		
		//try-catch{}�̿�� ���������� ���� ó�� ����
		System.out.printf("%d / %d = %d\n",a, b, a/b);		
	
		
		
		System.out.println("statement int anothermethod");

	}
}


/*
	���� ó�� ���
	1.���� ó�� : try-catch�� �̿�
	2.�ٸ� ������� ��Ź�ϱ� : ���ѱ�� : throws , ȣ���� ������ ���ܸ� �ް� ��, main������ �� �ѱ�� ó���� ���� �ƹ��� ���⿡ ���� ó���� ���������� �ȵǰ� ������ ���α׷� ����




*/