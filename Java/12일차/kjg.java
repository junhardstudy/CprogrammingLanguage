class Animal{
	int age;
	String name;
	
	void eat(){
		System.out.println("밥 먹는 중");
	}
	void move(){
		System.out.println("움직이는 중");
	}
}

class Person extends Animal{//extends Animal : Animal이라는 클래스를 상속받겠다.
	String job;//Animal 클래스로부터 상속받았기 때문에 field는 총 3개, 메서드는 3개를 가짐.
	void work(){
		System.out.println("일 하는 중");
	}
	
}

class PersonTest{
	public static void main(String [] args){
	Person Test1 = new Person();
	Test1.work();
	Test1.eat();
	Test1.move();
	}
}