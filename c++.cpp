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
    const int lB(const std::vector<int> &arr, const int &t) {
        if (t > arr[arr.size() - 1])
            return (arr.size() - 1);
        else if (t <= arr[0])
            return -1;
        int l = 0, r = (arr.size() - 1), ans = - 1;
        while (l <= r) {
            int mid = ((l + r) / 2);
            if (arr[mid] >= t)
                r = (mid - 1);
            else
                ans = mid, l = (mid + 1);
        }
        return ans;
    }
    long long minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<long long> prefixSum(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        long long MIN = LLONG_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            int idx = lB(nums, nums[i]);
            MIN = min(MIN, ((nums[i] * 1ll * (idx + 1) - prefixSum[idx + 1]) + (prefixSum[nums.size()] - prefixSum[idx + 1] - (nums[i] * 1ll * (nums.size() - idx - 1)))));
        }
        return MIN;
    }
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long ans = 0;
        map<int, int> mp;
        for (int i = 0; i < k; ++i) {
            vector<int> tmp;
            for (int j = i; j < arr.size() && !mp[j]; j += k, j %= arr.size()) {
                mp[j] = 1;
                tmp.push_back(arr[j]);
            }
            ans += minMoves(tmp);
            debug(k, ans)
        }
        return ans;
    }
    void test(void) {
        vector<int> arr = {1, 7, 9, 6};
        cout << makeSubKSumEqual(arr, 1);
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif