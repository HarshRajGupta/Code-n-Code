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

int xNotY(int x, int y, int n) {
    return ((n / x) - (n / ((x * y) / __gcd(x, y))));
}
int notXY(int x, int y, int n) {
    return (n - (n / x) - (n / y) + (n / ((x * y) / __gcd(x, y))));
}

int tot(int x, int y, int n, int u1, int u2) {
    int ans = notXY(x, y, n);
    if (u1 + u2 < ans) return 1;
    ans += max(u1, xNotY(y, x, n));
    ans += max(u2, xNotY(x, y, n));
    debug(x, y, n, u1, u2, xNotY(x, y, n), xNotY(y, x, n), notXY(x, y, n), ans)
    if (u1 + u2 < ans) return 1;
    if (u1 + u2 > ans) return -1;
    return 0;
}

int minimizeSet(int d1, int d2, int u1, int u2) {
    int l = 0, r = INT_MAX;
    while (l <= r) {
        int mid = (l + r) / 2;
        int c = tot(d1, d2, mid, u1, u2);
        if (c == 1) {
            r = mid - 1;
        } else if (c == -1) {
            l = mid + 1;
        } else {
            r = mid;
            break;
        }
    }
    int ans = max(l, r);
    for (int i = ans - 1; i >= 1; --i) {
        int a = tot(d1, d2, i, u1, u2);
        if (a >= 0)
            ans = i;
        else break;
    }
    return ans;
}
void solve(void) {
    /* Code */
    cout << minimizeSet(2, 4, 8, 2);
    // cout << 2;
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