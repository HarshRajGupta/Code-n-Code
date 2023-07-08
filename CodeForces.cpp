#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans = -1;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i + 1] != nums[i] + 1) continue;
            for (int j = i + 1; j < nums.size(); ++j) {
                if ((j - i) & 1 && nums[j] != nums[i + 1]) break;
                if (!((j - i) & 1) && nums[j] != nums[i]) break;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
    void test() {
        vector<int> a = {4,5,6};
        cout << alternatingSubarray(a);
        /* test */
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif