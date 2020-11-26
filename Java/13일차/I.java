class I{
	public static void main(String [] args){
	Food F = new Food();
	

	F.eat(new Pizza());
	
	}
}

class Food{
	
	
	void eat(Object obj){
		if(obj instanceof Food)
			System.out.print(obj.getClass().getName() + "을 먹습니다.");
		else
			System.out.print("비정상 접근");
	}
}
class Hamburger extends Food{}
class Pizza extends Food{}
class Icecream extends Food{}
class Hotdog extends Food{}
class Ramen extends Food{}


