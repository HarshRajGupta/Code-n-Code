class Solution {
    public int maxProduct(int[] nums) {
        int ans = nums[0], pos = 1, neg = 1;
        for(int i: nums) {
            if (i > 0) {
                pos *= i;
                neg *= i;
                ans = Math.max(ans, Math.max(pos, neg));
            } else if (i < 0) {
                pos *= i;
                neg *= i;
                ans = Math.max(ans, Math.max(pos, neg));
                int t = neg;
                neg = Math.min(1, Math.min(pos, neg));
                pos = Math.max(1, Math.max(pos, t));
            } else {
                pos = neg = 1;
                ans = Math.max(ans, 0);
            }
        }
        return ans;
    }
}