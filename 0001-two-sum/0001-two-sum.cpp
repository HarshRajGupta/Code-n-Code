#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            if (mp[target - nums[i]]) return {i, mp[target - nums[i]] - 1};
            mp[nums[i]] = i + 1;
        }
        return {};
    }
    void test() {
        debug(twoSum({1, 2, 3, 4}, 3));
    }
};

#ifdef __TEST__
__TEST__
#endif