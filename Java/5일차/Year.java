import java.util.*;

class Year{
	public static void main(String [] args){
		int year, month, special_case = 0, date;
		Scanner S = new Scanner(System.in);
	/*	
		System.out.print("�� �� : ");
		year = S.nextInt();
		System.out.print("�� �� : ");
		month = S.nextInt();
		
		
		//���� ���� ���� �Ǵ�
		if((year % 4) == 0 && (year % 100) != 0 || (year % 400) == 0)special_case = 1;
		
		switch(month){
			case 1: case 3: case 5: case 7: case 8: case 10: case 12: date = 31; break;
			case 4: case 6: case 9: case 11: date = 30; break;
			case 2: if(special_case == 0)date = 28;//����� ���
					else date = 29;//������ ���
					break;
			default : date = 0; System.out.println("month error!");
		}
		System.out.format("%d�� %d���� %d�ϱ��� �ֽ��ϴ�.\n", year, month, date);
		
	*/	
		
		//--------------------------��	��----------------------------
		String test_type;
		int score;
		
	//	S.nextLine();//buffer �� �ִ� ���� �� ����
		System.out.print("�� �� ����(1��/2��): ");
		test_type = S.nextLine();
		System.out.print("�� �� :");
		score =S.nextInt();
		
		if(test_type.length() != 2)System.out.println("Syntax error!");
		
		switch(test_type){
			case "1��":if(score >= 70)System.out.println("�հ�!");
						else System.out.println("���հ�!");
						break;
			case "2��":if(score >= 60)System.out.println("�հ�!");
						else System.out.println("���հ�!");
						break;
			default: System.out.println("Condition data error!");
					return;
		}
		
		//�Ǵ�
		
		if(test_type.equals("1��") && score >= 70)System.out.println("if first : pass!");
		else if(test_type.equals("2��") && score >= 60)System.out.println("if second : pass!");
		else System.out.println("if : fail!");
		
		
		
		
		
		
		
		
		
		
		
	}
}