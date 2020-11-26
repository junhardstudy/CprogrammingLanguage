# JAVA

## 1일차

Notepad++, JDK설치 및 환경변수 등록등 개발환경 만들기.

기본적인 input(키보드)/output(모니터)


## 2일차

서식 지정자 종류 및 순서

Scanner클래스에 대한 여러가지 method(Scanner.nextInt(), Scanner.nextLine())

## 3일차

### Hw1 과제(Test.java)

양의 정수를 2개 입력으로 받고, 그 두 수와 두 수의 합을 각각 10진수, 8진수, 16진수로 아래와 같은 형식으로 출력하는 프로그램을 작성하시오.

* 각 수와 테이블 제목의 출력은 각각 11칸을 잡고 이에 대해 왼쪽 혹은 오른쪽 정렬이 되도록 출력할 것.

* 10진수의 경우는 부호 표시를 할 것(양수인 경우에는 +를 표시해 줄 것). 

```java
import java.util.Scanner;


class Test{
	public static void main(String [] args){
		int num1, num2;
		Scanner S = new Scanner(System.in);
		
		System.out.print("첫번째 양의 정수 :");
		num1 = S.nextInt();
		System.out.print("두번째 양의 정수 :");
		num2 = S.nextInt();
		System.out.print("\n");
		
		System.out.printf("%-11s|%-11s|%-11s|%-11s|\n", "number", "deciaml", "octal", "hexadecimal");
		System.out.printf("%-11s|%+11d|%2$#11o|%2$#11x|\n", "number 1", num1);
		System.out.printf("%-11s|%+11d|%2$#11o|%2$#11x|\n", "number 2", num2);
		System.out.printf("%-11s|%-+11d|%2$-#11o|%2$-#11x|\n", "sum", num1 + num2);
	}
}
```

여러가지 분기문

자료형간의 Casting

Math class의 여러가지 field와 method를 이용하여 원의 반지름 구하기

cmd로부터 여러 input arguments 받기

## 4일차



## 5일차

Random class를 이용한 난수 생성및 handling

여러가지 Loop문

try~catch문을 통한 예외처리 간단하게 하기
<br>
<br>
<br>

### Hw2 과제(RandomNumber.java)
-10이상 10이하의 임의의 정수형 난수를 생성하고, 사용자가 입력한 값이 난수와 일치한다면 “일치”, 난수와 절댓값은 같지만 부호는 다르다면 “절댓값만 일치(부호는 다
름)”, 그 외의 경우는 “불일치”를 출력하는 프로그램을 작성하시오. 

-> 단, 사용자는 command line에 정수를 입력한다. 사용자가 command line에 추측값을 입력하지 않은 경우 사용법을 알려주고, 프로그램을 종료시킬 것. 

```java
//Random클래스를 사용한 난수 생성
//사용자에게 -10이상 10이하의 하나의 수를 추측하고
//난수도 -10이상 10이하 사이에서 하나 생성 한뒤
//사용자가 난수를 맞춘다면 합격!
//아니면 불합격 출력!

import java.util.Random;
import java.util.Scanner;
import java.lang.*;

class RandomNumber{
	public static void main(String [] args){
		int rand_num, answer;
		Random R = new Random();
		Scanner S = new Scanner(System.in);
	
		
		rand_num = S.nextInt();
		answer = (int)(R.nextDouble() * 21 -10);
		//또는 answer = R.nextInt(21) - 10;
		
		while(true){
		if(rand_num == answer){
			System.out.printf("%d correct!", answer);
			return;
		}
		else {
			System.out.printf("%d fail\nretry :", answer);
			rand_num = S.nextInt();
		}
		
		}
	//	System.out.println(R.nextDouble());
	//	System.out.println(R.nextInt(3));
		
	}
}
```

### Hw2 과제(Hw_test.java)

두 수와 연산자 (+, -, *, %, /)를 입력으로 받아들여 이를 계산하여 출력하는 프로그램

* 입력 받는 두 수는 정수일 수도, 소수일 수도 있음.

* 입력을 한번에 식으로 입력 받아도 되고, 연산자와 피 연산자를 하나 하나 입력 받아도 됨 (입력 양식은 본인이 정하면 됨).

* 특히, 나눗셈에 유의해서 올바른 결과를 낼 것.

* 정수결과는 정수로, 소수 결과는 소수점 둘째 자리까지만 나타내도록 할 것

