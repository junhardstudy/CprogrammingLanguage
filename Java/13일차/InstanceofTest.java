class Pet{}
class Cat extends Pet{}
class Dog extends Pet{}
class Shiba extends Dog{}













class InstanceofTest{
	public static void main(String [] args){
		
		//��ĳ����, ��, �����, �ùٰ� ���� �Ѹ����� ���� �� Pet Ÿ������ ����(����)�ϱ�
		/*
		Pet a1 = new Cat();
		Pet a2 = new Dog();
		Pet a3 = new Shiba();
		*/
		
		Pet [] a = {new Cat(), new Dog(), new Shiba()};
		//instanceof Ȯ��
		System.out.println(a[0] instanceof Cat);
		System.out.println(a[1] instanceof Cat);
		System.out.println(a[2] instanceof Cat);
		
		
		
		Shiba j = new Shiba();
		//Shiba -> Dog -> Pet�� ��Ӱ��踦 ������ Shiba�� Cat�� ���� ��Ӱ��谡 �ƴ�
		//System.out.println(j instanceof Cat);//������ �Ұ�
		
		Dog D = new Dog();
		Cat C = new Cat();
		//���������� �ƹ��� ��Ӱ��谡 �����Ƿ� ������ �Ұ����� ���
		//System.out.println(C instanceof D);//������ �Ұ�
		
		
		
	}
}