class Pet{}
class Cat extends Pet{}
class Dog extends Pet{}
class Shiba extends Dog{}













class InstanceofTest{
	public static void main(String [] args){
		
		//업캐스팅, 개, 고양이, 시바견 각각 한마리씩 만든 후 Pet 타입으로 지정(참조)하기
		/*
		Pet a1 = new Cat();
		Pet a2 = new Dog();
		Pet a3 = new Shiba();
		*/
		
		Pet [] a = {new Cat(), new Dog(), new Shiba()};
		//instanceof 확인
		System.out.println(a[0] instanceof Cat);
		System.out.println(a[1] instanceof Cat);
		System.out.println(a[2] instanceof Cat);
		
		
		
		Shiba j = new Shiba();
		//Shiba -> Dog -> Pet의 상속관계를 가지나 Shiba와 Cat은 서로 상속관계가 아님
		//System.out.println(j instanceof Cat);//컴파일 불가
		
		Dog D = new Dog();
		Cat C = new Cat();
		//마찬가지로 아무런 상속관계가 없으므로 컴파일 불가능한 경우
		//System.out.println(C instanceof D);//컴파일 불가
		
		
		
	}
}