class Animal{
	int age;
	String name;
	
	
	Animal(){
		System.out.println("동물 생성");
	}
	
	Animal(int age, String name){
		this.age = age;
		this.name = name;
		System.out.printf("%d 세 %s임\n", this.age, this.name);
	}
	
	
	void eat(){
		System.out.println("밥 먹는 중");
	}
	void move(){
		System.out.println("움직이는 중");
	}
	
	@Override
	public boolean equals(Object obj){//어떤 동물이 같은지를 object메소드 재정의 이용
		if(this.age == ((Animal)obj).age && this.name.equals(((Animal)obj).name))return true;
		else return false;
	}
	
	@Override
	public String toString(){
		return String.format("이름 : %s, 나이: %d", name, this.age);
	}
}

class Person extends Animal{//extends Animal : Animal이라는 클래스를 상속받겠다.
	String job;//Animal 클래스로부터 상속받았기 때문에 field는 총 3개, 메서드는 3개를 가짐.
	
	Person(){
		//Ainmal();//부모클래스의 default 생성자가 자동으로 호출됨.
		System.out.println("사람 생성");
	}
	//자식 클래스의 default생성자가 있으면 반드시 부모 클래스에도 default생성자가 존재해야함.
	
	Person(String job, String name, int age){
		super(age, name);//부모 클래스의 생성자를 가장 먼저 호출해야함
		this.job = job;
		
		//Animal(age, name); 컴파일 에러
		//부모클래스의 필드는 부모클래스가 초기화하도록 할것
		System.out.println(this.job + "인 " + name + "이며 " + age + "세");
		
		
		
	}
	
	@Override //재정의 : 상속받은 부모 클래스로부터 원하는 메소드를 부분 수정하고자 하는 경우 사용하며, 
	void move(){
		System.out.println("걷는 중");
		
	}
	void work(){
		System.out.println("일 하는 중");
	}
}
	
//접근지시자의 범위를 축소해서 override할수는 없음. 단, 확대하는 것은 가능
//부모 클래스의 특정 메소드가 public 이면 자식 클래스에서 재정의 할때는 public만 가능하며
//protected이면 public과 protected 가 가능

//메소드 재정의시 헤더는 완벽하게 일치해야 한다 -> X
//메소드 재정의시 시그니처는 완벽하게 일치해야 한다 -> O
//메소드 시그니처가 일치하지않는다면 -> 중복정의(method overload)

class PersonTest{
	public static void main(String [] args){
	Person Test1 = new Person();
	Test1.work();
	Test1.eat();
	Test1.move();
	System.out.println(Test1.age);
	
	Person Test2 = new Person("학생", "아무개", 25);
	
	Animal A1 = new Animal(1, "a");
	Animal A2 = new Animal(1, "abc");
	if(A1.equals(A2) == true)System.out.print("same");
	else System.out.print("differ");
	
	System.out.println();
	System.out.print(A1.toString());
	}
}