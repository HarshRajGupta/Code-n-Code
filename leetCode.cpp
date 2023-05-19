#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        vector<int> leftMonotony(n), rightMonotony(n, 0), prefixSum(n + 1);
        int currMax = 0;
        rep(i, 0, n) {
            prefixSum[i + 1] = prefixSum[i] + height[i];
            if (currMax < height[i]) {
                currMax = height[i];
                rightMonotony[i] = 0;
            } else {
                int j = i - 1;
                while (height[j] < height[i]) {
                    j -= rightMonotony[j];
                }
                rightMonotony[i] = i - j;
            }
        }
        currMax = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (currMax < height[i]) {
                currMax = height[i];
                leftMonotony[i] = 0;
            } else {
                int j = i + 1;
                while (height[j] < height[i]) {
                    j += leftMonotony[j];
                }
                leftMonotony[i] = j - i;
            }
        }
        debug(height, leftMonotony, rightMonotony, prefixSum)
        int ans = 0, i = 0;
        while (height[i] != currMax) {
            int j = i + leftMonotony[i];
            ans += ((j - i - 1) * height[i]) - (prefixSum[j + 1] - prefixSum[i + 1]);
            debug(i, j, ans)
            i = j;
        }
        debug(ans)
        i = n - 1;
        while (height[i] != currMax) {
            int j = i - rightMonotony[i];
            ans += (i - j) * height[i] - (prefixSum[i + 1] - prefixSum[j + 1]);
            i = j;
        }
        return ans;
    }
    void test() {
        vector<int> t = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        cout << trap(t) << endl;
    }
};

#ifdef __TEST__
__TEST__
#endif