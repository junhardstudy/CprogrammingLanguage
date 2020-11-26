/*
	Hw11 homework, second problem.


*/

class Desktop extends Computer{
	
}

class NoteBook extends Computer{
	
}

class SubBattery implements ChargingCable{
	public void charging(Object obj) throws InterruptedException{
		if(obj instanceof CellPhone){
			while(((CellPhone)obj).battery != 100){
				System.out.print("charging: ");
				System.out.print(((CellPhone)obj).battery++);
				Thread.sleep(200);
				System.out.print("\r");
			}
			System.out.println("chare success!");
		}
		else{
			System.out.println("plz adopt mobile!");
		}
	}
}

class Computer implements ChargingCable{
	public void charging(Object obj) throws InterruptedException{
		if(obj instanceof CellPhone){
			while(((CellPhone)obj).battery != 100){
				System.out.print("charging: ");
				System.out.print(((CellPhone)obj).battery++);
				Thread.sleep(200);
				System.out.print("\r");
			}
			System.out.println("chare success!");
		}
		else{
			System.out.println("plz adopt mobile!");
		}
	}
	
}

interface ChargingCable{
	public abstract void charging(Object obj) throws InterruptedException;
}

class CellPhone{
	int battery;	
	CellPhone(){
		this.battery = (int)(Math.random() * 51);
	}
	
}

class Test4{
	public static void main(String [] args) throws InterruptedException{
		CellPhone GalaxyS = new CellPhone();
		CellPhone Iphone = new CellPhone();
		CellPhone HellG = new CellPhone();
		Desktop Dell = new Desktop();
		SubBattery Mii = new SubBattery();
		ChargingCable MiiCable = new SubBattery();
		
		
		Dell.charging(GalaxyS);
		Mii.charging(Iphone);
		MiiCable.charging(HellG);//interface를 상속받은 클래스의 인스턴스를 해당 인터페이스 참조 변수에서 참조!
		
	}
}