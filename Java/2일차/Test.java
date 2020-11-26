/*
	실수 자료형에 따른 underflow 테스트


*/




class Test{
	public static void main(String [] args){
		float a = 0.2f, b, sum1 = 0;
		double c = 0.2, d, sum2 = 0;
		int i;
		
		
		for(i =0; i< 500; i++){
			sum1 += a;
			sum2 += c;
			if(i >= 400)System.out.printf("processing : %f\n", sum1);
		}
		
		System.out.printf("float type : %.10f\ndouble type : %.10f", sum1, sum2);
		
		
	}
}