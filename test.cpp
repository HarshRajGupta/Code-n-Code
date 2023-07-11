#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    vector<vector<set<int>>> dp;
    int n = 0;
    set<int> subSeqSums(vector<int>& nums, int pos = 0, int selected = 0) {
        if ((pos >= (n << 1)) || (selected >= n)) return {};
        if ((nums.size() - pos) < (n - selected)) return {};
        if (dp[selected][pos].size()) return dp[selected][pos];
        set<int> skip = subSeqSums(nums, pos + 1, selected),
                 select = subSeqSums(nums, pos + 1, selected + 1);
        for (auto &i : select) skip.insert(i + nums[pos]);
        if (selected == n - 1) skip.insert(nums[pos]);
        return dp[selected][pos] = skip;
    }
public:
    int minimumDifference(vector<int>& nums) {
        n = nums.size() >> 1;
        dp = vector<vector<set<int>>>(n, vector<set<int>>(n << 1));
        auto subSeqSum = subSeqSums(nums);
        int sum = 0;
        for (auto &i : nums) sum += i;
        auto lb = subSeqSum.lower_bound((sum >> 1)), ub = subSeqSum.upper_bound((sum >> 1));
        int MIN = abs(*lb - (sum - *lb));
        if (lb != subSeqSum.begin()) {
            MIN = min(MIN, sum - *prev(lb));
        } else if (lb != subSeqSum.end() && next(lb) != subSeqSum.end()) {
            MIN = min(MIN, sum - *next(lb));
        }
        if (ub != subSeqSum.begin()) {
            MIN = min(MIN, sum - *prev(ub));
        } else if (ub != subSeqSum.end() && next(ub) != subSeqSum.end()) {
            MIN = min(MIN, sum - *next(ub));
        }
        return MIN;
    }
    void test() {
        vector<int> a = {3, 7, 9, 3};
        cout << minimumDifference(a);
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