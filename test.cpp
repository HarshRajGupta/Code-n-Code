#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    unordered_set<int> dp[15][30];
    int n = 0;
    unordered_set<int> subSeqSums(vector<int>& nums, int pos = 0, int selected = 0) {
        if ((pos >= (n << 1)) || (selected >= n)) return {};
        if ((nums.size() - pos) < (n - selected)) return {};
        if (dp[selected][pos].size()) return dp[selected][pos];
        if ((nums.size() - pos) == (n - selected)) {
            int sum = 0;
            for (int i = pos; i < (n << 1); ++i) sum += nums[i];
            return dp[selected][pos] = {sum};
        }
        auto skip = subSeqSums(nums, pos + 1, selected),
             select = subSeqSums(nums, pos + 1, selected + 1);
        for (auto &i : select) skip.insert(i + nums[pos]);
        return dp[selected][pos] = skip;
    }
public:
    int minimumDifference(vector<int>& nums) {
        n = nums.size() >> 1;
        auto subSeqSum = subSeqSums(nums);
        int sum = 0;
        for (auto &i : nums) sum += i;
        // auto lb = subSeqSum.lower_bound((sum >> 1)), ub = subSeqSum.upper_bound((sum >> 1));
        // int MIN = abs(*lb - (sum - *lb));
        // if (lb != subSeqSum.begin()) {
        //     MIN = min(MIN, abs(*prev(lb) - (sum - *prev(lb))));
        // } else if (lb != subSeqSum.end() && next(lb) != subSeqSum.end()) {
        //     MIN = min(MIN, abs(*next(lb) - (sum - *next(lb))));
        // }
        // return MIN;
        int MIN = INT_MAX;
        for (auto &i : subSeqSum) {
            MIN = min(MIN, abs(i - (sum - i)));
        }
        return MIN;
    }
    void test() {
        vector<int> a = { -768, 21048, -30104, 18383, 5515, 52512, -44374, 26201, 83243, -85658, 89956, -67529, -92254, 67182, -97560, -17563, 50650, 21425};
        cout << minimumDifference(a);
    }
    Solution() {
        ios::sync_with_stdio(0); cin.tie(0);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif