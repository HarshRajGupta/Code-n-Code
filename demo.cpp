#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    void bfs(vector<vector<int>>& board, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 2;
        while (!q.empty()) {
            auto &[x, y] = q.front();
            if (x > 0 && board[x - 1][y] == 1) {
                board[x - 1][y] = 1;
                q.push({x - 1, y});
            }
            if (y > 0 && board[x][y - 1] == 1) {
                board[x][y - 1] = 2;
                q.push({x, y - 1});
            }
            if (x < board.size() - 1 && board[x + 1][y] == 1) {
                board[x + 1][y] = 2;
                q.push({x + 1, y});
            }
            if (y < board[0].size() - 1 && board[x][y + 1] == 1) {
                board[x][y + 1] = 2;
                q.push({x, y + 1});
            }
            q.pop();
        }
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[0][j] == 1) {
                bfs(board, 0, j);
            }
            if (board[board.size() - 1][j] == 1) {
                bfs(board, board.size() - 1, j);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 1) {
                bfs(board, i, 0);
            }
            if (board[i][board[0].size() - 1] == 1) {
                bfs(board, i, board[0].size() - 1);
            }
        }
        debug(board)
        int cnt = 0;
        for (auto &i : board) {
            for (auto &j : i) {
                if (j == 1) ++cnt;
            }
        }
        return cnt;
    }
    void test() {
        vector<vector<int>> a = {{0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1}, {1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0}, {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0}, {1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1}, {0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1}, {1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0}, {1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0}, {1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1}};
        cout << numEnclaves(a);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif