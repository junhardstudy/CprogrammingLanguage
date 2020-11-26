//강아지와 놀거나(포만감 > 6) 강아지에게 밥 주기(포만감 <=6)
//강아지와 놀거나 강아지에게 밥 주기
//강아지 객체 => 강아지 클래스(설계도)

//스캐너 객체 => 스캐너 클래스(설계도)에 따라 생성됨
//Scanner S = new Scanner(System.in);


class Dog{//강아지 설계도
		//강아지라면 가지고 있어야 할 속성과 동작을 기술
		//추상화를 거침:프로그램에서 필요한 속성과 동작만을 추출(추상화)
		//속성: 필드(여기선 full과 name이라는 필드가 존재)
		//필드는 따로 초기화를 하지 않는다면 자료형에 맞느느 0으로 초기화 됨.
		
		
		int full;
		String name;
		int num;
		//생성자 : 특별한 메소드로 객체를 생성할때만 호출 가능한 메소드, 메소드 헤더 구조는 반환 타입이 없으며 클래스 이름과 동일
		
		Dog(){}//생성자: 매개변수가 없는 생성자; 디폴트 생성자;
		
		
		Dog(int i, String s){
			full = i;
			name = s;
		}//태어날때 이름과 포만감을 지정하는 생성자
		
		
		
		//동작: 메소드로 작성
		
		//아래는 노는 메소드
		void play(){
			//노는 과정
			System.out.println("재미있다.");
			full--;
		}
		//먹는 메소드
		void eat(int food){
			//food개수만큼 포만감 증가시키고, 잘먹었다고 출력
			if(food <= 0)System.out.println("no food;;");
			else {
				full += food;
				System.out.println("잘먹음");
			}
			
		}
		
		void eatwhatfood(String food_foodname, int num){
			if(food_foodname.length() <= 0){
				System.out.print("음식 개수가 모자람!");
				return;
			}
			else System.out.printf("%s(을)를 %d개 먹음\n", food_foodname, num);
			
		}
		
		
	
}





