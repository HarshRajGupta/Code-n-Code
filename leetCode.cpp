#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        for (int i = ans.size() - 2; i >= 0; --i) {
            if (temperatures[i] < temperatures[i + 1]) ans[i] = 1;
            else {
                int j = ans[i + 1];
                while (j && temperatures[i] >= temperatures[i + j + 1] ) {
                    if (ans[i + j + 1]) j += ans[i + j + 1];
                    else j = 0;
                }
                if (temperatures[i] < temperatures[i + j + 1])
                    ans[i] = j + 1;
            }
        }
        return ans;
    }
    void test() {
        vector<int> temp = {55, 38, 53, 81, 61, 93, 97, 32, 43, 78};
        vector<int> ans = dailyTemperatures(temp);
        debug(ans)
    }
};

#ifdef __TEST__
__TEST__
#endif