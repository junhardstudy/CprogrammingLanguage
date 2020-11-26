import java.util.Scanner;

class CastingTest{
	public static void main(String [] args){
		int tp = 0;
		long a = 1;
		float b = 2.2f;
		double c = 123.456F;//작은 자료형(float)가 큰 자료형(double)에 담기기에 에러 없음
		
		Scanner S = new Scanner(System.in);
		
		
		//'/'연산자 고찰
		//System.out.println(0/0); <- error
		//System.out.println(70/0); <- erro
		System.out.println(+90/0.0); //+infinity
		System.out.println(0/0.0); //NaN:Not a Number
		System.out.println(-7/0.0); //-infinity
		
		/*
		문자열(문자) "3"을 숫자(int)로 바꾸고자 하는 경우
		캐스팅 연산자는 불가능하고 
		*/
		System.out.println(args[0]);
		
		
		
		
		
		
		
		
		
		a =(long)b;
		System.out.print("a = "+a+", b = "+b);
		System.out.printf("\nc=%f \n", c);
		
	
		for(int i = 0; i <10; i++){
			System.out.printf("%d\t", (int)(Math.random()*6));
				//0이상 5이하의 정수형 난수 생성
			System.out.printf("%d\t", (int)(Math.random()*11 + 10));
				//10이상 20이하의 정수형 난수 생성
			System.out.printf("%d\n", (int)(Math.random()*21 -10));
				//-10이상 10이하의 정수형 난수 생성
		}
		
		//화씨온도(정수)를 입력받아 섭씨 온도로 변환
		tp = S.nextInt();
		System.out.printf("섭씨 %f", (5.0/9)*(tp - 32));
		
		System.out.println(5+3+": 5와 3의 합");
		System.out.println("5와 3의 합:"+5+3);//문장을 이어주는 의미로 사용되는 +뒤에 오는 어떠한 +든지 다 문장을 이어주는 의미로 인용됨 따라서 더한 결과 값을 문장에 이어주기 위해서는 아래 구문과 같이 사용
		System.out.println("5와 3의 합:"+(5+3));
		
		
		
	}
	
}