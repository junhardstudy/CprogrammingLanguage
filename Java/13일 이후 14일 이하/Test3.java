class ����{
	void on(){
		System.out.print(getClass().getName() + "On");
	}
	void off(){
		System.out.print(getClass().getName() + "Off");
	}
	
}

class ����� extends ���� implements TemperUpDown{
	public void tempeUp(){//interface�� �޼ҵ带 ������ �Ҷ��� �ݵ�� public����!
		System.out.println(getClass().getName() + " temp up");
	}
	public void tempeDown(){
		System.out.println(getClass().getName() + " temp down");
	}
	
}

class ������ extends ���� implements TemperUpDown{
	public void tempeUp(){
		System.out.println(getClass().getName() + " temp up");
	}
	public void tempeDown(){
		System.out.println(getClass().getName() + " temp up");
	}
}
//�������� interface�� �����ϰ� ���� ���� , �̿�. �� : implements A, B, C{}

class ��Ź�� extends ����{
	
}

class Tv extends ����{
	
}

class ���Ϸ� extends ���� implements TemperUpDown{
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
}//interface �ȿ����� ���� �����ڰ� public���� �����Ǿ� ����.(���� abstract ���� �����Ǿ� ����)






class Test3{
	public static void main(String [] args){
		���� [] appliance = {new �����(), new Tv()};
		TemperUpDown [] tp = {new �����(), new ���Ϸ�()};
		
		appliance[0].on();
		for(TemperUpDown t : tp)t.tempeDown();
		
		appliance[1].on();
	}
}









