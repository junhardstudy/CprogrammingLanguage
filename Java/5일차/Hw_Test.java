import java.util.*;

class Hw_Test{
	public static void main(String [] args){
		int rand_num, num;
	
		
		if(args.length != 1){
			System.out.print("error");
			return;
		}
		
		num = Integer.parseInt(args[0]);
		rand_num = (int)(Math.random() * 21 - 10);
		
		if(num == rand_num)System.out.print("correct");
		else if(num == Math.abs(rand_num))System.out.printf("absolute correct %d ", rand_num);
		else System.out.printf("no %d", rand_num);
		
		
		//---------------------------------구	분---------------------------------
		
		double num_1, num_2, result;
		String operator;
		Scanner Sc = new Scanner(System.in);
		
		System.out.print("\n 수식:");
		num_1 = Sc.nextDouble();
		operator = Sc.next();
		num_2 = Sc.nextDouble();
		
		switch(operator){
			case "+":
				result = num_1 + num_2;
				if((int)result - result == 0.0)System.out.printf("result = %d", (int)result);else System.out.printf("result = %.5f", result);		
				break;
			case "-":
				result = num_1 - num_2;
				if((int)result - result == 0.0)System.out.printf("result = %d", (int)result);else System.out.printf("result = %.5f", result);		
				break;
			case "/":
				result = num_1 / num_2;
				if((int)result - result == 0.0)System.out.printf("result = %d", (int)result);else System.out.printf("result = %.5f", result);		
				break;
			case "%":
				result = num_1 % num_2;
				if((int)result - result == 0.0)System.out.printf("result = %d", (int)result);else System.out.printf("result = %.5f", result);		
				break;
			default : System.out.println("Syntax Error!");
		}
		
		//---------------------------------구	분---------------------------------

		
		
		
		int int_num, temp;
		
		System.out.print("자릿수 구분");
		int_num = Sc.nextInt();
		
		temp = int_num/(int)Math.pow(10, 4);
		int_num %= int_num%(int)Math.pow(10, 4);
		
		if(temp > 1)System.out.printf("%d만", temp);
		else System.out.print("만");
		
		temp = int_num/Math.pow(10, 3);
		int_num %= int_num%Math.pow(10, 3);
		
		if(temp > 1)System.out.printf("%d천", temp);
		else if(temp == 1)System.out.print("천");
		
		temp = int_num/Math.pow(10, 2);
		int_num %= int_num%Math.pow(10, 2);
		
		if(temp >1)System.out.printf("%d백", temp);
		else if(temp == 1)System.out.print("백");
		
		temp = int_num/(int)Math.pow(10, 4);
		int_num %= int_num%(int)Math.pow(10, 4);
		
		if(temp > 1)System.out.printf("%d십", temp);
		else if(temp == 1)System.out.print("십");
		
		temp = int_num/(int)Math.pow(10, 4);
		int_num %= int_num%(int)Math.pow(10, 4);
		
		if(temp > 1)System.out.printf("%d", temp);
		else if(temp == 1)System.out.print("일");
		
		
		
	}
}