#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    vector<int> fun(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n, 1), arr = {nums[0]};

        for (int i = 1; i < n; i++) {
            if (nums[i] > ans.back()) {
                arr.push_back(nums[i]);
                ans[i] = (arr.size());
            }
            else {
                int low = lower_bound(ans.begin(), ans.end(),
                                      nums[i])
                          - ans.begin();
                arr[low] = nums[i];
                ans[i] = low + 1;
            }
        }
        return ans;
    }
    void test() {
        vector<int> t = {2, 1, 3, 1, 6, 2};

        auto ans = fun(t);
        debug(ans);
    
    }
};

#ifdef __TEST__
__TEST__
#endif