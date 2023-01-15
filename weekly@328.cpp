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

long long countGood(vector<int>& nums, int k) {
    map<int, int> mp;
    size_t ct = 0, l = 0, r = 0, p = 0;
    while (l <= r && r <= nums.size()) {
        debug(p, k, ct)
        if (p == k) {
            while (l < r && mp[nums[l]] == 1) {
                // cout << l << ' ';
                ++ct;
                mp[nums[l]]--;
                ++l;
            }
            ct++;
            mp[nums[l]]--;
            p--;
        } else if (r < nums.size()) {
            if (mp[nums[r]]) {
                p += mp[nums[r]];
                // cout << p << ' ' << l << ' ' << r << '\n';
                debug(mp, nums[r], p, l, r)
            }
            mp[nums[r]]++;
            r++;
        } else break;
    }
    return ct;
}

void solve(void) {
    v<int> a = {1,1,1,1,1};
    cout << countGood(a, 2ll);
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