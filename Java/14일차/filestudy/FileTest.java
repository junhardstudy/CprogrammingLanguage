



import java.io.File;
import java.util.*;





class FileTest{
	public static void main(String [] args){
		
		//���� ���
		File f = new File("C:\\Users\\Win7\\Desktop\\kjg");//File ���� ��ü�� ���
		File f1 = new File("C:" + File.separator + "Users" + File.separator + "Win7");
		//�÷����� �����ϰ� ���� ����!
		
		//��� ���(�� ������ �ִ� �������� ����)
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