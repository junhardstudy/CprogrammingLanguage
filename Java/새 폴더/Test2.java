interface A{
	void disp();
	
	
}

class B implements A{
	public void disp(){
		System.out.println("method for B!");
	}
}

class C extends B{
	
}

class Test2 extends B{
	public static void main(String [] args){
		B b;
		new B();
		b = new B();
		//b.disp();
	}
}