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
            debug(prefixSum, nums[i], i)
            if (nums[i] == 0) continue;
            if (nums[i] < 0) return false;
            if (i + k >= nums.size()) return false;
            prefixSum[i + 1] -= nums[i];
            prefixSum[i + k + 1] += nums[i];
        }
        return true;
    }
    void test() {
        vector<int> nums = {60, 72, 87, 89, 63, 52, 64, 62, 31, 37, 57, 83, 98, 94, 92, 77, 94, 91, 87, 100, 91, 91, 50, 26};
        int k = 4;
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