```java
import java.util.*;

class Hw_Test{
	public static void main(String [] args){
		int rand_num, num;
	
		
		if(args.length != 1){
			System.out.print("error");
			return;
		}
		
		num = Integer.parseInt(args[0]);
		rand_num = (int)(Math.random() * 21 - 10);
		
		if(num == rand_num)System.out.print("correct");
		else if(num == Math.abs(rand_num))System.out.printf("absolute correct %d ", rand_num);
		else System.out.printf("no %d", rand_num);
		
		
		//---------------------------------구	분---------------------------------
		
		double num_1, num_2, result;
		String operator;
		Scanner Sc = new Scanner(System.in);
		
		System.out.print("\n 수식:");
		num_1 = Sc.nextDouble();
		operator = Sc.next();
		num_2 = Sc.nextDouble();
		
		switch(operator){
			case "+":
				result = num_1 + num_2;
				if((int)result - result == 0.0)System.out.printf("result = %d", (int)result);else System.out.printf("result = %.5f", result);		
				break;
			case "-":
				result = num_1 - num_2;
				if((int)result - result == 0.0)System.out.printf("result = %d", (int)result);else System.out.printf("result = %.5f", result);		
				break;
			case "/":
				result = num_1 / num_2;
				if((int)result - result == 0.0)System.out.printf("result = %d", (int)result);else System.out.printf("result = %.5f", result);		
				break;
			case "%":
				result = num_1 % num_2;
				if((int)result - result == 0.0)System.out.printf("result = %d", (int)result);else System.out.printf("result = %.5f", result);		
				break;
			default : System.out.println("Syntax Error!");
		}
		
		//---------------------------------구	분---------------------------------

		
		
		
		int int_num, temp;
		
		System.out.print("자릿수 구분");
		int_num = Sc.nextInt();
		
		temp = int_num/(int)Math.pow(10, 4);
		int_num %= int_num%(int)Math.pow(10, 4);
		
		if(temp > 1)System.out.printf("%d만", temp);
		else System.out.print("만");
		
		temp = int_num/Math.pow(10, 3);
		int_num %= int_num%Math.pow(10, 3);
		
		if(temp > 1)System.out.printf("%d천", temp);
		else if(temp == 1)System.out.print("천");
		
		temp = int_num/Math.pow(10, 2);
		int_num %= int_num%Math.pow(10, 2);
		
		if(temp >1)System.out.printf("%d백", temp);
		else if(temp == 1)System.out.print("백");
		
		temp = int_num/(int)Math.pow(10, 4);
		int_num %= int_num%(int)Math.pow(10, 4);
		
		if(temp > 1)System.out.printf("%d십", temp);
		else if(temp == 1)System.out.print("십");
		
		temp = int_num/(int)Math.pow(10, 4);
		int_num %= int_num%(int)Math.pow(10, 4);
		
		if(temp > 1)System.out.printf("%d", temp);
		else if(temp == 1)System.out.print("일");
		
		
		
	}
}
```

## 6일차

### HW2 과제(Test.java)

입력받은 정수를 백, 십, 일 단위로 분리하기

```java
import java.util.*;

class Test{
	public static void main(String [] args){
		double number;
		int integer_number, absolute, temp;
		Scanner S = new Scanner(System.in);
		
		System.out.print("-1000초과, 1000미만의 실수: ");
		number = S.nextDouble();
		integer_number = (int)number;
		
		System.out.printf("입력하신 실수의 정수 부분: %d\n", integer_number);
		
		if((integer_number & 0b10000000000000000000000000000000) == 0) absolute = integer_number;
		else absolute = - integer_number;
		
		
		temp = absolute / 100;
		if(temp > 1)System.out.printf("%d백", temp);
		if(temp == 1)System.out.printf("백");
		absolute %= 100;
	
	
		temp = absolute / 10;
		if(temp > 1)System.out.printf("%d십",temp);
		if(temp == 1)System.out.printf("십");
		absolute %= 10;
				
		if(absolute > 1)System.out.printf("%d",absolute);
		if(absolute == 1)System.out.printf("일");
						
	}
}
```

반복문을 통한 구구단 및 별찍기 연습(Loop_Test.java)

