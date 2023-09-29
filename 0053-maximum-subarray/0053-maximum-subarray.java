class Solution {
    public int maxSubArray(int[] nums) {
        int ans = -1000000, curr = 0;
        for(int i : nums) {
            curr += i;
            ans = Math.max(curr, ans);
            curr = Math.max(curr, 0);
        }
        return ans;
    }
}