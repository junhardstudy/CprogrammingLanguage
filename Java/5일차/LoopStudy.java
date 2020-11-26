/*
	자바 5일차
	Loop문 연습


*/
import java.lang.*;

class LoopStudy{
	public static void main(String [] args){
		int i, j;
		//for(i = 0 ; i < 100 ; i++)
		//	System.out.println("Welcome to the Java!");
		
		for(i = 1 ; i < 11 ; i++)
			System.out.printf("%d ",i);
		System.out.println("");
		
		for(i = 0; i < 5; i++){
			for(j = 1; j <11; j++)
				System.out.printf("%d ", j);
			System.out.println("");
		}
		
		for(i = 0; i<='Z' - 'A'; i++)
			System.out.printf("%c ", 'A' + i);
		System.out.println("");
		
		for(i = 0; i < 5; i++){
			for(j = 1 ; j <= 10; j++)
				System.out.printf("%2d ",j + i*10);
			System.out.println("");
		}
		i = 0;
		while(true){
			try{
				Thread.sleep(500);
			}catch(InterruptedException e){
			}
			System.out.printf("%d\r", i++);
		}
		
	}
}