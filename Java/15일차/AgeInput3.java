//����ڿ��� ���̸� �޾� ���̸� ����ϴ� �޼ҵ�!!

import java.util.*;


//����� ���� ���� : ���� ���� ���� : ����ڰ� ���̸� ������ �Է��� ��� �߻��Ǵ� ����
class NegativeAgeException extends Exception{
	NegativeAgeException(){
		super("���� ���� ����!");
	}
	
}

class TooManyAgeException extends Exception{
	TooManyAgeException(){
		super("������������ ���� ����!");
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
		System.out.print("���� : ");
		age = S.nextInt();
		if(age < 0)throw new NegativeAgeException();
		//else if(age > 100)throw new TooManyAgeException();
	}
	
		
	
		
		
	
}