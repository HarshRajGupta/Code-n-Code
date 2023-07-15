#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start = 0, len = -1, end = 0, count = 0, ans = 0;
        while (start < nums.size()) {
            debug(start, ans, len, end, count);
            while (count < k && len < (int)nums.size() - 1) {
                ++len;
                if (nums[len] & 1) ++count;
            }
            if (count < k) {
                break;
            }
            end = len + 1;
            while (end < nums.size() && !(nums[end] & 1)) {
                ++end;
            }
            ans += (end - len);
            debug(start, ans, len, end, count);
            if (nums[start] & 1) {
                if (end == nums.size()) break;
                else len = end;
            }
            ++start;
        }
        return ans;
    }
    void test() {
        vector<int> a = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 3};
        cout << numberOfSubarrays(a, 2);
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