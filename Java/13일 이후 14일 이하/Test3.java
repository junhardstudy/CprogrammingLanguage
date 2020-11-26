class 가전{
	void on(){
		System.out.print(getClass().getName() + "On");
	}
	void off(){
		System.out.print(getClass().getName() + "Off");
	}
	
}

class 냉장고 extends 가전 implements TemperUpDown{
	public void tempeUp(){//interface의 메소드를 재정의 할때는 반드시 public으로!
		System.out.println(getClass().getName() + " temp up");
	}
	public void tempeDown(){
		System.out.println(getClass().getName() + " temp down");
	}
	
}

class 에어컨 extends 가전 implements TemperUpDown{
	public void tempeUp(){
		System.out.println(getClass().getName() + " temp up");
	}
	public void tempeDown(){
		System.out.println(getClass().getName() + " temp up");
	}
}
//여러개의 interface를 구현하고 싶을 때는 , 이용. 예 : implements A, B, C{}

class 세탁기 extends 가전{
	
}

class Tv extends 가전{
	
}

class 보일러 extends 가전 implements TemperUpDown{
	public void tempeUp(){
		System.out.println(getClass().getName() + " temp up");
	}
	public void tempeDown(){
		System.out.println(getClass().getName() + " temp up");
	}
}

interface TemperUpDown{
	void tempeUp();
	void tempeDown();
}//interface 안에서는 접근 지시자가 public으로 생략되어 있음.(또한 abstract 또한 생략되어 있음)






class Test3{
	public static void main(String [] args){
		가전 [] appliance = {new 냉장고(), new Tv()};
		TemperUpDown [] tp = {new 냉장고(), new 보일러()};
		
		appliance[0].on();
		for(TemperUpDown t : tp)t.tempeDown();
		
		appliance[1].on();
	}
}









