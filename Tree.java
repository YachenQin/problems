package prepare;

import java.io.IOException;


public class Tree {
	
	static boolean resolove(int[] A){
		
		int sum=0;
		for(int i:A){
			sum=sum+i;
		}
		
		int sumslice=sum/4;
		if(sumslice*4!=sum){
			return false;
		}
		
		int[] everyslice=new int[4];
		int count=0;
		int slicesum=0;
		for(int i=0;i<A.length;i++){
			slicesum=slicesum+A[i];
			if(slicesum==sumslice){
				everyslice[count]=i;
				count++;
				slicesum=0;
			}
		}
		
		if(everyslice[3]==A.length-1){
			return true;
		}
		
		return false;
		
	}
	
	public static void main(String[] args) throws IOException {
		int[] A={1,2,3,1,2,3,1,2,3,1,2,3};
		boolean a=Tree.resolove(A);
		System.out.println(a);
	}
	
}


