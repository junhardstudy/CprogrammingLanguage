class Dog{
	String name;
	int age, full;
	
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
		
	}
}



//������ �Ѹ��� ������, ���������� ���� ��� ���
class DogTest{
	public static void main(String [] args){
		Dog myDog = new Dog();
		myDog.toString();
	}
}













