//파일 복사 프로그램
//FileTest.java를 복사하는 프로그램 작성하기
//복사본 파일명은 copy.java
//FileTest.java
import java.util.Scanner;
import java.io.*;


class Test6{
	public static void main(String [] args){
		File original = new File("FileTest.java");
		File duplicate = new File("copy.java");
		String tmp;
		
		if(original.exists() == false){
			System.out.println("does not exists such a file");
			return;
		}
		try{
		Scanner S = new Scanner(original);
		PrintWriter pw = new PrintWriter(duplicate);
		
		while(S.hasNext() != false){
			tmp = S.nextLine();
			
			tmp = tmp.replaceAll("println()", "HELLO");
			pw.println(tmp);
			
		}
		
		pw.close();
		S.close();
		}catch(FileNotFoundException fnfe){
			System.err.println("error");
		}
	}
}