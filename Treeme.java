package TreeNode;

public class Treeme {
	public int[][] datatree=new int[5][9];
	public int maxlevel=0;
	
	
	public int getlevel(int data){
		return data/100;
	}
	public int getpos(int data){
		return (data/10)%10;
	}
	public int getnumber(int data){
		return data%100;
	}
	
	
	
	
	public void transformdata(int[] list){
		for(int i=1;i<this.maxlevel+1;i++){
			for(int num:list){
				int level=getlevel(num);
				if(i==level){
					datatree[level][getpos(num)]=getnumber(num);
				}
			}
		}
	}
	
	public int getmaxlevel(int[] list){
		int level=0;
		for(int num:list){
			if(getlevel(num)>level){
				level=getlevel(num);
			}
		}
		
		this.maxlevel=level;
		return level;
		
	}
	
	
	public int numofleaf(int level,int position){
		
		if(level >=this.maxlevel){
			 return (datatree[level][position] != 0)?1:0;
		}
		return numofleaf(level+1, 2*position -1)+ numofleaf(level+1, 2*position);
	}
	
	public int getweight(int level, int position){
		
		if(level==this.maxlevel){
			return datatree[level][position];
		}
		return datatree[level][position]*numofleaf(level,position)+getweight(level+1,position*2-1)+getweight(level+1,position*2);
	}
	
}
