/*
	static �޼��忡���� non-static �޼��带 ���� �� �� ����

	�ߺ�����(overload):�̸��� ������ �ñ״���(�޼ҵ� �̸� + �Ű� ����)�� �ٸ� ���

*/


import java.util.*;


class Mathod_Test{
	public static void main(String [] args){
		int a, b, digit;
		String str;
		Scanner S = new Scanner(System.in);
		
		
		digit = sum(2, 5);
		System.out.printf("%d�� %d�� ���� %d�Դϴ�.\n", 2, 5, sum(2, 5));
		tvWork(S.nextLine());
		
		
		
		System.out.print("���Ǳ⿡�� ���� �� : "+ vendingWork(S.nextLine()));
		System.out.println(sum(4.4, 34, 6.5, 35, 6.78));
	}
	//sum() �޼���� �ո� ���ϰ� ���ο��� ��������� ���� �̿��ϰ� ����.
	
	
	static int sum(int a, int b){
		return a+b;
	}
	//�Ű������� �Ǽ� ž��, ���ڰ� ������� �������� ����, ���� ��ȯ�ϴ� sum() �޼ҵ�
	
	static double sum(double... d){//sum(2, 3, 4) => d = 2, 3, 4
		double sum = 0;
		for(double elt:d){//d�� ���Ұ� ���ʷ� elt�� �����.
			//for(:�迭��)
			sum += elt;
			
		}
		return sum;	
	}
	
	
	
	
	
	
	
	
	
	static void tvWork(String channel){
		System.out.println("���� ä��" + channel);
	}
	
	static String vendingWork(String beverage){
			
			return beverage;
	}
	
	
	
	
	
	/*
	static void sum(int a, int b){//mathod ����
		System.out.printf("%d + %d = %d", a, b, a+b);
		
	}
	*/
}