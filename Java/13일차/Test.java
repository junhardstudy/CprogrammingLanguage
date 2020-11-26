class Animal{
	int age;
	Animal(){}
	Animal(int age){
		this.age = age;
	}
	
	
	
	void print(){
		System.out.println("���� �Դϴ�.");
	}
	
	
}

class Human extends Animal{
	String name;
	Human(){}
	Human(String name, int age){
		super(age);//Human�� �ʵ尡 �ƴϹǷ� �θ� ��ü�� Animal�� �����ڿ��� �ʱ�ȭ �ϵ��� �ݵ�� �ؾ���
		this.name = name;
		
		
	}
	
	@Override
	public boolean equals(Object obj){
		if(obj instanceof Human){
			
			if(this.age == ((Human)obj).age && this.name.equals(((Human)obj).name))return true;
			else return false;
			
		}
		else {
			System.out.print("�ν��Ͻ� ����");
			return false;	
		}
		
	}
	
	
	void print(){
		System.out.println("�ΰ� �Դϴ�.");
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
			//Object Ŭ���� ��ü������ �� �޼ҵ尡 ������ �� Ŭ������ �������� �����Ƿ� ĳ���ú�ȯ �������.
			else return false;
		}
		else{
			
			return false;
		}
	}
	
	
	void print(){
		System.out.println("�л� �Դϴ�.");
	}
	
	
	
	
}

class Stone {}

class Test{
	public static void main(String [] args){
		
		/*	
		Animal Pet = new Animal();
		Human Person = new Human();
		Student Stud = new Student("�ƹ���", 25, 3);
		Animal a = new Human();//���� -> ĳ����(����ȯ)�� �߻��ߴµ�, �̷� ������ ĳ������ ��ĳ�����̶�� ��.
		
		Animal b = new Student();//���� -> ��ĳ����
		Human c = new Student();//���� -> ��ĳ����
		//������ : polymorphsim : �ϳ��� ��ü�� �������� Ÿ������ ������ �� �ִ� ����
		//����� ���� : �������� �̿��� �� ����
		
		//Student s = new Human();
		//�θ� Ŭ������ �ڽ� Ŭ������ ��Ī�ϴ� �ٿ� ĳ���� ���Ͱ��� ���� �Ұ���
		Human D = new Student();
		Student E = (Student)D;//�ٿ� ĳ����, �� �� ���� ���� ����
		Animal Te = new Student();
	

		System.out.println(((Student)Te).grade);
		System.out.println(Te.age);
		System.out.println(((Human)Te).name);
		
		//�ٿ� ĳ������ �Ѱ� : ����� ������ ���� �߻��� �Ͼ�ų� �������� �� �ɼ� ����
		System.out.println();
		
		System.out.printf("%s �� %d���̸� %d�г�\n", Stud.name, Stud.age, Stud.grade);
		
		Student a1 = new Student("�蹫��", 25, 3);
		Student a2 = new Student("�ƹ���", 24, 3);
		System.out.println(a1.equals(a2));
		
		
		Stone s = new Stone();
		a2.equals(s);
		
		Human [] I = {new Human("�ƾƾ�", 26), new Human("�ƾƾ�", 26), new Human("�̾ƾ�", 25)};
		
		System.out.println("���� 4�� �׽�Ʈ");
		System.out.println(I[0].equals(I[1]));
		System.out.println(I[0].equals(I[2]));
		System.out.println(I[0].equals(s));
		
		*/
		
	}
}