import java.util.List;
import java.util.ArrayList;


class Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> subNums = new ArrayList<List<Integer>>();

        for (int i = 0; i < Math.pow(2, nums.length); ++i) {
            List<Integer> subset = new ArrayList<>();
            int idx = i;
            int j = 0;
            
            while (idx > 0) {
                if (idx % 2 == 1) subset.add(nums[j]);
                ++j;
                idx /= 2;
            }

            subNums.add(subset);
        }

        return subNums;
    }
}
