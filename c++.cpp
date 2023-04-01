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
    long long minMoves(vector<int>& arr) {
        debug(arr);
        sort(arr.begin(), arr.end());
        long long sum = 0;
        for (auto& x : arr) sum += (x - arr[0]);
        return sum;
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
        vector<int> arr = {2,5,5,7};
        cout << makeSubKSumEqual(arr, 3);
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif