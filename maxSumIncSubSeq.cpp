#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int32_t i = (int32_t)n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

class Solution {
    int ans(vector<int> &arr, vector<vector<int>> &dp, int prev = 0, int pos = 0) {
        if (pos == arr.size()) {
            return 0;
        }
        if (dp[pos][prev] != -1) {
            return dp[pos][prev];
        }
        if (prev == 0 || arr[pos] > arr[prev - 1]) {
            return dp[pos][prev] = max(ans(arr, dp, prev, pos + 1), ans(arr, dp, pos + 1, pos + 1) + arr[pos]);
        }
        return dp[pos][prev] = ans(arr, dp, prev, pos + 1);
    }
public:
    int maxSumIS(int arr[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<int> Arr(n);
        for (int i = 0; i < n; ++i) Arr[i] = arr[i];
        return ans(Arr, dp);
    }
};

void solve(void) {
    int n; cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    Solution ob;
    cout << ob.maxSumIS(a, n);
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}