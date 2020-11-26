/*
	java 2����
	���� ������ ���� ����Ŭ ����: https://docs.oracle.com/javase/6/docs/api/java/util/Formatter.html#syntax
	
	���� ������ ���� : %[argument_index$][flags][width][.precision]conversion
	
	���۶� �ڷ��� ũ��� overflow�� underflow�� ���� ����
	�ĺ��� ���ʹ� ���� ���� � �Ұ�



*/

import java.util.Scanner;
//Scanner Ŭ������ �ڹٿ��� �⺻������ ����: ��ĵ �뵵
//java.util�̶�� ��Ű�� �ȿ� Scanner Ŭ������ ����
//��Ű�� = ����

class BufferStudy{
	public static void main(String [] args){
		//�ʱ�ȭ = ���� ó�� ����
		int num;
		//�޸𸮻󿡼� ������ �����Ҽ� �ִ� 4����Ʈ�� ������ Ȯ���ǰ�, �� �޸� ������ �̸��� i��� �ٿ���, ���Ŀ� ����� ���� ������ �ؼ����� �ǹ�.
		double flo;
		//8����Ʈ Ȯ��
		String str;
		Scanner Sc = new Scanner(System.in);
		//�ڷ��� �ĺ���(�����̸�); <- ���� ����
		
		/*
		���� �ڷ���
		-������: byte(1byte), short(2byte), int(4byte), long(8byte)
		-�Ǽ���: float(4byte, ��ȿ ���� 7 ~ 8�ڸ� ǥ�� ����), double(8byte, ��ȿ ���� 15 ~ 16�ڸ� ǥ�� ����) : ���е������� byte���� ����
		-������: char <- ���� �ϳ� ���尡��('a', '��', '��' ...) 2byte�Ҵ�
		-����: boolean <-(true, false) 1bit�� ǥ���� �����ϳ� �޸𸮻󿡼��� 1bit �Ҵ��� �ȵǱ⿡ 1byte�� �Ҵ�
		
		ǥ���� �� �ִ� �ڷ��� ������ ���⿡ �ڷ����� ������ �پ���
		����)�ڹٿ����� unsigned ���� ����
		
		�ڷ��� ũ�Ⱑ ǥ���� �� �ִ� �ڷ����� ũ�⸦ ������� overflow �߻�
		underflow�� �Ǽ������� ���е��� ������� �ǹ�
		
		�ĺ��� ����
			1.Ŭ�������� �빮�ڷ� ����
			2.�޼ҵ�, �������� �ҹ��ڷ� ����
			3.�� �ܾ� �̻��� �ռ���� �� ��° �ܾ� ù���ڴ� �빮�ڷ� ����(��)nextInt
			
		*/
		
		char c = '��';
		boolean b = true;
		boolean b1 = 2>3;//���Ǻηε� ���� ����, �� �� ���� false
		System.out.println(b + "\t" + b1 + "\t" + c);
		
		
		
		System.out.print("����: ");
		num = Sc.nextInt();//��ĳ�ʿ��� ���� �ϳ� �о�޶�� ��û
		
		/*
			���ۻ� ���Ͱ� ���� �־ ���ڿ� str�� Ű����κ��� ���� ������ �� �� ����.
			���� ���ۿ� �ִ� ���͸� ����� ���� .nextLine();�޼��� ȣ��
		*/
		//Sc.nextLine();
		//���� �ʿ� ����. nextDouble()�޼��忡���� ���� ó������ ������ �Ǽ����� ã�� ������ 
		System.out.print("�Ǽ�: ");
		flo = Sc.nextDouble();
		
		Sc.nextLine();//���ۻ� �ִ� ���Ͱ� ������.
		
		System.out.print("���ڿ�: ");
		str = Sc.nextLine();//��ĳ�ʿ��� ���� �ϳ� �о�޶�� ��û
		
		System.out.println("�Է� ���ڿ�: "+str+", �Է� ����: "+num +", �Է� �Ǽ� :" +flo);
		//println() �޼��忡�� ���� ������ ����ϰ��� �ϴ� ��� +�̿�
		
		System.out.print("abc"+"def");
		//print() �޼����� ��쿡���� ���ڿ����� �ٿ� ��� �ϰ��� �ϴ� ��� +�̿�
		
		
		/*
			����� ����
			\n : ����
			\t : �Ǹ�ŭ ���� ���
			\b : Ŀ�� ��ĭ �̵�
			\r : Ŀ�� �� ��ĭ���� �̵�
			����ڴ� ��� ��¸޼��忡�� ��� ����
		*/
		
		System.out.println("���\b��");//'��'�ڸ��� Ŀ���� ���� �븦 �����
		System.out.println("���\b");//'���' �״�� ǥ��
			
	}
	
}