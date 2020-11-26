import java.util.*;

class Test{
	public static void main(String [] args){
		double num_1, num_2, result;
		
		if(args.length != 2){
			System.out.println("not enough the number of arguments!. plz insert 2 agrguments at command line!");
			return;
		}
		
		num_1 = Integer.parseInt(args[0]);
		num_2 = Integer.parseInt(args[1]);
		
		result = num_1 / num_2;
		
		if((int)result - result == 0.0)System.out.printf("결과 = %#x", (int)result);
		else System.out.printf("결과 = %+.3f", result);
	}
}