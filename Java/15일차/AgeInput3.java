//사용자에게 나이를 받아 나이를 출력하는 메소드!!

import java.util.*;


//사용자 정의 예외 : 음수 나이 예외 : 사용자가 나이를 음수로 입력할 경우 발생되는 예외
class NegativeAgeException extends Exception{
	NegativeAgeException(){
		super("음수 나이 예외!");
	}
	
}

class TooManyAgeException extends Exception{
	TooManyAgeException(){
		super("비정상적으로 많은 나이!");
	}
}



class AgeInput3{
	public static void main(String [] args){
		try{
		ageInput();
		}
		catch(NegativeAgeException nae){
			//System.out.println("error negative number!");
			System.out.println(nae.getMessage());
			return;
			
		}
		catch(TooManyAgeException tme){
			System.out.println(tme.getMessage());
			return;
		}
		
		
	}	
	
	static void ageInput() throws NegativeAgeException{	
		Scanner S = new Scanner(System.in);
		int age;
		int divide;
		System.out.print("나이 : ");
		age = S.nextInt();
		if(age < 0)throw new NegativeAgeException();
		//else if(age > 100)throw new TooManyAgeException();
	}
	
		
	
		
		
	
}