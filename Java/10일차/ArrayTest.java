import java.util.*;

class ArrayTest{
	public static void main(String [] args){
		int [] scores1 = {1, 5, 3, 6, 3, 7};//배열의 원소 개수가 이미 정해진 상황에서는 {}로 초기화
		int [] scores2 = new int[5];//초기화는 되어 있지 않으나 배열의 원소 개수가 이미 정해진 배열 선언
		int sum = 0;
		
		Scanner S = new Scanner(System.in);
	/*	
		for(int i = 0; i < scores1.length; i++)
			System.out.println(scores1[i]);
		
		for(int i = 0; i < scores2.length; i++){
			System.out.print(i+1 + "번째 학생의 점수 : ");
			scores2[i] = S.nextInt();
			sum += scores2[i];
			
		}
		System.out.println(scores2.length + "명의 학생들에 대한 평균은 "+ sum/(double)scores2.length);
		*/
		
		System.out.print("몇 대? : ");
		Car [] myCar = new Car[S.nextInt()];
		
		
		
		Car [] myCar2 = {new Car("abc", 2011), new Car("bcd", 2013), new Car("cde", 2014)};//이렇게도 가능
		
		for(int i = 0 ; i < myCar2.length; i++){
			if(i == 1)myCar2[i].name = "모하비";
		}//아래와 같이 표현 가능

		
		
		for(int i = 0 ; i < myCar2.length; i++){
			System.out.println(myCar2[i].name);
		}//아래와 같이 표현 가능
		for(Car myCartmp: myCar2){
			myCartmp.name = "reset";
			System.out.println(myCartmp.name);
		}
		
		
	}
}

class Car{
	String name;
	int year;
	
	Car(){}
	Car(String name, int year){
		this.name = name;
		this.year = year;
	}
}