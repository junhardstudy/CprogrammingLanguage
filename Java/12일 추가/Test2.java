abstract class Fruit{
	abstract void print();
}

class Apple extends Fruit{
	void print(){
		System.out.println("나는 사과");
	}
}

class Pear extends Fruit{
	void print(){
		System.out.println("나는 배");
	}
}

class Grape extends Fruit{
	void print(){
		System.out.println("나는 포도");
	}
}
class Test2{
	public static void main(String [] args){
		Fruit [] F = {new Apple(), new Pear(), new Grape()};
		for(Fruit temp : F)temp.print();
	}
}