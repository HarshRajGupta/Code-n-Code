#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp[2] = {vector<int>(nums1.size(), -1), vector<int>(nums1.size(), -1)};
        dp[0][nums1.size() - 1] = dp[1][nums1.size() - 1] = 1;
        int res = 1;
        for (int i = nums1.size() - 2; i >= 0; --i) {
            if (nums1[i] <= nums1[i + 1]) {
                dp[0][i] = dp[0][i + 1] + 1;
            }
            if (nums2[i] <= nums2[i + 1]) {
                dp[1][i] = dp[1][i + 1] + 1;
            }
            if (nums1[i] <= nums2[i + 1]) {
                dp[0][i] = max(dp[0][i], dp[1][i + 1] + 1);
            }
            if (nums2[i] <= nums1[i + 1]) {
                dp[1][i] = max(dp[1][i], dp[0][i + 1] + 1);
            }
            res = max(res, max(dp[0][i], dp[1][i]));
        }
        debug(dp[0], dp[1])
        return res;
    }
    void test() {
        vector<int> a = {2, 3, 1}, b = {1, 2, 1};
        debug(maxNonDecreasingLength(a, b));
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif