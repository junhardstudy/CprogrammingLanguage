import java.util.*;

class Test{
	public static void main(String [] args){
		double number;
		int integer_number, absolute, temp;
		Scanner S = new Scanner(System.in);
		
		System.out.print("-1000�ʰ�, 1000�̸��� �Ǽ�: ");
		number = S.nextDouble();
		integer_number = (int)number;
		
		System.out.printf("�Է��Ͻ� �Ǽ��� ���� �κ�: %d\n", integer_number);
		
		if((integer_number & 0b10000000000000000000000000000000) == 0) absolute = integer_number;
		else absolute = - integer_number;
		
		
		temp = absolute / 100;
		if(temp > 1)System.out.printf("%d��", temp);
		if(temp == 1)System.out.printf("��");
		absolute %= 100;
	
	
		temp = absolute / 10;
		if(temp > 1)System.out.printf("%d��",temp);
		if(temp == 1)System.out.printf("��");
		absolute %= 10;
				
		if(absolute > 1)System.out.printf("%d",absolute);
		if(absolute == 1)System.out.printf("��");
				
		
		
		
	}
}