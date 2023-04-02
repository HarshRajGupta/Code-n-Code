#include <bits/stdc++.h>
using namespace std;

#ifndef OFFLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse","sse2","sse3","ssse3","sse4","popcnt","abm","mmx","avx","avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
        if (k == 1) {
            vector<int> arr(n, -1);
            arr[p] = 0;
            return arr;
        }
        vector<int> arr(n, -2);
        arr[p] = 0;
        for (auto& i : banned) arr[i] = -1;
        queue<vector<int>> q;
        q.push({p, 1});
        while (!q.empty()) {
            int pos = q.front()[0], cnt = q.front()[1];
            q.pop();
            for (int j = pos + 1; j <= pos + k - 1 && j < arr.size(); ++j) {
                if (arr[j] == -2 && (((j - pos + 1) & 1) == (k & 1)) && (j - pos + 1 + 2 * min(pos, n - j - 1)) >= k) {
                    debug(pos, j)
                    arr[j] = cnt;
                    q.push({j, cnt + 1});
                }
            }
            for (int j = pos - 1; j >= pos - k + 1 && j >= 0; --j) {
                if (arr[j] == -2 && (((pos - j + 1) & 1) == (k & 1)) && (pos - j + 1 + 2 * min(j, n - pos - 1)) >= k) {
                    arr[j] = cnt;
                    q.push({j, cnt + 1});
                }
            }
        }
        for (auto& i : arr) if (i == -2) i = -1;
        return arr;
    }
    void test(void) {
        vector<int> a = {};
        auto ans = minReverseOperations(5, 0, a, 4);
        debug(ans);
    }
};

#ifdef __TEST__
__TEST__
#endif