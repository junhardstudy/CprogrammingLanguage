/*
	�ڹ� 8����
	while, do-while statement


*/


import java.util.*;

class Condition_Loop{
	public static void main(String [] args){
		int number;
		Scanner S = new Scanner(System.in);
	
		/*
		//while(true) -break �̿�
		while(true){
			number = S.nextInt();
			if(number > 0 && number < 200){
				System.out.println("���̴� "+number+" �� �Դϴ�");
				break;
			}
			else
				System.out.println("error!");
		}
		*/
		
		//for���� �̿�
		for(	;true	;	){
			System.out.print("age : ");
			number = S.nextInt();
			if(number > 0 && number < 200){
				System.out.println("���̴� "+number+" �� �Դϴ�");
				break;
			}
			else
				System.out.println("error!");
		}
	
	
	
	
	
	
	
		/*
		do{
			System.out.print("Age : ");
			number = S.nextInt();
			if(number < 0 || number > 200)System.out.println(number + " isn't correct number!");
		}while(number < 0 || number > 200);
		*/
		
	
	

		/*	
		number = S.nextInt();
		
		while(number < 0 || number > 200){
			System.out.println("error occur!" + number + "is not correct number");
			System.out.print("no!");
			number = S.nextInt();
		}
		
		
		*/
		System.out.println("�Է� �Ͻ� ���̴� :" + number + "�� �Դϴ�");
	}
}