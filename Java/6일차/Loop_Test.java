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
		
		//n! ���ϱ�(overflow�� ��� �߻��ϴ��� �˾Ƴ���)
		for( i = 1 ; i <= number ; i++){
			sum *= i;
			if( temp != (sum/i)){
				System.out.printf("overflow occur! %d��°�� occur", i);
				break;
				}
			else temp = sum;
			
			
			
			
		}
		System.out.printf("%d! = %d", number, sum);
		//overflow�� (n - 1)! != (n!/n) �� true�� overflow �߻�
		
		System.out.println("------------------��	��--------------");
	/*	
		for(i = 0; (i < number) &&( i * number <= 9) ; i++){
			for(j = 1; j <= 9 ; j++){
					for(k = 1 ; k <= number &&	(i*number + k< 10); k++)
						System.out.printf("%d X %d = %2d |",i*number + k, j, (i*number + k)*j);
					
					
				System.out.println();
			}
			System.out.println("------------------------------");
		}			
		//number���� 1�϶� 1�� �����ܸ� �����;;;
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