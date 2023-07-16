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
        vector<int> ans(word.size(), 0);
        int MAX = 0;
        for (int i = word.size() - 1; i >= 0; --i) {
            ans[i] = ans[i + 1] + 1;
            for (auto &j : len) {
                auto s = word.substr(i, j);
                debug(i, j, s)
                if (i + j > word.size()) break;
                debug(s)
                if (mp.find(s) != mp.end()) {
                    ans[i] = j - 1;
                    break;
                }
            }
            MAX = max(ans[i], MAX);
        }
        debug(ans)
        return MAX;
    }
    void test() {
        vector<string> a = {"bcca", "aaa", "aabaa", "baaac"};
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