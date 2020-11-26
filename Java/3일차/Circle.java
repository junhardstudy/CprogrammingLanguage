/*
	자바 3일차
	final 키워드를 이용한 상수화 시키기
	Math클래스의 메소드, 필드


*/

import java.util.Scanner;

class Circle{
	public static void main(String [] args){
		double radius, length, surface;
		//final double PI = 3.14;//final = 상수화시킴 따라서 하단코드에서부터는 pi값 변경 불가
		
		Scanner S = new Scanner(System.in);
		
		
		//코사인 0 값, 루트 0 출력하기 출력 해보기
		System.out.format("%.2f\n", Math.cos(0));
		System.out.format("%.2f\n", Math.sqrt(0));
		
		
		
		/*random() method 연습
			random() method는 0.0이상 1.0미만 수 return
		*/
		
		System.out.format("%f", Math.random()*10);
		
		
		
		
		
		
		System.out.print("반지름 :");
		radius = S.nextDouble();
		
		length = 2*Math.PI*radius;
		surface = Math.PI*Math.pow(radius, 2);
		//Math 클래스는 java.lang 패키지안에 존재하며(java.lang.Math)  java.lang 패키지안에 속한 클래스는 imort 없이 사용가능.
		
		System.out.printf("둘레 : %.3f, 넓이 : %.3f", length, surface);
	}
} 