#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maj = -1;
        for (int &i : nums) {
            mp[i]++;
            if (mp[i] * 2 > nums.size()) {
                maj = i;
                break;
            }
        }
        if (maj == -1) return -1;
        vector<int> count(nums.size(), 0);
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == maj) ++total;
            count[i] = total;
        }
        debug(count);
        for (int i = 0; i < nums.size() - 1; ++i) {
            debug(count[i], total, i);
            if ((count[i] * 2 > (i + 1)) && ((total - count[i]) * 2) > (nums.size() - i)) {
                return i;
            }
        }
        return -1;
    }
    void test() {
        vector<int> a = {1,2,2,2};
        cout << minimumIndex(a);
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