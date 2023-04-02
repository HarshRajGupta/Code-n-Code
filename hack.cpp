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
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0;
        rep(i, 0, s.size() - 1) {
            if (s[i] != '0') continue;
            bool oneFound = false;
            int one = 0, zero = 0;
            rep(j, i + 1, s.size()) {
                debug(i, j, one, zero)
                if (oneFound && s[j] == '0') break;
                if (s[j] == '1') {
                    oneFound = true;
                    ++one;
                    if (one == zero) {
                        ans = max(ans, one + zero);
                        break;
                    }
                } else ++zero;
            }
        }
        return ans;
    }
    void test(void) {
        cout << findTheLongestBalancedSubstring("01000111") << endl;
    }
};

#ifdef __TEST__
__TEST__
#endif