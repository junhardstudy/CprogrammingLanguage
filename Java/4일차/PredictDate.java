/*
	자바 4일차


	else if이나 switch case문의 경우
	컴파일러가 예외 상황을 고려 하지 못하기에
	else if는 항상 else로 끝내고
	switch case는 항상 default로 끝낼것
	
	자바 1주차 강의 자료 중간 점검 문제1&2 답
	
	자바 프로그램의 개발단위는 클래스
	모든 자바 소스 파일의 확장자는 .java
	프로그램에서 데이터를 저장하는 공간은 변수
	변수에 값을 저장하는 연산은 대입 이라함
	실행도중에 값이 변하지 않는 수를 final 상수
	
	1.short
	2.short
	3.2^-2
	4.28.9
	5.true, false
	6.변수에 새로운 값이 대입되면 기존 값은 없어짐
	7.변수명은 대소문자 구분, 따라서 아님
	8.숫자가 먼저 오는 2번째, 특수기호가 먼저 오는 6번째
	
*/




import java.util.*;


class PredictDate{
	public static void main(String [] args){
		String str;
		int after, today, result;
		Scanner Sc = new Scanner(System.in);
		
		System.out.print("오늘은 ");
		str = Sc.nextLine();
		System.out.print("몇 일 후?");
		after = Sc.nextInt();
		
		
		switch(str){
			case "월요일": today = 0; break;
			case "화요일": today = 1; break;
			case "수요일": today = 2; break;
			case "목요일": today = 3; break;
			case "금요일": today = 4; break;
			case "토요일": today = 5; break;
			case "일요일": today = 6; break;
			default : System.out.println("error"); return;
		}
		
		result = (today + after) % 7;
		
		switch(result){
			case 0: System.out.printf("%d일 후는 월요일", after); break;
			case 1: System.out.printf("%d일 후는 화요일", after); break;
			case 2: System.out.printf("%d일 후는 수요일", after); break;
			case 3: System.out.printf("%d일 후는 목요일", after); break;
			case 4: System.out.printf("%d일 후는 금요일", after); break;
			case 5: System.out.printf("%d일 후는 토요일", after); break;
			case 6: System.out.printf("%d일 후는 일요일", after); break;
			default : System.out.println("error"); return;
		}
		
		
	}
}