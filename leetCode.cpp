#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        vector<vector<int>> pro(n + 1, vector<int>(2));
        int MAX = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] > 0) {
                if (pro[i + 1][0]) {
                    pro[i][0] = pro[i + 1][0] * nums[i];
                } else {
                    pro[i][0] = nums[i];
                }
                if (pro[i + 1][1]) {
                    pro[i][1] = pro[i + 1][1] * nums[i];
                } else {
                    pro[i][1] = nums[i];
                }
            } else if (nums[i] < 0) {
                if (pro[i + 1][0]) {
                    pro[i][1] = pro[i + 1][0] * nums[i];
                } else {
                    pro[i][1] = nums[i];
                }
                if (pro[i + 1][1]) {
                    pro[i][0] = pro[i + 1][1] * nums[i];
                } else {
                    pro[i][0] = nums[i];
                }
            }
            MAX = max(MAX, pro[i][0]);
        }
    }
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (nums[mid] == nums[r]) --r;
            else if (nums[mid] >= nums[l]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
    void test() {
        rep(i, 5, 25) {
            int t = (-1 * i) % 5;
            debug(i, t)
        }
    }
};

#ifdef __TEST__
__TEST__
#endif