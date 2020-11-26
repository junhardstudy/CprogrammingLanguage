/*
	setter�� ����� ���� : � field ���� �����ϰ� �����ϱ� ���ؼ�
	���� �ʵ带 �����ؼ� ���� �ٲܼ� �ִ� ��찡 �������� ���� �޼ҵ带 �����ϴ� ����
	


*/




class Dog{
	String name;
	private int age, full;
	//private ���� �����ڴ� �ܺο��� ���� �� �� ����
	//���� ������ : public, protected, private
	
	void setAge(int age){//�̹� ������ ��ü�� ���ؼ� �ʵ� ���� �ٲٰ��� �ϴ� ���.
		if(0 > age || age > 99)this.age = 3;
		else this.age = age;
	}
	//getter: �ʿ��� field�� ������ ��� ���� ���
	String getName(){//�̸��� �˷���(�̸��� ��ȯ�ϴ� �޼ҵ�)
		return name;
	}
	int getAge(){
		return age;
	}
	int getFull(){
		return full;
	}
	
	
	
	Dog(){
		
		this("������", 3, 5);//�����ڿ����� �� �ٸ� �����ڸ� ȣ�� �� �� ����
	  //Dog("������", 3, 5);//�߸��� ����
		
		
		/*
		name = "������";
		age = 3;
		full = 5;
		*/
	};//defualt ������
	
	Dog(String name, int age, int full){
		this.name = name;//this = �� ��ü
		
		if(0 > age || age > 99)this.age = 3;
		else this.age = age;
		
		if(0 > full || full > 10)this.full = 5;
		else this.full = full;
	}
	
	public String toString(){//�� ��ü�� ���� ������ (���ڿ�)String������ ��ȯ ����
		//�� �������� ��� �ʵ� ������ ��ȯ : �� �������� �̸��� ***�̸�, ���̴� **��, �������� **�Դϴ�.
		//return "�� �������� �̸��� "+name+"�̸�, ���̴� "+age+"��, �������� "+full+"�Դϴ�.";
		
		return String.format("�� �������� �̸��� %s�̸�, ���̴� %d��, �������� %d�Դϴ�.", name, age, full);//String���� ���� �޼��� ����.
		
	}//toString �޼���� object class�κ��� ���ȭ
}


//��ü�� ������ �Ŀ� �ʵ� ������ �ٲٰ� ������, ������(setter)��� �޼ҵ带 Ȱ��: ��)setAge(), setName(), ...
//������ �Ѹ��� ������, ���������� ���� ��� ���
class DogTest{
	public static void main(String [] args){
		Dog myDog = new Dog();
		//System.out.println(myDog.toString());
		System.out.println(myDog);//�� ����� �Ȱ��� �ǹ�
		//myDog.age = -3;
		myDog.setAge(5);
		System.out.println(myDog);
		System.out.println(myDog.getName());
		
	}
}













