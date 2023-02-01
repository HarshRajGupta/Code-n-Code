#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __RUN
#define __RUN solve(), std::cout << '\n'
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

vector<int> dp(1e9 + 1, -1);

int ans(int n) {
    if (n == 1 || n <= 0) return 0;
    if (dp[n] != -1) return dp[n];
    if (n % 6 == 0) return dp[n] = min(ans(n / 2), ans(n / 3)) + 1;
    if (n % 3 == 0) return dp[n] = min(ans(n / 3) + 1, ans(n / 2) + 2);
    if (n % 2 == 0 && (n - 1) % 3 == 0) return dp[n] = min(ans(n / 2) + 1, ans(n / 3) + 2);
    if (n % 2 == 0 && (n - 2) % 3 == 0) return dp[n] = min(ans(n / 2) + 1, ans(n / 3) + 3);
    if ((n - 1) % 6 == 0) return dp[n] = min(ans(n / 2), ans(n / 3)) + 2;
    return dp[n] = ans(n - 1) + 1;
}


void solve() {
    int n; cin >> n;
    cout << ans(n);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs; cin >> tCs;
    for (uint32_t tC = 0; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}