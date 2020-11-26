import java.util.*;

class Find_avg{
	public static void main(String [] args){
		int count = 0, number, sum = 0;
		Scanner S = new Scanner(System.in);
		
		
		do{
			System.out.print("number : ");
			number = S.nextInt();
			if(number < 0 )break;
			else if(number%5 == 0)continue;
			else {
				sum += number;
				count++;
			}
			
		}while(true);
		
		if(count > 0)System.out.printf("average is %10.4f \n\n", (double)sum/count);
		
		int n = 12;
		
		while(n>0){
			n -= 2;
			if(n == 6)continue;
			System.out.println(n);
			
		}
		
		
		
		
	}
	
}