#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

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
    int64_t ceil (long double n, long double d = 1) {
        return (n / d) + (n > (d * ((int64_t)(n / d))));
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size());

    }
    void test() {
        /* test */
        vector<int> arr = {1, 3, 4, 5, 6, 7, 8, 9};
        cout << arr[uB(arr, 5)];
    }
};

#ifdef __TEST__
__TEST__
#endif