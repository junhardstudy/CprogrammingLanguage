import java.util.Scanner;


class StudyArray{
	public static void main(String [] args){
		Scanner S = new Scanner(System.in);
		int number, move_number;
		String str;
		number = S.nextInt();
		double [] arry = new double[number];//c와 다르게 java에서는 가능
		
		
		initialize(arry);
		displayArray(arry);
		System.out.println("이 배열의 원소들의 합은 " + summAllElements(arry));
		System.out.println("이 중에서 가장 큰 원소는 " + findLargestElement(arry));
		System.out.println("이 중에서 가장 큰 원소를 가지고 있는 가장 작은 배열의 인덱스는 "+findingLargestofSmallestIndex(arry));
		System.out.println("무작위로 shuffling 한 후 ");
		shufflingRandom(arry);
		displayArray(arry);
		
		System.out.print("배열을 어느 방향으로 ?");
		S.nextLine();
		str = S.nextLine();
		System.out.print("몇 칸 ?");
		move_number = S.nextInt();
		
		move_number %= arry.length;//자기 배열 길이이상의 shift는 결국 제자리로 오기 때문에 나머지 만큼만 shift 해주면 됨
		
		System.out.print("before : ");
		displayArray(arry);
		shifting(arry, str, move_number);
		System.out.print("after  : ");
		displayArray(arry);
		
		selectSort(arry);
		System.out.println("after sort");
		displayArray(arry);
		
		System.out.println("다시 무작위로 섞음");
		shufflingRandom(arry);
		displayArray(arry);
		
		System.out.println("bubble sort 이용");
		bubbleSort(arry);
		displayArray(arry);
		
		
		
		
		
		
	}
		static void initialize(double [] arry){
			for(int i = 0; i < arry.length; i++)arry[i] = Math.random()*10;
		}
		
		static void displayArray(double [] arry){
			System.out.println("배열 원소를 출력");
			for(int i= 0 ; i < arry.length ; i++)System.out.printf("|%.1f",arry[i]);
			System.out.println();
		}
		
		static double summAllElements(double [] arry){
			double sum = 0;
			for(int i=0; i < arry.length; i++)sum+=arry[i];
			return sum;
		}
		
		static double findLargestElement(double [] arry){
			double tmp;
			tmp = arry[0];
			for(int i = 0 ; i < arry.length; i++){
				if(arry[i] > tmp)tmp = arry[i];
			}
			return tmp;
		}
		
		static int findingLargestofSmallestIndex(double [] arry){
			int tmp_index = 0; 
			double tmp = arry[0];
			
			for(int i = 0 ; i < arry.length ; i++){
				
				if(tmp < arry[i]){
					tmp = arry[i];
					tmp_index = i;
				}
			}
			return tmp_index;
			
		}
		
		static void shufflingRandom(double [] arry){
			double tmp;
			int rnd = (int)(Math.random() * 51);//섞는 횟수
			int before, after;
			for(int i = 0; i < rnd; i++){
				before = (int)(Math.random()*arry.length);
				after = (int)(Math.random()*arry.length);
				tmp = arry[before];
				arry[before] = arry[after];
				arry[after] = tmp;
			}
			
			
			/*
				
			
			
			
			*/
		}
		
		//어느 방향으로 몇칸 이동 시키는 method
		static void shifting(double [] array, String direction, int number){
			double tmp_1, tmp_2, temp;
			
			
			switch(direction){
				
				
				//지정된 칸수 만큼 이동은 칸수만큼의 임시배열을 만들어서 저장한 다음에 이동하는 방법도 있음.
				case "right" : case "오른쪽" :
					
					//배열 원소를 중점으로 해서
					/*
					for(int i =0; i < number; i++){
						tmp_1 = array[0];
						for(int j =1; j < array.length ; j++){
							tmp_2 = array[j];
							array[j] = tmp_1;
							tmp_1 = tmp_2;
						}
						array[0] = tmp_1;
					}
					*/
					
					//변수 한개만으로 shift 시키기(제어문 변수는 제외)
					//움직이는거에 중점 맞춰서
					for(int i = 0; i < number; i++){
						temp = array[array.length -1];
						for(int j = array.length - 1; j > 0; j--){
							array[j] = array[j-1];
						}
						array[0] = temp;
					}
				
				
				
				break;
				case "left" : case "왼쪽" :
				
					/*
					for(int i = 0; i < number; i++){
						tmp_1 = array[array.length - 1];
						for(int j = array.length - 2; j >= 0; j--){
							tmp_2 = array[j];
							array[j] = tmp_1;
							tmp_1 = tmp_2;
						}
						array[array.length - 1] = tmp_1;
						
					}
					*/
					//변수 한개만 이용(제어 변수 제외)
					
					for(int i = 0 ; i < number; i++){
						temp = array[0];
						for(int j = 0; j < array.length - 1 ; j++){
							array[j] = array[j+1];
						}
						array[array.length - 1] = temp;
					}
					
				break;
				default : break;
			}
		}
		
		static void selectSort(double [] array){
			double temp;
			int temp_pivot;
			for(int i = 0; i <array.length - 1; i++){
				temp = array[i];
				temp_pivot = i;
				for(int j = i + 1; j < array.length ; j++){
					if(array[j] < temp){//오름차순 정렬	
						temp = array[j];
						temp_pivot = j;
					}
				}
				array[temp_pivot] = array[i];
				array[i] = temp;
				
			}
		}
		
		static void bubbleSort(double [] array){
			double tmp;
			for(int i = 0; i < array.length -1 ; i++){
				for(int j = i; j< array.length - 1; j++){
					if(array[j] > array[j+1]){
						tmp = array[j];
						array[j] = array[j+1];
						array[j+1] = tmp;
						
					}
				}
			}
		}
		
		
	
	
}
