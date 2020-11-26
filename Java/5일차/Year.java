import java.util.*;

class Year{
	public static void main(String [] args){
		int year, month, special_case = 0, date;
		Scanner S = new Scanner(System.in);
	/*	
		System.out.print("몇 년 : ");
		year = S.nextInt();
		System.out.print("몇 월 : ");
		month = S.nextInt();
		
		
		//먼저 윤년 유무 판단
		if((year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0)special_case = 1;
		
		switch(month){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12: date = 31; break;
			case 4: case 6: case 9: case 11: date = 30; break;
			case 2: if(special_case == 0)date = 28;//평년일 경우
					else date = 29;//윤년일 경우
					break;
			default : date = 0; System.out.println("month error!");
		}
		System.out.format("%d년 %d월은 %d일까지 있습니다.\n", year, month, date);
		
	*/	
		
		//--------------------------구	분----------------------------
		String test_type;
		int score;
		
	//	S.nextLine();//buffer 상에 있는 엔터 값 제거
		System.out.print("차 종 시험(1종/2종): ");
		test_type = S.nextLine();
		System.out.print("점 수 :");
		score =S.nextInt();
		
		if(test_type.length() != 2)System.out.println("Syntax error!");
		
		switch(test_type){
			case "1종":if(score >= 70)System.out.println("합격!");
						else System.out.println("불합격!");
						break;
			case "2종":if(score >= 60)System.out.println("합격!");
						else System.out.println("불합격!");
						break;
			default: System.out.println("Condition data error!");
					return;
		}
		
		//또는
		
		if(test_type.equals("1종") && score >= 70)System.out.println("if first : pass!");
		else if(test_type.equals("2종") && score >= 60)System.out.println("if second : pass!");
		else System.out.println("if : fail!");
		
		
		
		
		
		
		
		
		
		
		
	}
}