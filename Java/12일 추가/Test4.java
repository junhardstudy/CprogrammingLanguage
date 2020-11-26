import java.util.Arrays;

class Student implements Comparable{
	int age;
	
	Student(){}
	Student(int age){
		this.age = age;
	}
	
	public int compareTo(Object obj){
		if(obj instanceof Student){
			if(this.age > ((Student)obj).age)return 1;
			
			else if(this.age < ((Student)obj).age)return -1;
			
			else return 0;
		}
		else{
			System.out.println("�� �Ұ�");
			return 9999;
		}
	} 
}

class Animal{
	int age;
	
	Animal(){}
	Animal(int age){
		this.age = age;
	}
}

class Test4{
	public static void main(String [] args){
		Student [] s = {new Student(25), new Student(25), new Student(26), new Student(2), new Student(6), new Student(5), new Student(3), new Student(15)};
		
		String [] str = {"Cbcd", "ac", "AeDfc", "Ac"};
		
		
		Animal a = new Animal(3);
		System.out.println(s[0].compareTo(s[1]));
		System.out.println(s[0].compareTo(s[2]));
		System.out.println(s[0].compareTo(a));
		
		System.out.println();
		Arrays.sort(s);//Arrays Ŭ������ sort�޼ҵ带 ȣ���Ҷ�, �Ű������� Comparable �������̽��� ������ Ŭ������ �迭�� �־��ָ� �ڵ������� �������� ���ĵ� ���� Ŭ���������� �����߱⿡ sort�޼ҵ�� static���� �˼� ����
		
		System.out.println();
		
		for(Student tmp : s)System.out.println(tmp.age);
		
		System.out.println();
		

		Arrays.sort(str);
		for(String stmp : str)System.out.println(stmp);
	}
}


/*
public interface Comparable{
	
	
}

*/