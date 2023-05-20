#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
public:
    int longSubarrWthSumDivByK(int arr[], int n, int k) {
        vector<int> prefixSum(n + 1);
        map<int, pair<int, int>> mp;
        pair<int, int> testPair;
        int MAX = 0;
        rep(i, 0, n) {
            prefixSum[i + 1] = (prefixSum[i] + arr[i]) % k;
            if (prefixSum[i + 1] && mp[prefixSum[i + 1]] == testPair) {
                mp[prefixSum[i + 1]] = {i + 1, i + 1};
            } else {
                auto [l, r] = mp[prefixSum[i + 1]];
                mp[prefixSum[i + 1]] = {min(i + 1, l), max(i + 1, r)};
                MAX = max(MAX, mp[prefixSum[i + 1]].second - mp[prefixSum[i + 1]].first);
            }
        }
        debug(prefixSum, mp)
        if (prefixSum[n] == 0) return n;
        return MAX;
    }
    void test() {
        int vt[] = {18, 9, 9, 10, 5, 16, 15, 13, 6, 15, 3};
        cout << longSubarrWthSumDivByK(vt, 11, 4);
    }
};

#ifdef __TEST__
__TEST__
#endif