/*
	자바 4일차
	
	
	
*/

import java.util.*;


class Pass{
	public static void main(String [] args){
		Scanner Sc = new Scanner(System.in);
		String str;
		
		str = Sc.nextLine();
		
		/*
		if(str == "합격")System.out.println("1");
		else if(str == "불합격")System.out.println("0");
		else System.out.println("syntax error!");
		
		str의 문자열에 해당하는 주소값을 비교하기에 문자열 비교에는 올바르지 못한 구문
		*/
		
		if(str.equals("합격"))System.out.println("1");
		else if(str.equals("불합격"))System.out.println("0");
		else System.out.println("syntax error!");
		
		//문자열 비교에는 .equals 메서드를 이용하거나 switch-case문 사용
		while(true){
		System.out.printf("%d",Random.nextInt());
		Thread.sleep(900);
		}
		
		//임의의 수에 대해서 고정된 상수로 나눌경우
		
		
		
	}
}