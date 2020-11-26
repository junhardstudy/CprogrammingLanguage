import java.util.*;

class Predict_Random{
	public static void main(String [] args){
		int rand_num, user_num;
		Scanner S = new Scanner(System.in);
		
		rand_num = (int)(Math.random() * 101);
		
		do{
			System.out.print("plz type the number between 0 and 100 : ");
			user_num = S.nextInt();
			if(user_num == rand_num){
				System.out.println(rand_num + " is correct number!");
				break;
			}
			else if(user_num > rand_num)System.out.println("Bigger than answer number!\n");
			else System.out.println("Smaller than answer number!\n");
			
		}while(true);
	}
}