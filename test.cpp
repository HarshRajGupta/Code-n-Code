#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    bool canJoin(vector<string> &a) {
        vector<int> charCount(26);
        for (auto &i : a) {
            charCount[i[0]]--;
            charCount[i[1]]++;
        }
        bool posFound = false, negFound = false;
        for(int i = 0; i < 26; ++i) {
            if (charCount[i] > 0) {
                if (posFound) return false;
                posFound = true;
            }
            if (charCount[i] < 0) {
                if (negFound) return false;
                negFound = true;
            }
        }
        return true;
    }
    void test() {
        vector<string> s = {"he", "ll"};
        cout << canJoin(s);
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