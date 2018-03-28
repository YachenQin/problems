package move;

import java.io.IOException;



public class move {
	public static int jump(int[] nums) {
        if (nums == null || nums.length == 0 || nums.length == 1) {
            return 0;
        }
        int farthest = 0, step = 1, currEnd = 0, endIndex = nums.length - 1;
        for (int i = 0; i < endIndex; i++) {    // warning: not nums.length
            farthest = Math.max(farthest, nums[i] + i);
            if (i == currEnd) {     // reaches edge means you have to add 1 to go farther
                step++;
                currEnd = farthest;
            }
        }
        return step;
    }
	
	public static void main(String[] args) throws IOException {
		int[] A={3,4,2,1,3,1};
		int a=move.jump(A);
		System.out.println(a);
	}
}
		
		
		
