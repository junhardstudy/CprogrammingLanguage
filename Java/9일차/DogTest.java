/*
	setter을 만드는 이유 : 어떤 field 값을 안전하게 변경하기 위해서
	직접 필드를 참조해서 값을 바꿀수 있는 경우가 있음에도 따로 메소드를 마련하는 이유
	


*/




class Dog{
	String name;
	private int age, full;
	//private 접근 지정자는 외부에서 접근 할 수 없음
	//접근 지정자 : public, protected, private
	
	void setAge(int age){//이미 생성된 객체에 대해서 필드 값을 바꾸고자 하는 경우.
		if(0 > age || age > 99)this.age = 3;
		else this.age = age;
	}
	//getter: 필요한 field의 정보만 얻고 싶은 경우
	String getName(){//이름을 알려줌(이름을 반환하는 메소드)
		return name;
	}
	int getAge(){
		return age;
	}
	int getFull(){
		return full;
	}
	
	
	
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
		
	}//toString 메서드는 object class로부터 상속화
}


//객체가 생성된 후에 필드 정보를 바꾸고 싶을때, 설정자(setter)라는 메소드를 활용: 예)setAge(), setName(), ...
//강아지 한마리 생성후, 강아지에게 정보 물어서 출력
class DogTest{
	public static void main(String [] args){
		Dog myDog = new Dog();
		//System.out.println(myDog.toString());
		System.out.println(myDog);//위 문장과 똑같은 의미
		//myDog.age = -3;
		myDog.setAge(5);
		System.out.println(myDog);
		System.out.println(myDog.getName());
		
	}
}













