class Cat{
	String name;
	
	//���ϴ� ���� : �� �̸��� "name"
	void speak(){
		System.out.println("�� �̸��� "+name);
	}
	Cat(){};//������
	//Ư¡1: Ŭ������� �޼ҵ� ���� ��ġ
	//Ư¡2: ��ȯŸ���� ����
	//�����ڸ� ���� ���� ���� ��� �ڹٿ����� �ڵ����� default�����ڸ� ����
	//����� �����ÿ� �̸��� �ʱ�ȭ �ϴ� ������
		Cat(String real_name){
		name = real_name;
	};
	//����� ���� �����ڸ� ������ �ڹٿ��� �ڵ����� ������ִ� default�����ڴ� ���ǰ� �� ��.
	//���� ����� ���� �����ڸ� ������ �����ϸ� default�����ڸ� ���� ���ٰ�
}

//source ���� �����Ҷ��� public�� �� �ִ� Ŭ������ �̸����� ����!
class CatTest{
	public static void main(String [] args){
		Cat MyCat= new Cat();//default �����ڸ� ȣ��
		MyCat.speak();
		
		Cat MyCat2 = new Cat("�߿���");
		MyCat2.speak();
		
	}
}