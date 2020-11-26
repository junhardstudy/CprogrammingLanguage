/*
	자바 8일차
	while, do-while statement


*/


import java.util.*;

class Condition_Loop{
	public static void main(String [] args){
		int number;
		Scanner S = new Scanner(System.in);
	
		/*
		//while(true) -break 이용
		while(true){
			number = S.nextInt();
			if(number > 0 && number < 200){
				System.out.println("나이는 "+number+" 세 입니다");
				break;
			}
			else
				System.out.println("error!");
		}
		*/
		
		//for문을 이용
		for(	;true	;	){
			System.out.print("age : ");
			number = S.nextInt();
			if(number > 0 && number < 200){
				System.out.println("나이는 "+number+" 세 입니다");
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
		System.out.println("입력 하신 나이는 :" + number + "세 입니다");
	}
}