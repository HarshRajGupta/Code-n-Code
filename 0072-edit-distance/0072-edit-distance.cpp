class Solution {
    int ans(vector<vector<int>> &dp, string w1, string w2, int i , int j) {
        if (i == w1.size()) {
            return w2.size() - j;
        }
        if (j == w2.size()) {
            return w1.size() - i;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (w1[i] == w2[j]) {
            return dp[i][j] = ans(dp, w1, w2, i+1, j+1);
        }
        return dp[i][j] = 1 + min(ans(dp, w1, w2, i+1, j+1),
                                 min(ans(dp, w1, w2, i+1, j), ans(dp, w1, w2, i, j+1)));
    }
    
public:
    int minDistance(string w1, string w2) {
        vector<vector<int>> dp(w1.size(), vector<int>(w2.size(), -1));
        return ans(dp, w1, w2, 0, 0);
    }
};