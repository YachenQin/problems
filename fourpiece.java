package prepare;

import java.io.IOException;


public class fourpiece {
	public static boolean divided(int[] A){
		int length=A.length;
		int sum1=0,sum2=0,sum3=0,sum4=0;
		int m1=0,m2=1,m3=2;
		
		if(length<7){
			return false;
		}
		
		
		else{
			for(int i=m3+1;i<length;i++){
				sum4=sum4+A[i];
			}
			
			
			while(true){
				if(sum3<sum4){
					sum3=sum3+A[m3];
					sum4=sum4-A[m3+1];
					m3++;
					if(m3==length-1){
						return false;
					}
					else{
						continue;
					}
				}
				if(sum2<sum3){
					sum2=sum2+A[m2];
					sum3=sum3-A[m2+1];
					m2++;
					if(m2==m3){
						break;
					}
					else{
						continue;
					}
				}
				if(sum1<sum2){
					sum1=sum1+A[m1];
					sum2=sum2-A[m1+1];
					m1++;
					if(m1==m2){
						break;
					}
					else{
						continue;
					}
				}
				if(sum1==sum2 && sum2==sum3 && sum3==sum4){
					return true;
				}
			}
			return false;
		}
		
	}
	
	public static void main(String[] args) throws IOException {
		int[] A={2,5,1,1,1,1,4,1,7,3,7,7};
		boolean a=fourpiece.divided(A);
		System.out.println(a);
	}
}
