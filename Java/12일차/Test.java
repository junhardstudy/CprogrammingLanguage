import java.util.*;

class Test{
	public static void main(String [] args){
		String tmp;
		int tmp_pivot;
		for(int i = 0; i < args.length - 1 ; i++){
			tmp = args[i];
			tmp_pivot = i;
			for(int j =  i + 1; j < args.length ; j++){
				if(tmp.length() > args[j].length()){
					tmp = args[j];
					tmp_pivot = j;
				}
				
			}
			args[tmp_pivot] = args[i];
			args[i] = tmp;
		}
		
		for(int j =  0; j < args.length ; j++)System.out.println(args[j]);
	}
}