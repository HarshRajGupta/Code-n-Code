#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    bool canJoin(vector<string> &a) {
        vector<int> inDegree(26), outDegree(26), same(26);
        for (auto &i : a) {
            if (i[0] == i[1]) {
                same[i[0] - 'a']++;
            } else {
                inDegree[i[0] - 'a']++;
                outDegree[i[1] - 'a']++;
            }
        }
        int posFound = 0, negFound = 0;
        for (int i = 0; i < 26; ++i) {
            if (same[i] && !inDegree[i] && !outDegree[i]) {
                return false;
            }
            int count = inDegree[i] - outDegree[i];
            if (count > 0) {
                if (posFound) return false;
                posFound = true;
            } else if (count < 0) {
                if (negFound) return false;
                negFound = true;
            }
        }
        return true;
    }
    void test() {
        vector<string> s = {"he", "ll", "el", "lo"};
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