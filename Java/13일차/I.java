class I{
	public static void main(String [] args){
	Food F = new Food();
	

	F.eat(new Pizza());
	
	}
}

class Food{
	
	
	void eat(Object obj){
		if(obj instanceof Food)
			System.out.print(obj.getClass().getName() + "�� �Խ��ϴ�.");
		else
			System.out.print("������ ����");
	}
}
class Hamburger extends Food{}
class Pizza extends Food{}
class Icecream extends Food{}
class Hotdog extends Food{}
class Ramen extends Food{}


