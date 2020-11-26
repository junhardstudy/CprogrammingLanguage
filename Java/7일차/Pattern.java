import java.util.*;

class Pattern{
	public static void main(String [] args){
		int number, i, j, k;
		Scanner S = new Scanner(System.in);
		
		number = S.nextInt();
		
		for(i = 0; i <=number/2; i++){
			for(j = 0; j < i; j++)System.out.print(" ");
			for(k = 0; k <number - i*2; k++)System.out.print("*");
			System.out.println();
		}
		
		for(i =1; i<= number/2; i++){
			for(j = 0; j <number/2 - i; j++)System.out.print(" ");
			for(k = 0; k < 1 + 2*i ; k++)System.out.print("*");
			System.out.println();
		}
		System.out.println("------------구	분------------");
		
		for(i = 0; i < number; i++){
			for(j = 0; j < number - 1 -i; j++)System.out.print(" ");
			for(k = 0; k < number; k++)System.out.printf("%3d",number*i + k + 1);
			System.out.println();
		}
		System.out.println("------------구	분-----------");
		
		for(i = 0; i <= number/2 ; i++){
			for(k = 0; k < number/2 - i; k++)System.out.print(" ");
			for(j = 0; j < 1 + 2*i; j++)System.out.print("*");
			System.out.println();
		}
		for(i = 0; i <number/2 ; i++){
			for(j = 0; j < i+1; j++)System.out.print(" ");
			for(k = 0; k < (number - 2) - i*2; k++)System.out.print("*");
			System.out.println();
		}
		System.out.println("-------------구	분-----------");
		
		for(i = 0; i <= number/2 ; i++){
			for(j = 0; j < number/2 - i; j++)System.out.print(" ");
			for(k = 0; k < 1 + 2*i; k++)System.out.printf("%d", Math.abs(i - k));
			System.out.println();
		}
		for(i = 0; i < number/2 ; i++){
			for(j = 0; j < i + 1; j++)System.out.print(" ");
			for(k = 0; k < number - 2*(i+1); k++)System.out.printf("%d", Math.abs(number/2 - (i+k) - 1));
			System.out.println();
		}
		
		
		
		
	}
}