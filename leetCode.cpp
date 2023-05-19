#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        vector<int> leftMonotony(n), rightMonotony(n, 0), prefixSum(n + 1);
        int currMax = 0;
        for (int i = 0; i < n; ++i) {
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
            debug(i, j)
            ans += ((j - i - 1) * height[i]) - (prefixSum[j] - prefixSum[i + 1]);
            debug(i, j, ans)
            i = j;
        }
        debug(ans)
        currMax = i;
        i = n - 1;
        while (i != currMax) {
            int j = i - rightMonotony[i];
            debug(i, j)
            ans += (i - j - 1) * height[i] - (prefixSum[i] - prefixSum[j + 1]);
            debug(i, j, ans)
            i = j;
        }
        return ans;
    }
    void test() {
        vector<int> t = {2, 0, 2};
        cout << trap(t) << endl;
    }
};

#ifdef __TEST__
__TEST__
#endif