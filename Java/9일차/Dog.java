class Dog{
	String name;
	int age, full;
	
	Dog(){
		
		this("개똥이", 3, 5);//생서자에서는 또 다른 생성자를 호출 할 수 있음
	  //Dog("개똥이", 3, 5);//잘못된 문법
		
		
		/*
		name = "개똥이";
		age = 3;
		full = 5;
		*/
	};//defualt 생성자
	
	Dog(String name, int age, int full){
		this.name = name;//this = 이 객체
		
		if(0 > age || age > 99)this.age = 3;
		else this.age = age;
		
		if(0 > full || full > 10)this.full = 5;
		else this.full = full;
	}
	
	public String toString(){//이 객체에 대한 정보를 (문자열)String형으로 반환 해줌
		//이 강아지의 모든 필드 정보를 반환 : 이 강아지의 이름은 ***이며, 나이는 **세, 포만감은 **입니다.
		//return "이 강아지의 이름은 "+name+"이며, 나이는 "+age+"세, 포만감은 "+full+"입니다.";
		
		return String.format("이 강아지의 이름은 %s이며, 나이는 %d세, 포만감은 %d입니다.", name, age, full);//String에도 포멧 메서드 존재.
		
	}
}



//강아지 한마리 생성후, 강아지에게 정보 물어서 출력
class DogTest{
	public static void main(String [] args){
		Dog myDog = new Dog();
		myDog.toString();
	}
}













