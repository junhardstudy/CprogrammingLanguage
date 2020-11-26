# JAVA

## 1일차

Notepad++, JDK설치 및 환경변수 등록등 개발환경 만들기.

기본적인 input(키보드)/output(모니터)


## 2일차

서식 지정자 종류 및 순서

Scanner클래스에 대한 여러가지 method(Scanner.nextInt(), Scanner.nextLine())

## 3일차

Hw 과제(Test.java)

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
Hw 과제(Hw_test.java)

수식을 문자열로 받아서 계산하기

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

입력받은 정수를 백, 십, 일 단위로 분리하기(Test.java)

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

반복문을 이용한 패턴 과제(Pattern.java)


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

(Hw7.java)

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
	
	static void sameDistinguish(String str1, String str2){
	}
	
	
	
	
	
	
}
```

## 12일차

Override, super, this, 접근 지시자, 상속(extends)

## 13일차

상속, interface, interface 구현

## 14일차

상속 관계 및 업캐스팅(upcasting), 다운캐스팅(downcasting), 객체형변환

## 15일차

파일 객체, 파일 입출력 하기(1)

## 16일차

파일 객체, 파일 입출력 하기(2)