```java
import java.util.*;

class Loop_Test{
	public static void main(String [] args){
		int i, j, k, number, sum, temp;
		Scanner S = new Scanner(System.in);
		
		number = S.nextInt();
/*		
		for(i = 1; i <= 9; i++){
			for(j = 1 ; j < number; j++)
					System.out.printf("| %d X %d = %2d |",j, i, j*i);
			System.out.println();
		}
		
*/
		sum = 1;
		temp = 1;
		
		//n! 구하기(overflow가 어디서 발생하는지 알아내기)
		for( i = 1 ; i <= number ; i++){
			sum *= i;
			if( temp != (sum/i)){
				System.out.printf("overflow occur! %d번째에 occur", i);
				break;
				}
			else temp = sum;
			
			
			
			
		}
		System.out.printf("%d! = %d", number, sum);
		//overflow는 (n - 1)! != (n!/n) 가 true면 overflow 발생
		
		System.out.println("------------------구	분--------------");
	/*	
		for(i = 0; (i < number) &&( i * number <= 9) ; i++){
			for(j = 1; j <= 9 ; j++){
					for(k = 1 ; k <= number &&	(i*number + k< 10); k++)
						System.out.printf("%d X %d = %2d |",i*number + k, j, (i*number + k)*j);
					
					
				System.out.println();
			}
			System.out.println("------------------------------");
		}			
		//number값이 1일때 1단 구구단만 출력함;;;
		*/
		
		
		for( k = 0; k < number; k++){
		for( i = k + 1 ; i < number; i++)System.out.print(" ");
		for( j = 0 ; j <= k ; j++)System.out.print("*");
		System.out.println();
		}
		System.out.println("\n");
		
		for( i = 0; i < number ; i++){
			for( k = 0; k < i ; k++)System.out.print(" ");
			for( j = 0; j < number - i ; j++)System.out.print("*");
			System.out.println();
		}
		
		System.out.println("\n");
		
		for(i = 0; i < number; i++){
			for(j = 0 ; j < number - i ; j++)System.out.print("*");
			System.out.println();
		}
		
	}
}
```

## 7일차

while, do-while반복문

객체 생성및 handling

***

### Hw4 과제 및 Hw5 과제 (Pattern.java)

숫자를 이용한 피라미드 쌓기와 별(*)찍기로 다이아몬드및 가로가 m이고 세로가 n인 직사각형 만들기

```java
import java.util.*;

class Pattern{
	public static void main(String [] args){
		int number, i, j, k;
		Scanner S = new Scanner(System.in);
		
		number = S.nextInt();
		
		for(i = 0; i <=number/2; i++){
			for(j = 0; j < i; j++)System.out.print(" ");
			for(k = 0; k <number - i*2; k++)System.out.print("*");
			System.out.println();
		}
		
		for(i =1; i<= number/2; i++){
			for(j = 0; j <number/2 - i; j++)System.out.print(" ");
			for(k = 0; k < 1 + 2*i ; k++)System.out.print("*");
			System.out.println();
		}
		System.out.println("------------구	분------------");
		
		for(i = 0; i < number; i++){
			for(j = 0; j < number - 1 -i; j++)System.out.print(" ");
			for(k = 0; k < number; k++)System.out.printf("%3d",number*i + k + 1);
			System.out.println();
		}
		System.out.println("------------구	분-----------");
		
		for(i = 0; i <= number/2 ; i++){
			for(k = 0; k < number/2 - i; k++)System.out.print(" ");
			for(j = 0; j < 1 + 2*i; j++)System.out.print("*");
			System.out.println();
		}
		for(i = 0; i <number/2 ; i++){
			for(j = 0; j < i+1; j++)System.out.print(" ");
			for(k = 0; k < (number - 2) - i*2; k++)System.out.print("*");
			System.out.println();
		}
		System.out.println("-------------구	분-----------");
		
		for(i = 0; i <= number/2 ; i++){
			for(j = 0; j < number/2 - i; j++)System.out.print(" ");
			for(k = 0; k < 1 + 2*i; k++)System.out.printf("%d", Math.abs(i - k));
			System.out.println();
		}
		for(i = 0; i < number/2 ; i++){
			for(j = 0; j < i + 1; j++)System.out.print(" ");
			for(k = 0; k < number - 2*(i+1); k++)System.out.printf("%d", Math.abs(number/2 - (i+k) - 1));
			System.out.println();
		}
		
	}
}
```

## 8일차

Class, Instance, Method, Field

## 9일차

overload, setter, getter, static method

## 10일차

Array, array를 이용한 객체 handling

## 11일차

Array, array 정렬하기(selection, bubble sort), array random shuffling, array search

2차원 array를 생성하고 사용하기

***

### Hw7 과제(Hw7.java)

