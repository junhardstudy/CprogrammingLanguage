import java.util.Scanner;

class CastingTest{
	public static void main(String [] args){
		int tp = 0;
		long a = 1;
		float b = 2.2f;
		double c = 123.456F;//���� �ڷ���(float)�� ū �ڷ���(double)�� ���⿡ ���� ����
		
		Scanner S = new Scanner(System.in);
		
		
		//'/'������ ����
		//System.out.println(0/0); <- error
		//System.out.println(70/0); <- erro
		System.out.println(+90/0.0); //+infinity
		System.out.println(0/0.0); //NaN:Not a Number
		System.out.println(-7/0.0); //-infinity
		
		/*
		���ڿ�(����) "3"�� ����(int)�� �ٲٰ��� �ϴ� ���
		ĳ���� �����ڴ� �Ұ����ϰ� 
		*/
		System.out.println(args[0]);
		
		
		
		
		
		
		
		
		
		a =(long)b;
		System.out.print("a = "+a+", b = "+b);
		System.out.printf("\nc=%f \n", c);
		
	
		for(int i = 0; i <10; i++){
			System.out.printf("%d\t", (int)(Math.random()*6));
				//0�̻� 5������ ������ ���� ����
			System.out.printf("%d\t", (int)(Math.random()*11 + 10));
				//10�̻� 20������ ������ ���� ����
			System.out.printf("%d\n", (int)(Math.random()*21 -10));
				//-10�̻� 10������ ������ ���� ����
		}
		
		//ȭ���µ�(����)�� �Է¹޾� ���� �µ��� ��ȯ
		tp = S.nextInt();
		System.out.printf("���� %f", (5.0/9)*(tp - 32));
		
		System.out.println(5+3+": 5�� 3�� ��");
		System.out.println("5�� 3�� ��:"+5+3);//������ �̾��ִ� �ǹ̷� ���Ǵ� +�ڿ� ���� ��� +���� �� ������ �̾��ִ� �ǹ̷� �ο�� ���� ���� ��� ���� ���忡 �̾��ֱ� ���ؼ��� �Ʒ� ������ ���� ���
		System.out.println("5�� 3�� ��:"+(5+3));
		
		
		
	}
	
}