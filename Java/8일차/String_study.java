//String str = "Hello": ���ڿ��� ����
//str�� "yello"�� �ٲٱ�
//������ ����

class String_study{
	public static void main(String [] args){
		int count = 0, i, mo = 0, ja = 0;
		
		String str = "a b@5c d^(efg";
		String str_temp;
		
	
		
		System.out.println(str = str.replace("H", "y"));
		//
		
		str_temp = str.toLowerCase();
		System.out.println(str);
		System.out.println(str_temp);
		
		
		
		//Ű���忡�� ��� ������ ���ڸ� �޾� ���� �� ������ ���� �˾Ƴ���
		for(i=0; i < str.length(); i++){
			if((('a' < str_temp.charAt(i)) && (str_temp.charAt(i) < 'e') )||(('e' < str_temp.charAt(i))&& (str_temp.charAt(i) < 'i') )||(('i' < str_temp.charAt(i) )&& (str_temp.charAt(i) < 'o') )||(('o' < str_temp.charAt(i)) && (str_temp.charAt(i) < 'u' ))||(('u' < str_temp.charAt(i) )&& (str_temp.charAt(i) <= 'z' )))count++;
		}
			System.out.println("������ ���� : " +count+"��");
			
			
		//�Ǵ� switch ���� Ȱ��
		str_temp = str.toLowerCase();//�빮�ڴ� ���ġ �ʰ� �ҹ��ڷ� ���� ���Ѽ� �� �ϱ� ����
		
		for(i = 0; i < str_temp.length(); i++){
			if(str_temp.charAt(i) < 'a' || str_temp.charAt(i) > 'z')continue;//���ĺ� ���ڰ� �ƴѰ�쿡�� ������� �ʿ䰡 �����Ƿ� continue!
			switch(str_temp.charAt(i)){
				case 'a' : case 'e' : case 'i' : case 'o' : case 'u': mo++; break;//���� ���� ī��Ʈ
				default : ja++;//���� ���� ī��Ʈ
			}
		}
		
		System.out.println("���� "+ja+"�� " + ", ����" + mo + "��");
			
			
			
		String str_2 = "car", str_3 = "is", str_4 = "fast";
		
		//���ڿ��� �̾ ǥ�� �ϴ� ���
		System.out.println(str_2 + " " + str_3 + " " + str_4);
		System.out.println("car " + " is".concat(str_4));
		
	}
	
}