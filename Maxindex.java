package maxindex;

import java.io.IOException;


public class Maxindex {
	public static int themaxindex(int[] array){
		int length=0;
		length=array.length;
		if(length==1){
			return 1;
		}
		
		int[] f = new int[length];
		for(int i=0;i<length;i++){
			f[i]=1;
			for(int j=0;j<i;j++){
				if(array[j]<array[i] && f[j]>f[i]-1){
					f[i]=f[j]+1;
				}
			}
		}
		
		int maxlength=0;
		for(int i=0;i<length;i++){
			if(f[i]>maxlength){
				maxlength=f[i];
			}
		}
		
		
		return maxlength;
		
	}
	
	public static void main(String[] args) throws IOException {
		int[] A={1,2,3,1,2,3,1,2,3,1,2,3};
		int a=Maxindex.themaxindex(A);
		System.out.println(a);
	}
}
