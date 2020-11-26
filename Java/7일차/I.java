import java.util.*;

class I{
	public static void main(String [] args){
		//강아지 한마리 생성
		Dog myDog = new Dog();
		Scanner S = new Scanner(System.in);
		
		while(true){
			if(myDog.full < 6){
				System.out.print("현재 배고픔, 밥 주기 : ");
				myDog.eat(S.nextInt());
			}
			else{
				System.out.println("현재 포만감은 " + myDog.full);
				myDog.play();
				break;
			}
			
			
			
		
		}
	


	/*
		System.out.println("생성 직후 포만감 : " + myDog.full);
		System.out.printf("생성 직후 이름 : %s", myDog.name);
		myDog.play();
		myDog.eat(5);
		
		
		Dog Second_Dog = new Dog(10, "푸들");
		System.out.println("새로운 강아지의 포만감은"+ Second_Dog.full +" 이며 이름은 " + Second_Dog.name);
	*/
	
		
	}
}