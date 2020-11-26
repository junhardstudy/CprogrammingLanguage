import java.util.Arrays;

class Movie implements Comparable{
	String name;
	double rate;
	
	Movie(){}
	Movie(String name, double rate){
		this.name = name;
		this.rate = rate;
		
	}
	
	@Override
	public int compareTo(Object obj){
		if(obj instanceof Movie){
			if(this.rate > ((Movie)obj).rate) return -5;
			else if(this.rate < ((Movie)obj).rate)return 5;
			else return 0;
		}
		else{
			System.out.print("plz insert correct instance");
			return 999;
		}
	}
}

class Test{
	public static void main(String [] args){
	Movie [] m = {new Movie("abc", 9.8), new Movie("bcc", 9.3), new Movie("ece", 10.0)};
	
	for(Movie temp : m)System.out.println(temp.rate);
	Arrays.sort(m);
	System.out.println();
	for(Movie temp : m)System.out.println(temp.rate);
	}
}