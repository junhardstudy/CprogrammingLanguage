class Animal{
	int age;
	String name;
	
	void eat(){
		System.out.println("�� �Դ� ��");
	}
	void move(){
		System.out.println("�����̴� ��");
	}
}

class Person extends Animal{//extends Animal : Animal�̶�� Ŭ������ ��ӹްڴ�.
	String job;//Animal Ŭ�����κ��� ��ӹ޾ұ� ������ field�� �� 3��, �޼���� 3���� ����.
	void work(){
		System.out.println("�� �ϴ� ��");
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