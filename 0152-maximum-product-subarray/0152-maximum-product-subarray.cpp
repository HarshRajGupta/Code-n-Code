class Solution {
    void maxSubArr(vector<vector<int>> &dp, vector<int> &nums, int pos) {
        if (pos == nums.size() - 1) {
            dp[pos][1] = nums[pos], dp[pos][0] = nums[pos];
            return;
        }
        if (dp[pos][0] == INT_MIN) {
            int pro = nums[pos], ans;
            maxSubArr(dp, nums, pos+1);
            if (pro > 0)
                ans = max(pro, pro*dp[pos+1][0]);
            else
                ans = max(pro, pro*dp[pos+1][1]);
            dp[pos][0] = ans;
        }
        if (dp[pos][1] == INT_MAX) {
            int pro = nums[pos], ans;
            maxSubArr(dp, nums, pos+1);
            if (pro < 0)
                ans = min(pro, pro*dp[pos+1][0]);
            else
                ans = min(pro, pro*dp[pos+1][1]);
            dp[pos][1] = ans;
        }
    }
    
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), {INT_MIN, INT_MAX});
        maxSubArr(dp, nums, 0);
        int ans = dp[0][0];
        for(int i = 0; i < nums.size(); ++i) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};