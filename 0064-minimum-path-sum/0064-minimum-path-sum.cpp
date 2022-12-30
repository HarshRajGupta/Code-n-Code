const vector<vector<int>> cs(200, vector<int>(200, -1));
class Solution {
    vector<vector<int>> dp = cs;
public:
    int minPathSum(vector<vector<int>> &grid, int i = 0, int j = 0) {
        if (dp[i][j] != -1)
            return dp[i][j];
        
        if (i == grid.size()-1) {
            if (j == grid[0].size()-1)
                return dp[i][j] = grid[i][j];
            return dp[i][j] = grid[i][j] + minPathSum(grid, i, j+1);
        }
        if (j == grid[0].size()-1) {
            return dp[i][j] = grid[i][j] + minPathSum(grid, i+1, j);
        }
        return dp[i][j] = grid[i][j] + min(minPathSum(grid, i+1, j), minPathSum(grid, i, j+1));
    }
};