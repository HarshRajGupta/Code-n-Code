#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
    const int lB(const std::vector<int> &arr, const int t, int l = 0, int r = -1) {
        if (r == -1) r = (arr.size() - 1);
        if (arr[l] >= t) return l - 1;
        if (arr[r] < t) return r;
        int ans = l - 1, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (arr[mid] >= t) r = (mid - 1);
            else ans = mid, l = (mid + 1);
        }
        return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size());

    }
    void test() {
        /* test */
        vector<int> arr = {1, 3, 4, 5, 6, 7, 8, 9};
        cout << arr[lB(arr, 5)];
    }
};

#ifdef __TEST__
__TEST__
#endif