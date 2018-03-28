package TreeNode;

public class Treenode {
	
	private int[][] listData = new int[5][9];       
    private int maxLevel = 0;
    
    public int resolve(int[] list){
        configLocalData(list);
        return getWeigth(1, 1);
    }
    
    private void configLocalData(int[] list){
        int maxLevel = getMaxLevel(list);
        for(int index = 1;index < maxLevel+1;index++){
            for(int num:list) {
                int first = getFirst(num);
                if (index == first){
                    listData[index][getMid(num)] = getLast(num);
                }
            }
        }
    }
    
	public int getMaxLevel(int[] list){
        int level=0;
        for(int num:list){
            int first = getFirst(num);
            if(level < first){
                level = first;
            }
        }
        this.maxLevel = level;
        return level;
    }
	
	public int getFirst(int data){
        return data/100;
    }
    public int getMid(int data){
        return (data/10)%10;
    }
    public int getLast(int data){
        return data%10;
    }
    
    public int getWeigth(int level, int index){
        if(level >= this.maxLevel){
            return listData[level][index];
        }
        return listData[level][index] * numOfLeaf(level, index) +getWeigth(level+1, 2*index-1)+getWeigth(level+1, 2*index);
    }
    
    public int numOfLeaf(int level, int index){
        if(level >= this.maxLevel){
            return (listData[level][index] != 0)?1:0;
        }
        return numOfLeaf(level+1, 2*index -1)+ numOfLeaf(level+1, 2*index);
    }
    
    
	
}
