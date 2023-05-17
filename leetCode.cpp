#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
    int subSeq(const vector<int> &nums, const int t, int index = 0, int sum = 0) {
        if (index == nums.size() || sum >= t) {
            return (sum == t);
        }
        return subSeq(nums, t, index + 1, sum) + subSeq(nums, t, index, sum + nums[index]);
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        return subSeq(nums, target);
    }
    void test() {
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif