/*
	�ڹ� 4����


	else if�̳� switch case���� ���
	�����Ϸ��� ���� ��Ȳ�� ��� ���� ���ϱ⿡
	else if�� �׻� else�� ������
	switch case�� �׻� default�� ������
	
	�ڹ� 1���� ���� �ڷ� �߰� ���� ����1&2 ��
	
	�ڹ� ���α׷��� ���ߴ����� Ŭ����
	��� �ڹ� �ҽ� ������ Ȯ���ڴ� .java
	���α׷����� �����͸� �����ϴ� ������ ����
	������ ���� �����ϴ� ������ ���� �̶���
	���൵�߿� ���� ������ �ʴ� ���� final ���
	
	1.short
	2.short
	3.2^-2
	4.28.9
	5.true, false
	6.������ ���ο� ���� ���ԵǸ� ���� ���� ������
	7.�������� ��ҹ��� ����, ���� �ƴ�
	8.���ڰ� ���� ���� 2��°, Ư����ȣ�� ���� ���� 6��°
	
*/




import java.util.*;


class PredictDate{
	public static void main(String [] args){
		String str;
		int after, today, result;
		Scanner Sc = new Scanner(System.in);
		
		System.out.print("������ ");
		str = Sc.nextLine();
		System.out.print("�� �� ��?");
		after = Sc.nextInt();
		
		
		switch(str){
			case "������": today = 0; break;
			case "ȭ����": today = 1; break;
			case "������": today = 2; break;
			case "�����": today = 3; break;
			case "�ݿ���": today = 4; break;
			case "�����": today = 5; break;
			case "�Ͽ���": today = 6; break;
			default : System.out.println("error"); return;
		}
		
		result = (today + after) % 7;
		
		switch(result){
			case 0: System.out.printf("%d�� �Ĵ� ������", after); break;
			case 1: System.out.printf("%d�� �Ĵ� ȭ����", after); break;
			case 2: System.out.printf("%d�� �Ĵ� ������", after); break;
			case 3: System.out.printf("%d�� �Ĵ� �����", after); break;
			case 4: System.out.printf("%d�� �Ĵ� �ݿ���", after); break;
			case 5: System.out.printf("%d�� �Ĵ� �����", after); break;
			case 6: System.out.printf("%d�� �Ĵ� �Ͽ���", after); break;
			default : System.out.println("error"); return;
		}
		
		
	}
}