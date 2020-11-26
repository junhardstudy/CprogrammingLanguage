//String str = "Hello": 문자열의 길이
//str을 "yello"로 바꾸기
//자음의 개수

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
		
		
		
		//키보드에서 모든 종류의 문자를 받아 들일 때 자음의 개수 알아내기
		for(i=0; i < str.length(); i++){
			if((('a' < str_temp.charAt(i)) && (str_temp.charAt(i) < 'e') )||(('e' < str_temp.charAt(i))&& (str_temp.charAt(i) < 'i') )||(('i' < str_temp.charAt(i) )&& (str_temp.charAt(i) < 'o') )||(('o' < str_temp.charAt(i)) && (str_temp.charAt(i) < 'u' ))||(('u' < str_temp.charAt(i) )&& (str_temp.charAt(i) <= 'z' )))count++;
		}
			System.out.println("자음의 개수 : " +count+"개");
			
			
		//또는 switch 개수 활용
		str_temp = str.toLowerCase();//대문자는 고려치 않고 소문자로 통일 시켜서 비교 하기 위함
		
		for(i = 0; i < str_temp.length(); i++){
			if(str_temp.charAt(i) < 'a' || str_temp.charAt(i) > 'z')continue;//알파벳 문자가 아닌경우에는 고려해줄 필요가 없으므로 continue!
			switch(str_temp.charAt(i)){
				case 'a' : case 'e' : case 'i' : case 'o' : case 'u': mo++; break;//모음 개수 카운트
				default : ja++;//자음 개수 카운트
			}
		}
		
		System.out.println("자음 "+ja+"개 " + ", 모음" + mo + "개");
			
			
			
		String str_2 = "car", str_3 = "is", str_4 = "fast";
		
		//문자열을 이어서 표현 하는 방법
		System.out.println(str_2 + " " + str_3 + " " + str_4);
		System.out.println("car " + " is".concat(str_4));
		
	}
	
}