class Solution {
    void lis(vector<vector<int>> &dp, vector<int> &nums, int v, int p) {
        if (dp[p][v] != -1)
            return;
        
        if (p == nums.size()) {
            dp[p][v] = 0;
            return;
        }

        if (v == 0) {
            lis(dp, nums, p+1, p+1);
            lis(dp, nums, v, p+1);
            dp[p][v] = max(dp[p+1][v], dp[p+1][p+1] + 1);
            return;
        }
        
        if (nums[v-1] < nums[p]) {
            lis(dp, nums, p+1, p+1);
            lis(dp, nums, v, p+1);
            dp[p][v] = max(dp[p+1][v], dp[p+1][p+1] + 1);
        } else {
            lis(dp, nums, v, p+1);
            dp[p][v] = dp[p+1][v];
        }
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, -1));
        lis(dp, nums, 0, 0);
        return dp[0][0];
    }
};