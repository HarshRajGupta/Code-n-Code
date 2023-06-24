#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    const int uB(const std::vector<int> &arr, const int t, int l = 0, int r = -1) {
        if (r == -1) r = (arr.size() - 1);
        if (t < arr[l]) return l;
        if (t > arr[r]) return r + 1;
        int ans = r + 1, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (arr[mid] <= t) l = (mid + 1);
            else ans = mid, r = (mid - 1);
        }
        return ans;
    }
public:
    vector<int> fun(int n, vector<int> &nums) {
        vector<int> ans(n, 1), arr = {nums[0]};
        for (int i = 1; i < n; i++) {
            if (nums[i] > arr.back()) {
                arr.push_back(nums[i]);
                ans[i] = (arr.size());
            }
            else {
                int low = uB(arr, nums[i]);
                arr[low] = nums[i];
                ans[i] = low + 1;
            }
        }
        return ans;
    }
    void test() {
        vector<int> t = {2, 1, 3, 1, 6, 2};

        auto ans = fun(6, t);
        debug(ans);

    }
};

#ifdef __TEST__
__TEST__
#endif