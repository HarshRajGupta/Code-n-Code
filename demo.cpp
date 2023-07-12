#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = (nums.size() >> 1), totalSum = 0;
        for (int &i : nums) totalSum += i;
        vector<vector<int>> left(n + 1), right(n + 1);
        for (int i = 1; i < (1 << n); ++i) {
            int N = __builtin_popcount(i), lSum = 0, rSum = 0;
            for (int j = 0; j < n; ++j) {
                if ((i & (1 << j))) {
                    lSum += nums[j];
                    rSum += nums[n + j];
                    // debug(i, j, (1 << j))
                }
            }
            left[N].push_back(lSum);
            right[N].push_back(rSum);
        }
        sort(right.begin(), right.end());
        debug(left, right)
        int MIN = min(abs(totalSum - (left[n][0] * 2)), abs(totalSum - (right[n][0] * 2))), halfSum = (totalSum / 2);
        debug(MIN, totalSum)
        for (int i = 1; i < n; ++i) {
            for (int &j : left[i]) {
                auto lb = lower_bound(right[n - i].begin(), right[n - i].end(), j-halfSum);
                if (lb != right[n - i].end()) {
                    MIN = min(MIN, abs(totalSum - ((j + *lb) << 1)));
                    debug(j, *lb)
                }
            }
        }
        return MIN;
    }
    void test() {
        vector<int> a = {2, -1, 0, 4, -2, -9};
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