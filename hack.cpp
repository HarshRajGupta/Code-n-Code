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
        int cnt = 1;
        for (int i = p + k - 1; i < n; i += (k - 1)) {
            if (arr[i] == -1) {
                break;
            }
            arr[i] = cnt++;
        }
        cnt = 1;
        for (int i = p - k + 1; i >= 0; i -= (k - 1)) {
            if (arr[i] == -1) {
                break;
            }
            arr[i] = cnt++;
        }
        for (int i = 0; i < n; ++i) if (arr[i] == -2) arr[i] = -1;
        return arr;
    }
    void test(void) {
        /* test */
        auto ans = minReverseOperations(4, 2, {}, 4);
        debug(ans);
    }
};

#ifdef __TEST__
__TEST__
#endif