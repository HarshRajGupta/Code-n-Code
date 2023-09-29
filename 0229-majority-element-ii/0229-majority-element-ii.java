class Solution {
    public List<Integer> majorityElement(int[] nums) {
        if (nums.length < 3) {
            ArrayList<Integer> ans = new ArrayList<>();
            ans.add(nums[0]);
            if (nums.length == 2 && nums[0] != nums[1]) ans.add(nums[1]);

            return ans;
        }
        // int first = 0, count1 = 0, second = 0, count2 = 0;
        // for(int i = 0; i < nums.length; ++i) {
        //     if (nums[i] == first) {
        //         ++count1;
        //     } else if (nums[i] == second) {
        //         ++count2;
        //     } else {
        //         if (count1 > count2) {
        //             if (count1 <= 1) {
        //                 first = nums[i];
        //                 count1 = 1;
        //             } else --count1;
        //         } else {
        //             if (count2 <= 1) {
        //                 second = nums[i];
        //                 count2 = 1; 
        //             } else --count2;
        //         }
        //     }
        // }
        // count1 = count2 = 0;
        // for(int i = 0; i < nums.length; ++i) {
        //     if (nums[i] == first) ++count1;
        //     if (nums[i] == second) ++count2;
        // }
        // ArrayList<Integer> ans = new ArrayList<>();
        // if (count1 > nums.length/3) ans.add(first);
        // if (first != second && count2 > nums.length/3) ans.add(second);
        // return ans;


int first = 0, count1 = 0, second = 0, count2 = 0;
        for(int i = 0; i < nums.length; ++i) {
            if (nums[i] == first) {
                ++count1;
            } else if (nums[i] == second) {
                ++count2;
            } else if (count1 == 0) {
                first = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                second = nums[i];
                count2 = 1;
            } else {
                --count1;
                --count2;
            }
        }
        count1 = count2 = 0;
        for(int i = 0; i < nums.length; ++i) {
            if (nums[i] == first) ++count1;
            if (nums[i] == second) ++count2;
        }
        ArrayList<Integer> ans = new ArrayList<>();
        if (count1 > nums.length/3) ans.add(first);
        if (first != second && count2 > nums.length/3) ans.add(second);
        return ans;
    }
}