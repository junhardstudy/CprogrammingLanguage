/*
	Homework #3

*/

import java.util.*;

class HW_3{
	public static void main(String [] args){
		double x1, x2, y1, y2;
		Scanner S = new Scanner(System.in);
		
		x1 = S.nextDouble();
		y1 = S.nextDouble();
		x2 = S.nextDouble();
		y2 = S.nextDouble();
		
		if(x2 - x1 <= 0 || y2 - y1 <= 0){
			System.out.println("statement erro");
			return;
		}			
		System.out.printf("closed line distance : %.1f, surface area : %.1f\n",2*((x2 - x1) + (y2 - y1)), (x2 - x1)*(y2 - y1)); 
		
		
		//-----------------------------��	��-----------------------
		
		int number, rest;
		
		number = S.nextInt();
		
		
		if((number & 16777216) == 0)System.out.println("positive number");
		else {
				System.out.println("negative number");
				number = -number;
				//������ ��쿡���ؼ��� ��ȣ �ٲ������
				//�ٲ��� ���� ��� ������ ���ؼ� ��ȣ ��Ʈ�� ������ ���� ��� �߸��� �� ���
		}
		//0x80000000 ���� ���Ͽ� decimal���·� ��
		
		if((number & 0b10000000000000000000000000000000) == 0)System.out.println("positive number");
		else {
			System.out.println("negative number");
			number = -number;
		}
		//0x80000000 ���� ���Ͽ� binary���·� ��
		
		rest = number & 0b111;
		System.out.printf("rest = %d\n", rest);
		System.out.printf("�Ǵ� decimal ���·� �� rest = %d\n", number&7 );
		
		

		
		
		
		
		
	}
}