#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    vector<int> dp;
    set<int> powersOf5 = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625};

    int ans(string s, int pos) {
        if (pos == s.size()) return 0;
        int num = 0;
        int res = 1e5;
        if (s[pos] == '0') return -1;
        if (dp[pos] != 1e5) return dp[pos];
        for (int i = pos; i < s.size(); ++i) {
            num = (num * 2) + s[i] - '0';
            if (powersOf5.find(num) != powersOf5.end()) {
                int t = ans(s, i + 1);
                if (t != -1) res = min(res, 1 + t);
            }
        }
        return dp[pos] = (res == 1e5 ? -1 : res);
    }
public:
    int minimumBeautifulSubstrings(string s) {
        dp = vector<int>(15, 1e5);
        return ans(s, 0);
    }
    void test() {
        /* test */
        cout << minimumBeautifulSubstrings("111");
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif