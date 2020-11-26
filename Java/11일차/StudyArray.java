import java.util.Scanner;


class StudyArray{
	public static void main(String [] args){
		Scanner S = new Scanner(System.in);
		int number, move_number;
		String str;
		number = S.nextInt();
		double [] arry = new double[number];//c�� �ٸ��� java������ ����
		
		
		initialize(arry);
		displayArray(arry);
		System.out.println("�� �迭�� ���ҵ��� ���� " + summAllElements(arry));
		System.out.println("�� �߿��� ���� ū ���Ҵ� " + findLargestElement(arry));
		System.out.println("�� �߿��� ���� ū ���Ҹ� ������ �ִ� ���� ���� �迭�� �ε����� "+findingLargestofSmallestIndex(arry));
		System.out.println("�������� shuffling �� �� ");
		shufflingRandom(arry);
		displayArray(arry);
		
		System.out.print("�迭�� ��� �������� ?");
		S.nextLine();
		str = S.nextLine();
		System.out.print("�� ĭ ?");
		move_number = S.nextInt();
		
		move_number %= arry.length;//�ڱ� �迭 �����̻��� shift�� �ᱹ ���ڸ��� ���� ������ ������ ��ŭ�� shift ���ָ� ��
		
		System.out.print("before : ");
		displayArray(arry);
		shifting(arry, str, move_number);
		System.out.print("after  : ");
		displayArray(arry);
		
		selectSort(arry);
		System.out.println("after sort");
		displayArray(arry);
		
		System.out.println("�ٽ� �������� ����");
		shufflingRandom(arry);
		displayArray(arry);
		
		System.out.println("bubble sort �̿�");
		bubbleSort(arry);
		displayArray(arry);
		
		
		
		
		
		
	}
		static void initialize(double [] arry){
			for(int i = 0; i < arry.length; i++)arry[i] = Math.random()*10;
		}
		
		static void displayArray(double [] arry){
			System.out.println("�迭 ���Ҹ� ���");
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
			int rnd = (int)(Math.random() * 51);//���� Ƚ��
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
		
		//��� �������� ��ĭ �̵� ��Ű�� method
		static void shifting(double [] array, String direction, int number){
			double tmp_1, tmp_2, temp;
			
			
			switch(direction){
				
				
				//������ ĭ�� ��ŭ �̵��� ĭ����ŭ�� �ӽù迭�� ���� ������ ������ �̵��ϴ� ����� ����.
				case "right" : case "������" :
					
					//�迭 ���Ҹ� �������� �ؼ�
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
					
					//���� �Ѱ������� shift ��Ű��(��� ������ ����)
					//�����̴°ſ� ���� ���缭
					for(int i = 0; i < number; i++){
						temp = array[array.length -1];
						for(int j = array.length - 1; j > 0; j--){
							array[j] = array[j-1];
						}
						array[0] = temp;
					}
				
				
				
				break;
				case "left" : case "����" :
				
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
					//���� �Ѱ��� �̿�(���� ���� ����)
					
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
					if(array[j] < temp){//�������� ����	
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
