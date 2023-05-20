#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int i = 0, j = 0, MAX = 0, count = 0;
        while (j < s.size()) {
            ++cnt[s[j] - 'A'];
            if (j - i + 1 - cnt[s[j] - 'A'] > k) {
                cnt[s[i] - 'A']--;
                ++i;
            }
            MAX = max(MAX, j - i + 1);
            ++j;
            debug(i, j, cnt)
        }
        return MAX;
    }
    void test() {
        cout << characterReplacement("BAAAB", 2);
    }
};

#ifdef __TEST__
__TEST__
#endif