/*
	1.method�� �ҹ��ڷ� ����
	
	2.�� �ܾ� �̻��� �ռ���� �ι�° �ܾ�� �빮�ڷ� ����
	
	3.class�� �빮�ڷ� ����

*/


import java.util.Scanner;

class I{//class Ŭ������(ù���ڴ� �׻� �빮��)
	public static void main(String [] args){
	String name;//����ڰ� �Է��� �̸��� ������ ����(�޸� ����)
	double height;//Ű�� ������ ���� (�޸� ����) Ȯ��
	int age;
	String phnumber;
	int year;
	double grade;
	
	Scanner Sc = new Scanner(System.in);
	//Ű����κ��� ���� �о���� ��ĳ�� ����
	//System.in = ǥ�� �Է��� Ű���带 �ǹ�.
	
	//System.out.print("�̸�:");
	//name = Sc.nextLine();//Ŀ�ǵ���ο��� �� ���� �о��.
	
	//System.out.printf("����� �̸��� %s �Դϴ�.\n", name);
	/*
	System.out.print("Ű:");
	height = Sc.nextDouble();//�Ǽ� �о��
	
	System.out.print("����:");
	age = Sc.nextInt();
	
	System.out.printf("Ű:%.2f, ����:%d\n",height, age);
	*/
	
	System.out.print("��ȭ ��ȣ:");
	phnumber = Sc.nextLine();
	System.out.print("�г�:");
	year = Sc.nextInt();
	System.out.print("����:");
	grade = Sc.nextDouble();
	
	System.out.printf("Phone number :%s\n�г�:%d\n����:%.3f",phnumber, year, grade);
	
		
		
		
		
	/*	
		
		System.out.println("fromln");//println:��������
		System.out.printf("Hellow\n");//printf:�������
		System.out.format("fromformat\n");//.format�� .printf�� ����
		System.out.printf("%d\n",6+8);//printf���� f�� ���format(����)�� �������� �ǹ�
		
		System.out.println(2+1);
		
		//System.out <- ǥ�� ���:�����
		
		
		System.out.printf("Name:%s Height:%.3f Age:%d\n","kim", 174.12345, 24);
		//�̸�(���ڿ�), Ű(�Ǽ�), ����(����)������ printf�� �̿��ؼ� ���format
		
	*/	
		
	}
}