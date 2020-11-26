import java.util.*;
import java.io.*;
import java.lang.*;


class TEst{
	public static void main(String [] args){
		Scanner KeyBoard = new Scanner(System.in);
		System.out.print("what read file names? :");
		File ReadFile = new File(KeyBoard.nextLine());
		
		if(!ReadFile.exists()){
			System.out.println("does not exists such a file");
			return ;
		}
		
		Student [] std = new Student[3];
		int i =0;
		
		System.out.print("what write file names? : ");
		File WriteFile = new File(KeyBoard.nextLine()+".txt");
		if(WriteFile.exists()){
			System.out.println("already exists such file!");
			return;
		}
		
		
		try{
		Scanner ScanfrFile = new Scanner(ReadFile);
		PrintWriter pw = new PrintWriter(WriteFile);
		
		
		
			while(ScanfrFile.hasNext()){
			
				std[i] = new Student(ScanfrFile.next(), ScanfrFile.nextInt(), ScanfrFile.nextDouble());
			
				pw.println(std[i].toString());
				i++;
			
			}
			ScanfrFile.close();
			//pw.close();
		
		}catch(FilerException fe){
			System.out.println("IOE occur!");
		
		
		}catch(FileNotFoundException fnfe){
			System.out.println("읽을 파일 없음");
		
		}
				
		System.out.println("done writing file!");
		
		
		
		
		
	}
}

class Student{
	private String name;
	private int grade;
	private double score;
	
	Student(){}
	Student(String name, int grade, double score){
		this.name = name;
		this.grade = grade;
		this.score = score;		
	}
	
	public String toString(){
		return String.format(this.name + this.grade + this.score);
	}
	
	
	
}