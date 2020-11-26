import java.util.Arrays;

class Movie implements Comparable{
	String title;
	String series;
	double grade;
	Movie(){}
	
	Movie(String t, String s, double g){
		title 	= t;
		series 	= s;
		grade 	= g;
	}
	
	public int compareTo(Object o){
		if(o instanceof Movie){
			if(grade<((Movie)o).grade) return -1;
			else if (grade>((Movie)o).grade) return 1;
			else return 0;
		}
		else{
			System.out.println("영화와 비교 불가능합니다. ");
			return 999;
		}
	}
	
	public String toString(){
		return String.format("제목: %s, 시리즈: %s, 평점: %.2f", title, series, grade);
	}
	
}
class MovieTest{
	public static void main(String args []){
		Movie[] movies = new Movie[5];
		movies[0] = new Movie("데드풀 2", "데드풀", 9.11);
		movies[1] = new Movie("인피니티 워", "어벤져스", 9.09);
		movies[2] = new Movie("데드풀", "데드풀", 8.53);
		movies[3] = new Movie("앤트맨과 와스프", "앤트맨", 8.92);
		movies[4] = new Movie("에이지 오브 울트론", "어벤져스", 8.59);
		
		//평점순 정렬
		Arrays.sort(movies);
		for(Movie movie:movies)	System.out.println(movie);
	}
}