/*
	�ڹ� 3����
	final Ű���带 �̿��� ���ȭ ��Ű��
	MathŬ������ �޼ҵ�, �ʵ�


*/

import java.util.Scanner;

class Circle{
	public static void main(String [] args){
		double radius, length, surface;
		//final double PI = 3.14;//final = ���ȭ��Ŵ ���� �ϴ��ڵ忡�����ʹ� pi�� ���� �Ұ�
		
		Scanner S = new Scanner(System.in);
		
		
		//�ڻ��� 0 ��, ��Ʈ 0 ����ϱ� ��� �غ���
		System.out.format("%.2f\n", Math.cos(0));
		System.out.format("%.2f\n", Math.sqrt(0));
		
		
		
		/*random() method ����
			random() method�� 0.0�̻� 1.0�̸� �� return
		*/
		
		System.out.format("%f", Math.random()*10);
		
		
		
		
		
		
		System.out.print("������ :");
		radius = S.nextDouble();
		
		length = 2*Math.PI*radius;
		surface = Math.PI*Math.pow(radius, 2);
		//Math Ŭ������ java.lang ��Ű���ȿ� �����ϸ�(java.lang.Math)  java.lang ��Ű���ȿ� ���� Ŭ������ imort ���� ��밡��.
		
		System.out.printf("�ѷ� : %.3f, ���� : %.3f", length, surface);
	}
} 