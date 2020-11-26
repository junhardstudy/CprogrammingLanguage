import java.util.*;

class ATest{
	public static void main(String [] args){
		Scanner S = new Scanner(System.in);
		int age;
		int divide;
		System.out.print("나이 : ");
		try{
		age = S.nextInt();
		
		System.out.printf("당신의 나이는 %d세 입니다.\n", age);
		
		System.out.print("what number divided ? :");
		divide = S.nextInt();
		
		System.out.printf("%d / %d = %d\n", age,divide, age/divide);
		/*
		}catch(Exception e){
			//어떤 예외가 발생해서 잡혔는지 모르기때문에 예외 처리를 어떤 식으로 해야할지 작성하기 어려움 : 비추
		}
		*/
		}catch(InputMismatchException ime){
			System.out.print("wrong 나이 !");
			return;
		}catch(ArithmeticException ae){
			System.out.print("not divide by zero!");
			return;
		}finally{
			System.out.println("이 문장은 반드시 실행됨");
		}
		
		

		
		
	}
}