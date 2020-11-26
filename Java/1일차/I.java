/*
	1.method는 소문자로 시작
	
	2.두 단어 이상의 합성어는 두번째 단어에서 대문자로 시작
	
	3.class는 대문자로 시작

*/


import java.util.Scanner;

class I{//class 클래스명(첫글자는 항상 대문자)
	public static void main(String [] args){
	String name;//사용자가 입력한 이름을 저장할 변수(메모리 공간)
	double height;//키를 저장할 변수 (메모리 공간) 확보
	int age;
	String phnumber;
	int year;
	double grade;
	
	Scanner Sc = new Scanner(System.in);
	//키보드로부터 값을 읽어오는 스캐너 생성
	//System.in = 표준 입력인 키보드를 의미.
	
	//System.out.print("이름:");
	//name = Sc.nextLine();//커맨드라인에서 한 라인 읽어옴.
	
	//System.out.printf("당신의 이름은 %s 입니다.\n", name);
	/*
	System.out.print("키:");
	height = Sc.nextDouble();//실수 읽어옴
	
	System.out.print("나이:");
	age = Sc.nextInt();
	
	System.out.printf("키:%.2f, 나이:%d\n",height, age);
	*/
	
	System.out.print("전화 번호:");
	phnumber = Sc.nextLine();
	System.out.print("학년:");
	year = Sc.nextInt();
	System.out.print("학점:");
	grade = Sc.nextDouble();
	
	System.out.printf("Phone number :%s\n학년:%d\n학점:%.3f",phnumber, year, grade);
	
		
		
		
		
	/*	
		
		System.out.println("fromln");//println:개행있음
		System.out.printf("Hellow\n");//printf:개행없음
		System.out.format("fromformat\n");//.format은 .printf와 유사
		System.out.printf("%d\n",6+8);//printf에서 f는 출력format(형식)을 지정함을 의미
		
		System.out.println(2+1);
		
		//System.out <- 표준 출력:모니터
		
		
		System.out.printf("Name:%s Height:%.3f Age:%d\n","kim", 174.12345, 24);
		//이름(문자열), 키(실수), 나이(정수)순으로 printf를 이용해서 출력format
		
	*/	
		
	}
}