/*
	java 2����
	���� ������ ���� ����Ŭ ����: https://docs.oracle.com/javase/6/docs/api/java/util/Formatter.html#syntax
	
	���� ������ ���� : %[argument_index$][flags][width][.precision]conversion


*/



class NumberTest{
	public static void main(String [] args){
		int a = 0b10;//0b+���� : ���ڸ� �������� �ؼ�
		//int b = 0b73; <-������ �Ұ���, 73�� �������� �ƴ�
		int b = 073; //0+���� : ���ڸ� �������� �ؼ�
		int c = 0x1f; //0x+���� : ���ڸ� 16������ �ؼ�
		int d = 2_3456_7891;//_�� ������ ������, ������ �Ҷ��� ������
		
		//b�� 8, 10, 16���� ���·� ���������� ���� �ٿ��� ���
		
		System.out.printf("8���� : %-#8o, 16���� : %1$#-8x, 10���� : %1$d", b);
		System.out.printf("\n%d", d);
		
		//System.out.format("%x\n", c);
		
		/*
			������ ����������
			%d = decimal
			%o = octal
			(%h �Ǵ�)%x = hexadecimal (%h�� �� ������ ��찡 �����Ƿ� ���������� %x ���)
			%#conversion�� ��� #�� �� �������� �˷���
			���������� -�� ��� width�� �������� ���밡��
		*/
		
		
		 /*
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
		*/
	}
}