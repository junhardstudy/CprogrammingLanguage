/*
	java 2일차
	서식 지정자 관련 오라클 문서: https://docs.oracle.com/javase/6/docs/api/java/util/Formatter.html#syntax
	
	서식 지정자 순서 : %[argument_index$][flags][width][.precision]conversion


*/



class NumberTest{
	public static void main(String [] args){
		int a = 0b10;//0b+숫자 : 숫자를 이진수로 해석
		//int b = 0b73; <-컴파일 불가능, 73은 이진수가 아님
		int b = 073; //0+숫자 : 숫자를 팔진수로 해석
		int c = 0x1f; //0x+숫자 : 숫자를 16진수로 해석
		int d = 2_3456_7891;//_는 가독성 높여줌, 컴파일 할때는 없어짐
		
		//b를 8, 10, 16진수 형태로 몇진수인지 까지 붙여서 출력
		
		System.out.printf("8진수 : %-#8o, 16진수 : %1$#-8x, 10진수 : %1$d", b);
		System.out.printf("\n%d", d);
		
		//System.out.format("%x\n", c);
		
		/*
			정수의 서식지정자
			%d = decimal
			%o = octal
			(%h 또는)%x = hexadecimal (%h는 안 먹히는 경우가 있으므로 관례적으로 %x 사용)
			%#conversion인 경우 #이 몇 진수인지 알려줌
			왼쪽정렬인 -인 경우 width가 있을때만 적용가능
		*/
		
		
		 /*
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
		*/
	}
}