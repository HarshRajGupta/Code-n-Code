#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    char fun(int n, vector<int> &inDegree, vector<int> &outDegree, vector<int> &same) {
        int posFound = 0, negFound = 0;
        for (int i = 0; i < 26; ++i) {
            if (same[i] && !inDegree[i] && !outDegree[i]) {
                if (same[i] == n) return '1';
                return '0';
            }
            int count = inDegree[i] - outDegree[i];
            if (count > 0) {
                if (posFound || count != 1) return '0';
                posFound = true;
            } else if (count < 0) {
                if (negFound || count != -1) return '0';
                negFound = true;
            }
        }
        return '1';
    }
public:
    string canJoin(vector<string> &a) {
        string ans;
        vector<int> inDegree(26), outDegree(26), same(26);
        for (auto &i : a) {
            if (i[0] == i[1]) {
                same[i[0] - 'a']++;
            } else {
                inDegree[i[0] - 'a']++;
                outDegree[i[1] - 'a']++;
            }
            ans.push_back(fun(a.size(), inDegree, outDegree, same));
        }
        return ans;
    }
    void test() {
        vector<string> s = {"le", "ll"};
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