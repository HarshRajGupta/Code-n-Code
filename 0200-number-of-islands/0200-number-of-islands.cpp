class Solution {
    void dfs(vector<vector<char>> &graph, int x, int y, vector<vector<bool>> &visited) {
        if ( x < 0 || y < 0|| x >= graph.size() || y >= graph[0].size() || visited[x][y] || graph[x][y] == '0') return;
        visited[x][y] = true;
        dfs(graph, x+1, y, visited);
        dfs(graph, x, y+ 1, visited);
        dfs(graph, x-1, y, visited);
        dfs(graph, x, y-1, visited);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return ans;
    }
};