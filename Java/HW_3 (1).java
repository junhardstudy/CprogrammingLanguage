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
		
		
		//-----------------------------구	분-----------------------
		
		int number, rest;
		
		number = S.nextInt();
		
		
		if((number & 16777216) == 0)System.out.println("positive number");
		else {
				System.out.println("negative number");
				number = -number;
				//음수인 경우에대해서는 부호 바꿔줘야함
				//바꾸지 않을 경우 음수에 대해서 부호 비트로 나머지 구할 경우 잘못된 값 출력
		}
		//0x80000000 값에 대하여 decimal형태로 비교
		
		if((number & 0b10000000000000000000000000000000) == 0)System.out.println("positive number");
		else {
			System.out.println("negative number");
			number = -number;
		}
		//0x80000000 값에 대하여 binary형태로 비교
		
		rest = number & 0b111;
		System.out.printf("rest = %d\n", rest);
		System.out.printf("또는 decimal 형태로 비교 rest = %d\n", number&7 );
		
		

		
		
		
		
		
	}
}