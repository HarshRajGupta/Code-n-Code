#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    vector<int> fun(int n, vector<int> &nums) {
        vector<int> ans(n, 1), arr = {nums[0]};
        for (int i = 1; i < n; i++) {
            if (nums[i] > arr.back()) {
                arr.push_back(nums[i]);
                ans[i] = (arr.size());
            }
            else {
                int low = upper_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
                arr[low] = nums[i];
                ans[i] = low + 1;
            }
        }
        return ans;
    }
    void test() {
        vector<int> t = {2, 1, 3, 1, 6, 2};

        auto ans = fun(6, t);
        debug(ans);

    }
};

#ifdef __TEST__
__TEST__
#endif