import java.io.*;

//abc.txt���Ͽ� Hello, World! ����ϱ�
class PrintWriterTest{//���� ���
	public static void main(String [] args)throws Exception{
		//1.���� ��ü�� ����
		File abc = new File("abc.txt");
		
		//2.���Ͽ� ��� ��Ʈ���� ����
		PrintWriter pw = new PrintWriter(abc);
		
		//3.���Ͽ� ����
		pw.println("Helllo, World! ");
		System.out.println("���� ���� �Ϸ�");
		
		//4.��Ʈ�� �ݱ�
		//��Ʈ���� �ݾ����� ���� ��� ���� ������ ������ �ȵ�
		pw.close();
		
	}
}