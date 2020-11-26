



import java.io.File;
import java.util.*;





class FileTest{
	public static void main(String [] args){
		
		//절대 경로
		File f = new File("C:\\Users\\Win7\\Desktop\\kjg");//File 또한 객체로 취급
		File f1 = new File("C:" + File.separator + "Users" + File.separator + "Win7");
		//플랫폼에 무관하게 접근 가능!
		
		//상대 경로(이 파일이 있는 폴더부터 시작)
		File f2 = new File("folderTest" + File.separator+"abc.java");
		

		System.out.println(f.exists());
		System.out.println(f1.exists());
		System.out.println(f.length());
		System.out.println(f2.exists());
		
		
		File txt1 = new File("text2.txt");
		File txt2 = new File("filetest" + File.separator + "text.txt");
		
		System.out.println(txt1.exists());
		System.out.println(txt2.exists());
		System.out.println(new Date(txt2.lastModified()));
		
		
		
		
		
		
		
		
		
		
	}
}