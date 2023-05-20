#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
    void nCr(vector<int> &arr, int k, int pos, vector<int> &a) {
        if (a.size() == k) {
            for (int i : a) cout << i << ' ';
            cout << '\n';
            return;
        }
        if (pos == arr.size()) return;
        a.push_back(arr[pos]);
        nCr(arr, k, pos + 1, a);
        a.pop_back();
        nCr(arr, k, pos + 1, a);
    }
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
        return MAX;
    }
    void test() {
        vector<int> vt = {18, 9, 9, 10, 5, 16, 15, 13, 6, 15, 3}, cd;
        nCr(vt, 3, 0, cd);
    }
};

#ifdef __TEST__
__TEST__
#endif