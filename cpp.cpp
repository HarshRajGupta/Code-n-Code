#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

const unsigned MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for (int64_t i = 0ll; i < n; ++i)
#define rep(i, a, n) for (int64_t i = a; i < n; ++i)
#define bw(i, n) for (int64_t i = n; i >= 0ll; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int64_t)(x).size())
#define all(x) (x).begin(), (x).end()

int maximisePoints(int points[], int n, int height[], int m, int checkPoints[], int c, int minHeight[], int h) {
    if (c >= 1 && checkPoints[0] == 0 && minHeight[0] > 0)
        return -1;
    int sum = 0;
    for (int i = 1; i < n; ++i)
        sum += points[i];
    if (m >= 1 && height[0] <= 0)
        sum += points[0];
    return sum;
}

void solve() {
    int n; cin >> n;
    v<int> arr(n);
    _for(i, n) cin >> arr[i];
    int sum = 0;
    rep(i, 1, n) sum += arr[i];
    v<int> height(n);
    _for(i, n) cin >> height[i];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}