```java
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
	
	StringManipulate(){}//default 생성자
	
	
	static String plusSentence(String str1, String str2){
		return str1+str2;
	}
	
}
```

## 12일차

### Hw12 (Circle.java)

첨부 파일 “원의 반지름과 넓이.java”에는 원의 반지름과 넓이가 한 라인마다 저장되어 있다.
반지름에 대한 원의 넓이가 제대로 구해졌는지를 판단하고, 그 결과를 프로그램 사용자의 학
번파일에 저장하는 프로그램을 작성하시오. 

```java
import java.util.*;
import java.io.*;

class Circle{
	public static void main(String [] args){
		String fileName;
		Scanner Keyboard = new Scanner(System.in);
		int order = 1;
		int radius;
		double surface;
		
		
		fileName = Keyboard.nextLine();
		
		File F = new File(fileName);
		if(!F.exists())System.out.println("doest not exists that " + fileName);
		
		try{
		Scanner ReadFile = new Scanner(F);
		
		
		while(ReadFile.hasNext()){
			radius = ReadFile.nextInt();
			surface = ReadFile.nextDouble();
			
			if(radius*radius*3.14 ==  surface){
				System.out.printf("%d 번째 원의 반지름은 %d, 넓이는 %.2f 입니다.\n", order, radius, surface);				
			}
			else{
				System.out.printf("%d 번째 원의 반지름은 %d이지만 넓이는 다릅니다. 실제 원 넓이 : %f\n", order, radius, 3.14*radius*radius);				
			}
			order++;
		}
		
		ReadFile.close();
		
		}catch(FileNotFoundException fnfe)
		{
			System.out.println("we can't filnd that file so, exit the program");
			return;
		}
		finally{
			ReadFile.close();
		}
		
		
		
	}
}
```


### Hw12 (TEst.java)

첨부 파일 “학생 정보.java”에는 학생 3 명의 이름, 학년, 학점이 차례로 저장되어 있다. 이
정보를 바탕으로 학생 객체 배열을 생성하고, 학생 정보를 출력하시오

```java
import java.util.*;
import java.io.*;
import java.lang.*;


class TEst{
	public static void main(String [] args){
		Scanner KeyBoard = new Scanner(System.in);
		System.out.print("what read file names? :");
		File ReadFile = new File(KeyBoard.nextLine());
		
		if(!ReadFile.exists()){
			System.out.println("does not exists such a file");
			return ;
		}
		
		Student [] std = new Student[3];
		int i =0;
		
		System.out.print("what write file names? : ");
		File WriteFile = new File(KeyBoard.nextLine()+".txt");
		if(WriteFile.exists()){
			System.out.println("already exists such file!");
			return;
		}
		
		
		try{
		Scanner ScanfrFile = new Scanner(ReadFile);
		PrintWriter pw = new PrintWriter(WriteFile);
		
		
		
			while(ScanfrFile.hasNext()){
			
				std[i] = new Student(ScanfrFile.next(), ScanfrFile.nextInt(), ScanfrFile.nextDouble());
			
				pw.println(std[i].toString());
				i++;
			
			}
			ScanfrFile.close();
			//pw.close();
		
		}catch(FilerException fe){
			System.out.println("IOE occur!");
		
		
		}catch(FileNotFoundException fnfe){
			System.out.println("ÀÐÀ» ÆÄÀÏ ¾øÀ½");
		
		}
				
		System.out.println("done writing file!");
		
		
		
		
		
	}
}

class Student{
	private String name;
	private int grade;
	private double score;
	
	Student(){}
	Student(String name, int grade, double score){
		this.name = name;
		this.grade = grade;
		this.score = score;		
	}
	
	public String toString(){
		return String.format(this.name + this.grade + this.score);
	}
	
	
	
```

Override, super, this, 접근 지시자, 상속(extends)

## 13일차

상속, interface, interface 구현

## 14일차

상속 관계 및 업캐스팅(upcasting), 다운캐스팅(downcasting), 객체형변환

### Hw(MovieTest.java)

영화 제목, 시리즈, 평점을 필드로 가지는 Movie 클래스가 있다. main()에서 영화 몇 개의
배열을 생성한 후, 이들을 평점에 따라 오름차순 정렬하시오: 단, Comparable 인터페이스를
구현하여 오름차순 정렬할 것. 

```java
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
```

## 15일차

파일 객체, 파일 입출력 하기(1)

## 16일차

파일 객체, 파일 입출력 하기(2)
