import java.util.*;

class Loop_Test{
	public static void main(String [] args){
		int i, j, k, number, sum, temp;
		Scanner S = new Scanner(System.in);
		
		number = S.nextInt();
/*		
		for(i = 1; i <= 9; i++){
			for(j = 1 ; j < number; j++)
					System.out.printf("| %d X %d = %2d |",j, i, j*i);
			System.out.println();
		}
		
*/
		sum = 1;
		temp = 1;
		
		//n! 구하기(overflow가 어디서 발생하는지 알아내기)
		for( i = 1 ; i <= number ; i++){
			sum *= i;
			if( temp != (sum/i)){
				System.out.printf("overflow occur! %d번째에 occur", i);
				break;
				}
			else temp = sum;
			
			
			
			
		}
		System.out.printf("%d! = %d", number, sum);
		//overflow는 (n - 1)! != (n!/n) 가 true면 overflow 발생
		
		System.out.println("------------------구	분--------------");
	/*	
		for(i = 0; (i < number) &&( i * number <= 9) ; i++){
			for(j = 1; j <= 9 ; j++){
					for(k = 1 ; k <= number &&	(i*number + k< 10); k++)
						System.out.printf("%d X %d = %2d |",i*number + k, j, (i*number + k)*j);
					
					
				System.out.println();
			}
			System.out.println("------------------------------");
		}			
		//number값이 1일때 1단 구구단만 출력함;;;
		*/
		
		
		for( k = 0; k < number; k++){
		for( i = k + 1 ; i < number; i++)System.out.print(" ");
		for( j = 0 ; j <= k ; j++)System.out.print("*");
		System.out.println();
		}
		System.out.println("\n");
		
		for( i = 0; i < number ; i++){
			for( k = 0; k < i ; k++)System.out.print(" ");
			for( j = 0; j < number - i ; j++)System.out.print("*");
			System.out.println();
		}
		
		System.out.println("\n");
		
		for(i = 0; i < number; i++){
			for(j = 0 ; j < number - i ; j++)System.out.print("*");
			System.out.println();
		}
		
		
		
		
		
		
		
	}
}