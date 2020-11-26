class Animal{
	int age;
	String name;
	
	
	Animal(){
		System.out.println("���� ����");
	}
	
	Animal(int age, String name){
		this.age = age;
		this.name = name;
		System.out.printf("%d �� %s��\n", this.age, this.name);
	}
	
	
	void eat(){
		System.out.println("�� �Դ� ��");
	}
	void move(){
		System.out.println("�����̴� ��");
	}
	
	@Override
	public boolean equals(Object obj){//� ������ �������� object�޼ҵ� ������ �̿�
		if(this.age == ((Animal)obj).age && this.name.equals(((Animal)obj).name))return true;
		else return false;
	}
	
	@Override
	public String toString(){
		return String.format("�̸� : %s, ����: %d", name, this.age);
	}
}

class Person extends Animal{//extends Animal : Animal�̶�� Ŭ������ ��ӹްڴ�.
	String job;//Animal Ŭ�����κ��� ��ӹ޾ұ� ������ field�� �� 3��, �޼���� 3���� ����.
	
	Person(){
		//Ainmal();//�θ�Ŭ������ default �����ڰ� �ڵ����� ȣ���.
		System.out.println("��� ����");
	}
	//�ڽ� Ŭ������ default�����ڰ� ������ �ݵ�� �θ� Ŭ�������� default�����ڰ� �����ؾ���.
	
	Person(String job, String name, int age){
		super(age, name);//�θ� Ŭ������ �����ڸ� ���� ���� ȣ���ؾ���
		this.job = job;
		
		//Animal(age, name); ������ ����
		//�θ�Ŭ������ �ʵ�� �θ�Ŭ������ �ʱ�ȭ�ϵ��� �Ұ�
		System.out.println(this.job + "�� " + name + "�̸� " + age + "��");
		
		
		
	}
	
	@Override //������ : ��ӹ��� �θ� Ŭ�����κ��� ���ϴ� �޼ҵ带 �κ� �����ϰ��� �ϴ� ��� ����ϸ�, 
	void move(){
		System.out.println("�ȴ� ��");
		
	}
	void work(){
		System.out.println("�� �ϴ� ��");
	}
}
	
//������������ ������ ����ؼ� override�Ҽ��� ����. ��, Ȯ���ϴ� ���� ����
//�θ� Ŭ������ Ư�� �޼ҵ尡 public �̸� �ڽ� Ŭ�������� ������ �Ҷ��� public�� �����ϸ�
//protected�̸� public�� protected �� ����

//�޼ҵ� �����ǽ� ����� �Ϻ��ϰ� ��ġ�ؾ� �Ѵ� -> X
//�޼ҵ� �����ǽ� �ñ״�ó�� �Ϻ��ϰ� ��ġ�ؾ� �Ѵ� -> O
//�޼ҵ� �ñ״�ó�� ��ġ�����ʴ´ٸ� -> �ߺ�����(method overload)

class PersonTest{
	public static void main(String [] args){
	Person Test1 = new Person();
	Test1.work();
	Test1.eat();
	Test1.move();
	System.out.println(Test1.age);
	
	Person Test2 = new Person("�л�", "�ƹ���", 25);
	
	Animal A1 = new Animal(1, "a");
	Animal A2 = new Animal(1, "abc");
	if(A1.equals(A2) == true)System.out.print("same");
	else System.out.print("differ");
	
	System.out.println();
	System.out.print(A1.toString());
	}
}