#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    map<string, bool> mp;
    set<int> len;
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        for (auto &i : forbidden) {
            mp[i] = true;
            len.insert(i.size());
        }
        debug(len, mp)
        vector<int> ans(word.size());
        int MAX = 0;
        for (int i = word.size() - 1; i >= 0; --i) {
            ans[i] = ans[i + 1] + 1;
            for (auto &j : len) {
                if (mp.find(word.substr(i, j)) != mp.end()) {
                    ans[i] = j - 1;
                    break;
                }
            }
            MAX = max(ans[i], MAX);
        }
        return MAX;
    }
    void test() {
        vector<string> a = {"bcca","aaa","aabaa","baaac"};
        cout << longestValidSubstring("aaaabaaacc", a);
    }
    Solution() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif