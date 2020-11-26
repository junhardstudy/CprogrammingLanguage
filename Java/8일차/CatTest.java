class Cat{
	String name;
	
	//말하는 동작 : 내 이름은 "name"
	void speak(){
		System.out.println("내 이름은 "+name);
	}
	Cat(){};//생성자
	//특징1: 클래스명과 메소드 명이 일치
	//특징2: 반환타입이 없다
	//생성자를 정의 하지 않을 경우 자바에서는 자동으로 default생성자를 정의
	//고양이 생성시에 이름을 초기화 하는 생성자
		Cat(String real_name){
		name = real_name;
	};
	//사용자 정의 생성자를 만들경우 자바에서 자동으로 만들어주는 default생성자는 정의가 안 됨.
	//따라서 사용자 정의 생성자를 만들경우 웬만하면 default생성자를 정의 해줄것
}

//source 파일 저장할때는 public이 들어가 있는 클래스의 이름으로 저장!
class CatTest{
	public static void main(String [] args){
		Cat MyCat= new Cat();//default 생성자를 호출
		MyCat.speak();
		
		Cat MyCat2 = new Cat("야옹이");
		MyCat2.speak();
		
	}
}