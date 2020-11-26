import java.util.Scanner;

class Main{
	public static void main(String [] args){
		int tempx, tempy, index, temp;
		
		
		Scanner S = new Scanner(System.in);
		int [] x = new int[3];
		int [] y = new int[3];
		
		
		while(true){
		x[0] = (int)(Math.random()*21 - 10);
		y[0] = (int)(Math.random()*21 - 10);
		x[1] = x[0] + (int)(Math.random()*21 - 10);
		y[1] = (int)(Math.random()*21 - 10);
		x[2] = x[0] + x[1] + (int)(Math.random()*21 - 10);
		y[2] = (int)(Math.random()*21 - 10);
		
		System.out.printf("(%d, %d)  (%d, %d) (%d, %d)\n",x[0], y[0], x[1], y[1], x[2], y[2]);
		
		
		
		//좌표값을 배열로 바꾸고, 좌표 순서를 오름 차순으로 정렬 해볼것
	
		
		if((x[2] == x[1]) && (x[1] == x[0])){
			System.out.print(0);//y축에 평행한 경우
			//return;
		}
		
		
		if(Math.abs((double)(y[2] - y[1])/(x[2] - x[1])) == Math.abs((double)(y[1] - y[0])/(x[1] - x[0]))){
			System.out.print(0);
			//return;
		}
		
		if(y[2] == y[1]){
			if(y[0] < y[1]){
				System.out.println(-1);
				//return;
			}
			else if(y[0] > y[1]){
				System.out.println(1);
				//return;
			}
			else {
				System.out.println(0);//x 축에 평행한 직선
				//return;
			}
		}
		
		if(y[2] > y[1]){
			System.out.println(1);
			//return;
		}
		if(y[2] < y[1]){
			System.out.println(-1);
			//return;

			}
			
			
			if((x[0]-x[1])*(y[2]-y[1]) - (y[0] - y[1])*(x[2]-x[1]) < 0)System.out.println(-1);
			else if((x[0]-x[1])*(y[2]-y[1]) - (y[0] - y[1])*(x[2]-x[1]) > 0)System.out.println(1);
			else System.out.println(0);
			try{
			Thread.sleep(1000);
			}catch(InterruptedException ex){}
			
			System.out.println();
		}		
	}
}
