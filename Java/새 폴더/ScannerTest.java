//이름 학년 학점

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
		
		
		//1.읽을 파일 객체 생성
		File f = new File("std.txt");
		
		//2.내가 읽으려는 파일이 실제로 존재하는지 판단
		if(f.exists() == false){
			System.out.println("does not exist such a file!");
			System.exit(0);
			//return;
		}
		
		try{
		Scanner S = new Scanner(f);//파일에 입력 스트림을 연결
		//System.in = 키보드 표준 입력
		
		
		//관례상 대문자만 따서 적어줌(fnfe)
		
		//3.존재 하는 경우에는 파일에서 자료 읽고 모니터에 출력
		//System.out.println(S.next());
		
		
		System.out.println("파일 내용 : ");
		//파일에서 자료 읽기 : 파일에 자료가 존재하는 동안에는 계속해서 읽기 작업하기
		while(S.hasNext()){
			
			stdperson[i].name = S.next();
			stdperson[i].grade = S.nextInt();
			stdperson[i].rate = S.nextDouble();
			
		}
		
		for(Student temp : stdperson){System.out.printf("이름 : %s, 학년 %d, 학점 : %.2f",temp.name, temp.grade, temp.rate);
		System.out.println();
		}
		//.haseNext() : 스캐너에서 다음으로 읽을 자료가 있다면 true를 반환 아니면 false
		
		}catch(FileNotFoundException fnfe){
			fnfe.printStackTarce();
			System.err.println("FileNotFoundException 발생하여 프로그램을 종료 합니다.");
			
		}
		
		//4.스트림 닫기
		
		
		
	}
}