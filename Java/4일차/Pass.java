/*
	�ڹ� 4����
	
	
	
*/

import java.util.*;


class Pass{
	public static void main(String [] args){
		Scanner Sc = new Scanner(System.in);
		String str;
		
		str = Sc.nextLine();
		
		/*
		if(str == "�հ�")System.out.println("1");
		else if(str == "���հ�")System.out.println("0");
		else System.out.println("syntax error!");
		
		str�� ���ڿ��� �ش��ϴ� �ּҰ��� ���ϱ⿡ ���ڿ� �񱳿��� �ùٸ��� ���� ����
		*/
		
		if(str.equals("�հ�"))System.out.println("1");
		else if(str.equals("���հ�"))System.out.println("0");
		else System.out.println("syntax error!");
		
		//���ڿ� �񱳿��� .equals �޼��带 �̿��ϰų� switch-case�� ���
		while(true){
		System.out.printf("%d",Random.nextInt());
		Thread.sleep(900);
		}
		
		//������ ���� ���ؼ� ������ ����� �������
		
		
		
	}
}