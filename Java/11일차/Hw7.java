import java.util.*;

class Hw7{
	public static void main(String [] args){
		Scanner S = new Scanner(System.in);
		StringManipulate StrManipulate = new StringManipulate();
		String str1, str2, str;
		System.out.print("sentence 1 : ");
		str1 = S.nextLine();
		System.out.print("sentence 2 : ");
		str2 = S.nextLine();
		
		str = StrManipulate.plusSentence(str1, str2);
		System.out.println(str);
		
		
		
		
	}
}

class StringManipulate{
	
	StringManipulate(){}//default »ý¼ºÀÚ
	
	
	static String plusSentence(String str1, String str2){
		return str1+str2;
	}
	
	static void sameDistinguish(String str1, String str2){
	}
	
	
	
	
	
	
}