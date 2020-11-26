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
				System.out.printf("%d ��° ���� �������� %d, ���̴� %.2f �Դϴ�.\n", order, radius, surface);				
			}
			else{
				System.out.printf("%d ��° ���� �������� %d������ ���̴� �ٸ��ϴ�. ���� �� ���� : %f\n", order, radius, 3.14*radius*radius);				
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