//RandomŬ������ ����� ���� ����
//����ڿ��� -10�̻� 10������ �ϳ��� ���� �����ϰ�
//������ -10�̻� 10���� ���̿��� �ϳ� ���� �ѵ�
//����ڰ� ������ ����ٸ� �հ�!
//�ƴϸ� ���հ� ���!

import java.util.Random;
import java.util.Scanner;
import java.lang.*;

class RandomNumber{
	public static void main(String [] args){
		int rand_num, answer;
		Random R = new Random();
		Scanner S = new Scanner(System.in);
	
		
		rand_num = S.nextInt();
		answer = (int)(R.nextDouble() * 21 -10);
		//�Ǵ� answer = R.nextInt(21) - 10;
		
		while(true){
		if(rand_num == answer){
			System.out.printf("%d correct!", answer);
			return;
		}
		else {
			System.out.printf("%d fail\nretry :", answer);
			rand_num = S.nextInt();
		}
		
		}
	//	System.out.println(R.nextDouble());
	//	System.out.println(R.nextInt(3));
		
	}
}