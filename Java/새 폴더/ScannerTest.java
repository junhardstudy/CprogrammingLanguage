//�̸� �г� ����

import java.io.*;
import java.util.Scanner;

class Student {
	String name;
	int grade;
	double rate;
	
	Student(){}
	Student(String name, int grade, double rate){
		this.name = name;
		this.grade = grade;
		this.rate = rate;
	}
	
	void setAll(){
		this.name = name;
		this.grade = grade;
		this.rate = rate;
	}
}


class ScannerTest{
	public static void main(String [] args){
		Student [] stdperson = new Student[3];
		int i = 0;
		
		
		//1.���� ���� ��ü ����
		File f = new File("std.txt");
		
		//2.���� �������� ������ ������ �����ϴ��� �Ǵ�
		if(f.exists() == false){
			System.out.println("does not exist such a file!");
			System.exit(0);
			//return;
		}
		
		try{
		Scanner S = new Scanner(f);//���Ͽ� �Է� ��Ʈ���� ����
		//System.in = Ű���� ǥ�� �Է�
		
		
		//���ʻ� �빮�ڸ� ���� ������(fnfe)
		
		//3.���� �ϴ� ��쿡�� ���Ͽ��� �ڷ� �а� ����Ϳ� ���
		//System.out.println(S.next());
		
		
		System.out.println("���� ���� : ");
		//���Ͽ��� �ڷ� �б� : ���Ͽ� �ڷᰡ �����ϴ� ���ȿ��� ����ؼ� �б� �۾��ϱ�
		while(S.hasNext()){
			
			stdperson[i].name = S.next();
			stdperson[i].grade = S.nextInt();
			stdperson[i].rate = S.nextDouble();
			
		}
		
		for(Student temp : stdperson){System.out.printf("�̸� : %s, �г� %d, ���� : %.2f",temp.name, temp.grade, temp.rate);
		System.out.println();
		}
		//.haseNext() : ��ĳ�ʿ��� �������� ���� �ڷᰡ �ִٸ� true�� ��ȯ �ƴϸ� false
		
		}catch(FileNotFoundException fnfe){
			fnfe.printStackTarce();
			System.err.println("FileNotFoundException �߻��Ͽ� ���α׷��� ���� �մϴ�.");
			
		}
		
		//4.��Ʈ�� �ݱ�
		
		
		
	}
}