#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int MaximizeEqualNumbers(int n, int k, vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while (j < n) {
            if (nums[j] - nums[i] <= (2 * k)) {
                ans = max(ans, j - i + 1);
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
    void test() {
        int n = 4, k = 1;
        vector<int> nums = {2, 1, 5, 3};
        cout << MaximizeEqualNumbers(n, k, nums) << endl;
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif