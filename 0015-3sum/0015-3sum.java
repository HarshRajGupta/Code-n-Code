class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int i = 0; i < nums.length; ++i) {
            int l = i + 1, r = nums.length - 1;
            while(l < r) {
                int sum = (nums[l] + nums[r])*-1;
                if (sum < nums[i]) {
                    --r;
                } else if (sum > nums[i]) {
                    ++l;
                } else {
                    ArrayList<Integer> numbers = new ArrayList<>();
                    numbers.add(nums[i]);
                    numbers.add(nums[l]);
                    numbers.add(nums[r]);
                    ans.add(numbers);
                    while(l < r && nums[l+1] == nums[l]) ++l;
                    while(l < r && nums[r-1] == nums[r]) --r;
                    ++l;
                    --r;
                }
            }
            while(i < nums.length - 1 && nums[i+1] == nums[i]) ++i;
        }
        return ans;
    }
}