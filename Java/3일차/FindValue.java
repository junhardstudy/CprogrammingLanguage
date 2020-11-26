class FindValue{
	public static void main(String [] args){
		int today, after, result;
		today = Integer.parseInt(args[0]);
		after = Integer.parseInt(args[1]);
		result = (today + after) % 7;
		System.out.printf("%d요일로부터 %d일 후는 %d요일 입니다", today, after, result);
	}
}