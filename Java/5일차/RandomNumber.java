//Random클래스를 사용한 난수 생성
//사용자에게 -10이상 10이하의 하나의 수를 추측하고
//난수도 -10이상 10이하 사이에서 하나 생성 한뒤
//사용자가 난수를 맞춘다면 합격!
//아니면 불합격 출력!

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
		//또는 answer = R.nextInt(21) - 10;
		
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