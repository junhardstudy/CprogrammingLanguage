import java.io.*;

//abc.txt파일에 Hello, World! 출력하기
class PrintWriterTest{//파일 출력
	public static void main(String [] args)throws Exception{
		//1.파일 객체를 생성
		File abc = new File("abc.txt");
		
		//2.파일에 출력 스트림을 연결
		PrintWriter pw = new PrintWriter(abc);
		
		//3.파일에 쓰기
		pw.println("Helllo, World! ");
		System.out.println("파일 생성 완료");
		
		//4.스트림 닫기
		//스트림을 닫아주지 않을 경우 변경 내용이 저장이 안됨
		pw.close();
		
	}
}