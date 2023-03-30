#include <bits/stdc++.h>
using namespace std;

#ifndef OFFLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse","sse2","sse3","ssse3","sse4","popcnt","abm","mmx","avx","avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
    const int bS(const std::vector<int> &arr, const int &t, int l, int r) {
        while (l <= r) {
            const int mid = ((l + r) / 2);
            if (arr[mid] == t)
                return mid;
            else if (arr[mid] > t)
                r = (mid - 1);
            else
                l = (mid + 1);
        }
        return ((arr[l] == t) ? l : ((arr[r] == t) ? r : -1));
    }
public:
    vector<int> twoSum(vector<int> nums, int target) {
        int n = nums.size() - 1;
        sort(nums.begin(), nums.end());
        rep(i, 0, n) {
            int idx = bS(nums, target - nums[i], i + 1, n);
            if (idx != -1)
                return {i, idx};
        }
        return {};
    }
    void test(void) {
        cout << 1;
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif