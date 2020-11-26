import java.util.*;
import java.lang.*;


class DimenArray{
	public static void main(String [] args)throws Exception{
		int [][] array = new int [3][2];
		
		
		initialize(array);
		displayUseforeach(array);
		//display(array);
		for(int i = 0; i<array[0].length ; i++)System.out.printf("%d 번째 열의 합은 %d\n", i+1, summingAllElements(array)[i]);
		
	
		
		shuffling(array);
		display(array);
		System.out.println();
		
		System.out.printf("%d행 %d열이 가장 큰 값의 원소를 가짐", findIndex(array)[0] + 1, findIndex(array)[1] + 1);
	
		
		
		
	}
	
	static void initialize(int [][] array){
		Random Rnd = new Random();
		for(int i =0; i < array.length; i++){
			for(int j = 0; j < array[0].length; j++)array[i][j] = Rnd.nextInt(11);
		}
	}
	
	static void display(int [][] array){
		for(int i =0; i < array.length; i++){
			for(int j = 0; j < array[0].length; j++)System.out.printf("%3d", array[i][j]);
			System.out.println();
		}
		
	}
	static void displayUseforeach(int [][] array){
		for(int [] row:array){
			for(int column:row){
				System.out.printf("%3d", column);
			}
			System.out.println();
		}
	}
	
	static int[] summingAllElements(int [][] array){
		int [] sum = new int[array[0].length];
		for(int i = 0; i < array[0].length; i++){
			for(int j = 0; j < array.length; j++){
				sum[i] += array[j][i]; 
			}
		}
		return sum;
	}
	
	
	static void shuffling(int [][] array){
		Random Rnd = new Random();
		int number, rowbefore, columnbefore, temp, rowafter, columnafter;
		number = Rnd.nextInt(100);
		for(int i = 0; i < number; i++){
			rowbefore = Rnd.nextInt(array.length);
			columnbefore = Rnd.nextInt(array[0].length);
			rowafter = Rnd.nextInt(array.length);
			columnafter = Rnd.nextInt(array[0].length);
			
			temp = array[rowbefore][columnbefore];
			array[rowbefore][columnbefore] = array[rowafter][columnafter];
			array[rowafter][columnafter] = temp;
			
			
		}
		
	}
	
	static int[] findIndex(int [][] array){
		int [] index = {0, 0};
		int temp = array[0][0];
		for(int i = 0 ; i < array[0].length; i++)
			for(int j =0; j < array.length; j++){
				if(array[j][i] > temp){
					temp = array[j][i];
					index[0] = j;//행
					index[1] = i;//열
				}
			}
			return index;
	}
	
	
	
	
	
	
}