import java.util.*;
import java.io.*;

class Circle{
	public static void main(String [] args){
		String fileName;
		Scanner Keyboard = new Scanner(System.in);
		int order = 1;
		int radius;
		double surface;
		
		
		fileName = Keyboard.nextLine();
		
		File F = new File(fileName);
		if(!F.exists())System.out.println("doest not exists that " + fileName);
		
		try{
		Scanner ReadFile = new Scanner(F);
		
		
		while(ReadFile.hasNext()){
			radius = ReadFile.nextInt();
			surface = ReadFile.nextDouble();
			
			if(radius*radius*3.14 ==  surface){
				System.out.printf("%d 번째 원의 반지름은 %d, 넓이는 %.2f 입니다.\n", order, radius, surface);				
			}
			else{
				System.out.printf("%d 번째 원의 반지름은 %d이지만 넓이는 다릅니다. 실제 원 넓이 : %f\n", order, radius, 3.14*radius*radius);				
			}
			order++;
		}
		
		ReadFile.close();
		
		}catch(FileNotFoundException fnfe)
		{
			System.out.println("we can't filnd that file so, exit the program");
			return;
		}
		finally{
			ReadFile.close();
		}
		
		
		
	}
}