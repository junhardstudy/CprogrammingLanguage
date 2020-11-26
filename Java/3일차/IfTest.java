/*
	조건문에 관하여

*/

import java.util.Scanner;

class IfTest{
	public static void main(String [] args){
		int score, today, after, result;
		String [] pass = {"더미"};//문자열의 배열
		String pass2;//문자열, 저장될때는 c에서 처럼 배열로 저장이 되지만 자바라서 객체 처럼 취급
		Scanner S = new Scanner(System.in);
		
		
		System.out.print("pass or not? :");
		pass2 = S.nextLine();
	//	System.out.println("%d", Integer.parseInt(pass[0]));
	
		
		if(pass2.charAt(0)=='합')System.out.println("1");
		else System.out.println("0");
		//문자열의 경우 call by referrence 이고 문자의 경우 call by value임(문자는 기초 자료형 이기 때문이며 문자열은 참조 자료형이기 때문)
	/*	
		System.out.print("점수 :");
		score = S.nextInt();
		
		
		if(score >= 90) System.out.println("장학금!");
		
		//else if(score < 90 && score >=30) System.out.println("합격!");
		//이미 상단에서 90점이상에 대해서 연산 하였으므로 90점미만 자료들만 남아있음. 굳이 또 90점 이상 데이터를 걸러낼 필요는 없음 따라서
		else if(score >= 30) System.out.println("합격!");
		
		else System.out.println("불합격!");
	/*	
		System.out.print("오늘은 무슨 요일? :");
		S.nextLine();
		today = S.nextLine();
		*/
	
	}
}