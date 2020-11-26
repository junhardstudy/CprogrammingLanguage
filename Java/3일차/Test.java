/*첫번째 과제


*/

import java.util.Scanner;


class Test{
	public static void main(String [] args){
		int num1, num2;
		Scanner S = new Scanner(System.in);
		
		System.out.print("첫번째 양의 정수 :");
		num1 = S.nextInt();
		System.out.print("두번째 양의 정수 :");
		num2 = S.nextInt();
		System.out.print("\n");
		
		System.out.printf("%-11s|%-11s|%-11s|%-11s|\n", "number", "deciaml", "octal", "hexadecimal");
		System.out.printf("%-11s|%+11d|%2$#11o|%2$#11x|\n", "number 1", num1);
		System.out.printf("%-11s|%+11d|%2$#11o|%2$#11x|\n", "number 2", num2);
		System.out.printf("%-11s|%-+11d|%2$-#11o|%2$-#11x|\n", "sum", num1 + num2);
	}
}