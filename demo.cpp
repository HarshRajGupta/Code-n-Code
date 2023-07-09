#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size() + 7);
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i + 1] += prefixSum[i];
            nums[i] += prefixSum[i + 1];
            if (nums[i] == 0) continue;
            if (nums[i] < 0) return false;
            if (i + k >= nums.size()) return false;
            prefixSum[i + 1] -= nums[i];
            nums[i] = 0;
            prefixSum[i + k + 1] += nums[i];
        }
        return true;
    }
    void test() {
        vector<int> nums = {2, 2, 3, 1, 1, 0}; int k = 3;
        cout << checkArray(nums, k) << endl;
        /* test */
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif