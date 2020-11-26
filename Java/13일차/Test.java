class Animal{
	int age;
	Animal(){}
	Animal(int age){
		this.age = age;
	}
	
	
	
	void print(){
		System.out.println("동물 입니다.");
	}
	
	
}

class Human extends Animal{
	String name;
	Human(){}
	Human(String name, int age){
		super(age);//Human의 필드가 아니므로 부모 객체인 Animal의 생성자에서 초기화 하도록 반드시 해야함
		this.name = name;
		
		
	}
	
	@Override
	public boolean equals(Object obj){
		if(obj instanceof Human){
			
			if(this.age == ((Human)obj).age && this.name.equals(((Human)obj).name))return true;
			else return false;
			
		}
		else {
			System.out.print("인스턴스 에러");
			return false;	
		}
		
	}
	
	
	void print(){
		System.out.println("인간 입니다.");
	}
	
	
}

class Student extends Human{
	int grade;
	
	Student (){
		
	}

	
	Student(String name, int age, int grade){
		super(name, age);
		this.grade = grade;
		
	}
	
	@Override
	public boolean equals(Object obj){
		if(obj instanceof Student){
			if(this.grade == ((Student)obj).grade)return true;
			//Object 클래스 자체에서는 이 메소드가 재정의 된 클래스를 포함하지 않으므로 캐스팅변환 해줘야함.
			else return false;
		}
		else{
			
			return false;
		}
	}
	
	
	void print(){
		System.out.println("학생 입니다.");
	}
	
	
	
	
}

class Stone {}

class Test{
	public static void main(String [] args){
		
		/*	
		Animal Pet = new Animal();
		Human Person = new Human();
		Student Stud = new Student("아무개", 25, 3);
		Animal a = new Human();//가능 -> 캐스팅(형변환)이 발생했는데, 이런 종류의 캐스팅을 업캐스팅이라고 함.
		
		Animal b = new Student();//가능 -> 업캐스팅
		Human c = new Student();//가능 -> 업캐스팅
		//다형성 : polymorphsim : 하나의 객체를 여러가지 타입으로 지정할 수 있는 성질
		//상속의 장점 : 다형성을 이용할 수 있음
		
		//Student s = new Human();
		//부모 클래스를 자식 클래스로 지칭하는 다운 캐스팅 위와같은 경우는 불가능
		Human D = new Student();
		Student E = (Student)D;//다운 캐스팅, 이 와 같은 경우는 가능
		Animal Te = new Student();
	

		System.out.println(((Student)Te).grade);
		System.out.println(Te.age);
		System.out.println(((Human)Te).name);
		
		//다운 캐스팅의 한계 : 실행시 비정상 종료 발생이 일어나거나 컴파일이 안 될수 있음
		System.out.println();
		
		System.out.printf("%s 는 %d세이며 %d학년\n", Stud.name, Stud.age, Stud.grade);
		
		Student a1 = new Student("김무개", 25, 3);
		Student a2 = new Student("아무개", 24, 3);
		System.out.println(a1.equals(a2));
		
		
		Stone s = new Stone();
		a2.equals(s);
		
		Human [] I = {new Human("아아아", 26), new Human("아아아", 26), new Human("이아아", 25)};
		
		System.out.println("문제 4번 테스트");
		System.out.println(I[0].equals(I[1]));
		System.out.println(I[0].equals(I[2]));
		System.out.println(I[0].equals(s));
		
		*/
		
	}
}