class Solution {
    int lcs(vector<vector<int>> &dp, string &t1, string &t2, int i, int j) {
        if (i >= t1.size() || j >= t2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if(t1[i] == t2[j]) {
            return dp[i][j] = 1 + lcs(dp, t1, t2, i+1, j+1);
        } else {
            return dp[i][j] = max(lcs(dp, t1, t2, i+1, j), lcs(dp, t1, t2, i, j+1));
        }
    }
public:
    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>> dp(t1.size(), vector<int>(t2.size(), -1));
        return lcs(dp, t1, t2, 0, 0);
    }
};