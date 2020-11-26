abstract class Fruit{
	abstract void print();
}

class Apple extends Fruit{
	void print(){
		System.out.println("���� ���");
	}
}

class Pear extends Fruit{
	void print(){
		System.out.println("���� ��");
	}
}

class Grape extends Fruit{
	void print(){
		System.out.println("���� ����");
	}
}
class Test2{
	public static void main(String [] args){
		Fruit [] F = {new Apple(), new Pear(), new Grape()};
		for(Fruit temp : F)temp.print();
	}
}