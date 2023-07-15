#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start = 0, len = 0, end = 0, count = 0, ans = 0;
        while (start < nums.size()) {
            while (count < k && len < nums.size()) {
                if (nums[len] & 1) ++count;
                ++len;
            }
            if (len == nums.size()) break;
            end = len + 1;
            while (end < nums.size() && !(nums[end] & 1)) {
                ++end;
            }
            ans += (end - len) + 1;
            debug(start, ans, len, end, count);
            if (nums[start] & 1) --count;
            ++start;
            debug(start, ans, len, end, count);
        }
        return ans;
    }
    void test() {
        vector<int> a = {1, 1, 2, 1, 1};
        cout << numberOfSubarrays(a, 3);
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