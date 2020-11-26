/*
	static 메서드에서는 non-static 메서드를 참조 할 수 없음

	중복정의(overload):이름이 같으나 시그니쳐(메소드 이름 + 매개 변수)가 다른 경우

*/


import java.util.*;


class Mathod_Test{
	public static void main(String [] args){
		int a, b, digit;
		String str;
		Scanner S = new Scanner(System.in);
		
		
		digit = sum(2, 5);
		System.out.printf("%d와 %d의 합은 %d입니다.\n", 2, 5, sum(2, 5));
		tvWork(S.nextLine());
		
		
		
		System.out.print("자판기에서 받은 거 : "+ vendingWork(S.nextLine()));
		System.out.println(sum(4.4, 34, 6.5, 35, 6.78));
	}
	//sum() 메서드는 합만 구하고 메인에서 자유자재로 합을 이용하고 싶음.
	
	
	static int sum(int a, int b){
		return a+b;
	}
	//매개변수는 실수 탑입, 인자가 몇개인지는 지정하지 않음, 합을 반환하는 sum() 메소드
	
	static double sum(double... d){//sum(2, 3, 4) => d = 2, 3, 4
		double sum = 0;
		for(double elt:d){//d의 원소가 차례로 elt에 복사됨.
			//for(:배열명)
			sum += elt;
			
		}
		return sum;	
	}
	
	
	
	
	
	
	
	
	
	static void tvWork(String channel){
		System.out.println("현재 채널" + channel);
	}
	
	static String vendingWork(String beverage){
			
			return beverage;
	}
	
	
	
	
	
	/*
	static void sum(int a, int b){//mathod 정의
		System.out.printf("%d + %d = %d", a, b, a+b);
		
	}
	*/
}