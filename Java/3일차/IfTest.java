/*
	���ǹ��� ���Ͽ�

*/

import java.util.Scanner;

class IfTest{
	public static void main(String [] args){
		int score, today, after, result;
		String [] pass = {"����"};//���ڿ��� �迭
		String pass2;//���ڿ�, ����ɶ��� c���� ó�� �迭�� ������ ������ �ڹٶ� ��ü ó�� ���
		Scanner S = new Scanner(System.in);
		
		
		System.out.print("pass or not? :");
		pass2 = S.nextLine();
	//	System.out.println("%d", Integer.parseInt(pass[0]));
	
		
		if(pass2.charAt(0)=='��')System.out.println("1");
		else System.out.println("0");
		//���ڿ��� ��� call by referrence �̰� ������ ��� call by value��(���ڴ� ���� �ڷ��� �̱� �����̸� ���ڿ��� ���� �ڷ����̱� ����)
	/*	
		System.out.print("���� :");
		score = S.nextInt();
		
		
		if(score >= 90) System.out.println("���б�!");
		
		//else if(score < 90 && score >=30) System.out.println("�հ�!");
		//�̹� ��ܿ��� 90���̻� ���ؼ� ���� �Ͽ����Ƿ� 90���̸� �ڷ�鸸 ��������. ���� �� 90�� �̻� �����͸� �ɷ��� �ʿ�� ���� ����
		else if(score >= 30) System.out.println("�հ�!");
		
		else System.out.println("���հ�!");
	/*	
		System.out.print("������ ���� ����? :");
		S.nextLine();
		today = S.nextLine();
		*/
	
	}
}