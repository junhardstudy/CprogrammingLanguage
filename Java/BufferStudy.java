/*
	java 2일차
	서식 지정자 관련 오라클 문서: https://docs.oracle.com/javase/6/docs/api/java/util/Formatter.html#syntax
	
	서식 지정자 순서 : %[argument_index$][flags][width][.precision]conversion
	
	버퍼랑 자료형 크기및 overflow와 underflow에 대한 내용
	식별자 관례및 개행 문자 몇개 소개



*/

import java.util.Scanner;
//Scanner 클래스는 자바에서 기본적으로 제공: 스캔 용도
//java.util이라는 패키지 안에 Scanner 클래스가 존재
//패키지 = 폴더

class BufferStudy{
	public static void main(String [] args){
		//초기화 = 값을 처음 대입
		int num;
		//메모리상에서 정수를 저장할수 있는 4바이트의 공간이 확보되고, 그 메모리 공간의 이름을 i라고 붙여줌, 추후에 저장된 값은 정수로 해석함을 의미.
		double flo;
		//8바이트 확보
		String str;
		Scanner Sc = new Scanner(System.in);
		//자료형 식별자(변수이름); <- 변수 선언
		
		/*
		기초 자료형
		-정수형: byte(1byte), short(2byte), int(4byte), long(8byte)
		-실수형: float(4byte, 유효 숫자 7 ~ 8자리 표현 가능), double(8byte, 유효 숫자 15 ~ 16자리 표현 가능) : 정밀도때문에 byte수가 나뉨
		-문자형: char <- 문자 하나 저장가능('a', '각', '으' ...) 2byte할당
		-논리형: boolean <-(true, false) 1bit로 표현이 가능하나 메모리상에서는 1bit 할당이 안되기에 1byte로 할당
		
		표현할 수 있는 자료의 종류가 많기에 자료형의 종류도 다양함
		참고)자바에서는 unsigned 지원 안함
		
		자료의 크기가 표현할 수 있는 자료형의 크기를 벗어날때는 overflow 발생
		underflow는 실수형에서 정밀도를 상실함을 의미
		
		식별자 관례
			1.클래스명은 대문자로 시작
			2.메소드, 변수명은 소문자로 시작
			3.두 단어 이상의 합성어는 두 번째 단어 첫글자는 대문자로 시작(예)nextInt
			
		*/
		
		char c = '밥';
		boolean b = true;
		boolean b1 = 2>3;//조건부로도 대입 가능, 이 때 값은 false
		System.out.println(b + "\t" + b1 + "\t" + c);
		
		
		
		System.out.print("정수: ");
		num = Sc.nextInt();//스캐너에게 정수 하나 읽어달라고 요청
		
		/*
			버퍼상에 엔터가 남아 있어서 문자열 str에 키보드로부터 값을 가져올 수 가 없음.
			따라서 버퍼에 있는 엔터를 지우기 위해 .nextLine();메서드 호출
		*/
		//Sc.nextLine();
		//해줄 필요 없음. nextDouble()메서드에서는 가장 처음으로 만나는 실수값을 찾기 때문에 
		System.out.print("실수: ");
		flo = Sc.nextDouble();
		
		Sc.nextLine();//버퍼상에 있는 엔터값 가져감.
		
		System.out.print("문자열: ");
		str = Sc.nextLine();//스캐너에게 라인 하나 읽어달라고 요청
		
		System.out.println("입력 문자열: "+str+", 입력 정수: "+num +", 입력 실수 :" +flo);
		//println() 메서드에서 변수 값들을 출력하고자 하는 경우 +이용
		
		System.out.print("abc"+"def");
		//print() 메서드의 경우에서도 문자열들을 붙여 출력 하고자 하는 경우 +이용
		
		
		/*
			제어문자 종류
			\n : 개행
			\t : 탭만큼 간격 띄움
			\b : 커서 한칸 이동
			\r : 커서 맨 앞칸으로 이동
			제어문자는 모든 출력메서드에서 사용 가능
		*/
		
		System.out.println("경북\b대");//'북'자리에 커서가 가서 대를 덮어씌움
		System.out.println("경북\b");//'경북' 그대로 표시
			
	}
	
}