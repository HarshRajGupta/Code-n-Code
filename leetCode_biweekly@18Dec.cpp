#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int32_t i = (int32_t)n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> degree(n), oddDeg;
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        for (auto i : edges) {
            if (!graph[i[0] - 1][i[1] - 1] && !graph[i[1] - 1][i[0] - 1]) {
                degree[i[0] - 1]++;
                ++degree[i[1] - 1];
                graph[i[0] - 1][i[1] - 1] = true;
                graph[i[1] - 1][i[0] - 1] = true;
            }
        }
        for (auto i = 0; i < n; ++i) {
            if (degree[i] % 2)
                oddDeg.push_back(i);
        }
        debug(graph, degree, oddDeg)
        if (oddDeg.size() == 0 || oddDeg.size() == 2 || oddDeg.size() == 4) {
            if (oddDeg.size() == 0) return true;
            // cout << graph[oddDeg[0]][oddDeg[1]] << ln;
            if (oddDeg.size() == 2) {
                // cout << graph[oddDeg[0]][oddDeg[1]] << ln;
                if (!graph[oddDeg[0]][oddDeg[1]]) return true;
                for (int i = 0; i < n; ++i) {
                    if (i != oddDeg[0] && i != oddDeg[1]) {
                        if (!graph[oddDeg[0]][i] && !graph[oddDeg[1]][i]) return true;
                    }
                }
                return false;
            }
            if (!graph[oddDeg[0]][oddDeg[1]] && !graph[oddDeg[2]][oddDeg[3]])
                return true;
            if (!graph[oddDeg[0]][oddDeg[2]] && !graph[oddDeg[1]][oddDeg[3]])
                return true;
            if (!graph[oddDeg[0]][oddDeg[3]] && !graph[oddDeg[1]][oddDeg[2]])
                return true;
        }
        return false;
    }
};

void solve(void) {
    /* Code */
    Solution s;
    vector<vector<int>> edges = {{2, 19}, {16, 17}, {8, 14}, {2, 16}, {12, 20}, {12, 14}, {16, 18}, {15, 16}, {10, 21}, {3, 5}, {13, 18}, {17, 20}, {14, 17}, {9, 12}, {5, 15}, {5, 6}, {3, 7}, {2, 21}, {10, 13}, {8, 16}, {7, 18}, {4, 6}, {9, 1}, {13, 21}, {18, 20}, {7, 14}, {4, 19}, {5, 8}, {3, 11}, {11, 1}, {7, 12}, {4, 7}, {3, 16}, {13, 17}, {17, 19}, {9, 13}, {7, 19}, {10, 16}, {4, 13}, {4, 5}, {2, 15}, {12, 19}, {11, 16}, {2, 9}, {11, 17}, {17, 1}, {16, 21}, {4, 10}, {10, 14}, {14, 16}, {4, 1}, {13, 20}, {5, 20}, {4, 14}, {4, 21}, {10, 20}, {2, 14}, {8, 15}, {4, 8}, {6, 19}, {15, 1}, {19, 1}, {8, 19}, {15, 21}, {3, 12}, {11, 18}, {9, 17}, {18, 19}, {7, 21}, {3, 21}, {16, 19}, {11, 15}, {5, 1}, {8, 17}, {3, 15}, {8, 1}, {10, 19}, {3, 8}, {6, 16}, {2, 8}, {5, 18}, {11, 13}, {11, 20}, {14, 21}, {6, 20}, {4, 20}, {12, 13}, {5, 12}, {10, 11}, {9, 15}, {3, 19}, {9, 20}, {14, 18}, {21, 1}, {13, 19}, {8, 21}, {2, 13}, {3, 10}, {9, 18}, {19, 21}, {6, 7}, {3, 18}, {2, 18}, {6, 14}, {3, 17}, {5, 21}, {14, 20}, {8, 9}, {16, 1}, {3, 4}, {13, 1}, {5, 9}, {4, 15}, {17, 21}, {20, 21}, {2, 17}, {13, 14}, {11, 14}, {9, 16}, {10, 18}, {6, 15}, {6, 12}, {3, 13}, {5, 11}, {6, 1}, {12, 17}, {8, 10}, {5, 10}, {8, 18}, {4, 12}, {10, 1}, {6, 13}, {4, 18}, {7, 20}, {7, 16}, {2, 6}, {12, 21}, {4, 17}, {15, 18}, {13, 16}, {15, 20}, {7, 10}, {6, 10}, {2, 20}, {7, 15}, {18, 1}, {12, 1}, {3, 20}, {7, 1}, {14, 15}, {4, 9}, {11, 19}, {7, 9}, {5, 17}, {18, 21}, {6, 21}, {8, 11}, {6, 17}, {3, 14}, {7, 11}, {5, 7}, {7, 13}, {6, 8}, {6, 9}, {10, 12}, {5, 16}, {2, 4}, {17, 18}, {9, 11}, {12, 16}, {3, 6}, {12, 18}, {3, 9}, {11, 12}, {14, 19}, {10, 15}, {5, 13}, {8, 13}, {15, 17}, {2, 10}, {11, 21}, {20, 1}, {6, 18}, {2, 12}, {19, 20}, {6, 11}, {8, 12}, {2, 3}, {12, 15}, {2, 11}, {9, 10}, {7, 17}, {9, 19}, {13, 15}, {7, 8}, {4, 11}, {2, 5}, {5, 19}, {16, 20}, {15, 19}, {9, 14}, {14, 1}, {10, 17}, {9, 21}, {2, 7}, {8, 20}, {5, 14}, {4, 16}};
    cout << s.isPossible(21, edges);
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}