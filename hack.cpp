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
    vector<int> minReverseOperations(int n, int p, vector<int> banned, int k) {
        if (k == 1) {
            vector<int> arr(n, -1);
            arr[p] = 0;
            return arr;
        }
        vector<int> arr(n, -2);
        arr[p] = 0;
        for (auto& i : banned) arr[i] = -1;
        int cnt = 1, j = p + 1;
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            for (; j <= pos + k - 1 && j < arr.size(); ++j) {
                if (arr[j] != -1 && (j - pos + 1 + 2 * min(pos, n - j)) >= k) {
                    arr[j] = cnt;
                    q.push(j);
                }
            }
        }
        q.push(p);
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            for (; j >= pos - k + 1 && j >= 0; --j) {
                if (arr[j] != -1 && (pos - j + 1 + 2 * min(j, n - pos)) >= k) {
                    arr[j] = cnt;
                    q.push(j);
                }
            }
        }
        return arr;
    }
    void test(void) {
        /* test */
        auto ans = minReverseOperations(5, 1, {2, 3}, 4);
        debug(ans);
    }
};

#ifdef __TEST__
__TEST__
#endif