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
			System.out.println("��ȭ�� �� �Ұ����մϴ�. ");
			return 999;
		}
	}
	
	public String toString(){
		return String.format("����: %s, �ø���: %s, ����: %.2f", title, series, grade);
	}
	
}
class MovieTest{
	public static void main(String args []){
		Movie[] movies = new Movie[5];
		movies[0] = new Movie("����Ǯ 2", "����Ǯ", 9.11);
		movies[1] = new Movie("���Ǵ�Ƽ ��", "�����", 9.09);
		movies[2] = new Movie("����Ǯ", "����Ǯ", 8.53);
		movies[3] = new Movie("��Ʈ�ǰ� �ͽ���", "��Ʈ��", 8.92);
		movies[4] = new Movie("������ ���� ��Ʈ��", "�����", 8.59);
		
		//������ ����
		Arrays.sort(movies);
		for(Movie movie:movies)	System.out.println(movie);
	}
}