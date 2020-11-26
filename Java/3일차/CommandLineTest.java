class CommandLineTest{
	public static void main(String [] args){
		int a;//정수 1개 저장가능
		int [] arr = {3, 2, 1, 5, 6, 7};//정수 6개를 저장할 수 있는 배열
		
		
		//커맨드 라인에서 사용자의 이름과 나이, 평점을 입력받아, ***님의 10년후 나이는 ****세 그리고 평점은 ***입니다.를 출력
		if(args.length < 2){
			//커맨드 라인에서 받아들이는 배열(인자, 입력 데이터 수)개수가 모자랄 경우 경고 문장을 띄우며 프로그램 종료
			//모든 배열에는 .length라는 필드가 주어짐
			System.out.println("입력 데이터 수 부족");
			return;//프로그램 종료
		}
		//홍길동 5 를 입력할 경우
		//5는 "5"라는 문자열로 인식
		//문자열 "5"를 정수형 데이터  5로 바꾸기 위해서는 아래와 같은 매서드 이용
		int age = Integer.parseInt(args[1]);
		double grade = Double.parseDouble(args [2]);
		//랩퍼(wrapper) 클래스 : Integer, Double, Byte, ... 기초 자료형들을 클래스 형태로 취급하기에 wrapper 클래스라고 불림
		
		System.out.format("%s님의 나이(%d)는 10년후 %d세, 평점은 %.3f 입니다.\n",args[0], age, age + 10, grade);
	}
}