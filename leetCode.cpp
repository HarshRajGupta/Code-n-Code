#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    bool canDo(vector<int> &a, vector<int> &b, int x, int y) {
        int ans = 0, MAX = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (b[i] <= y)
                ans += a[i];
            else {
                MAX = max(MAX, a[i]);
            }
        }
        return (ans + MAX) >= x;
    }
    int scoreAndCost(vector<int> &a, vector<int> &b, int x) {
        int ans = -1, l = 1, r = 1e5, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (canDo(a, b, x, mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
public:
    void test() {
        vector<int> a = {3, 7, 1}, b = {2, 4, 4};
        cout << scoreAndCost(a, b, 2);
    }
};

#ifdef __TEST__
__TEST__
#endif