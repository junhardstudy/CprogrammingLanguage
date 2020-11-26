import java.util.*;

class Gcd{
	public static void main(String [] args){
		int num1, num2, temp;
		Scanner S = new Scanner(System.in);
		
		System.out.print("plz insert two digit :");
		num1 = S.nextInt();
		num2 = S.nextInt();
		
		if(num2 > num1){
			temp = num1;
			num1 = num2;
			num2 = temp;
		}//큰 수, 작은 수 구분
		
		while(true){
			if(num2 == 0){
				System.out.print("gcd number is : "+num1);
				break;
			}
			temp = num1 % num2;	
			num1 = num2;
			num2 = temp;
			
		}
		
		
	}
}