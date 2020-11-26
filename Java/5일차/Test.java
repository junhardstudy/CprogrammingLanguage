/*
	자바 5일차


*/


import java.util.*;

class Test{
	public static void main(String [] args){
		int number, sign, a, b, maxnum;
		Scanner S = new Scanner(System.in);
		
		a = S.nextInt();
		b = S.nextInt();
		
	//	a > b ? System.out.printf("max : %d", a):System.out.printf("max : %d", b);
	// java에서는 안되는 구문
	
	
	maxnum = a>b ? a : b;	
	System.out.printf("%d", maxnum);
		
		
	/*	
		System.out.print("integer : ");
		number = S.nextInt();
		
		
		if(number > 0)sign = 1;
		else if(number == 0)sign = 0;
		else sign =-1;
		
		System.out.format("sign = %d\n", sign);
	*/
	}
}