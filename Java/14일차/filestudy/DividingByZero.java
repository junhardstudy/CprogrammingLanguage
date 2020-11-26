import java.util.*;

class DividingByZero{
	public static void main(String [] args)throws ArithmeticException{
		System.out.println("statement before method");
		div();
		System.out.println("statement after method");
		
	}
	
	static void div()throws ArithmeticException{
		Scanner S = new Scanner(System.in);
		int a, b;
		a = S.nextInt();
		b = S.nextInt();
		
		//try-catch{}이용시 직접적으로 예외 처리 가능
		System.out.printf("%d / %d = %d\n",a, b, a/b);		
	
		
		
		System.out.println("statement int anothermethod");

	}
}


/*
	예외 처리 방법
	1.직접 처리 : try-catch문 이용
	2.다른 사람에게 부탁하기 : 떠넘기기 : throws , 호출한 곳에서 예외를 받게 됨, main에서도 떠 넘기면 처리할 곳이 아무도 없기에 예외 처리가 실질적으로 안되고 비정상 프로그램 종료




*/