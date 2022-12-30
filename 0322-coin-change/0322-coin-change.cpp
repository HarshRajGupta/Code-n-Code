class Solution {
    int ans(vector<int>& coins, vector<int>& dp, int am) {
        if (am == 0)
            return 0;
        
        if (dp[am] != INT_MIN)
            return dp[am];
        
        int res = -1;
        
        for(int i : coins) {
            if (i > am) 
                return dp[am] = res;
            int t = ans(coins, dp, am - i);
            if (t != -1) {
                if (res == -1)
                    res = t + 1;
                else
                    res = min(res, t+1);
            }
        }
        return dp[am] = res;
    }
public:
    int coinChange(vector<int> coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(1e4+7, INT_MIN);
        return ans(coins, dp, amount);
    }
};