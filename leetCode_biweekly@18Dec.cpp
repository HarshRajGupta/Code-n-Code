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
            degree[i[0] - 1]++;
            ++degree[i[1] - 1];
            graph[i[0] - 1][i[1] - 1] = true;
        }
        for (auto i = 0; i < n; ++i) {
            if (degree[i] % 2)
                oddDeg.push_back(i);
        }
        if (oddDeg.size() != 0 || oddDeg.size() != 2 || oddDeg.size() != 4) return false;
        if (oddDeg.size() == 0) return true;
        if (oddDeg.size() == 2) {
            if (!graph[oddDeg[0]][oddDeg[1]]) return true;
            return false;
        }
        if (!graph[oddDeg[0]][oddDeg[1]] && !graph[oddDeg[2]][oddDeg[3]])
            return true;
        if (!graph[oddDeg[0]][oddDeg[2]] && !graph[oddDeg[1]][oddDeg[3]])
            return true;
        if (!graph[oddDeg[0]][oddDeg[3]] && !graph[oddDeg[1]][oddDeg[2]])
            return true;
        return false;
    }
};

void solve(void) {
    /* Code */
    Solution s;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 4}, {2, 5}};
    cout << s.isPossible(5, edges);
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