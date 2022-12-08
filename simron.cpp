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

bool isStable(int p, v<int> &planets) {
    int even = 0, odd = 0;
    for (int i = 0, t = 0; i < sz(planets); ++i) {
        if (i == p) continue;
        if (t & 1) odd += planets[i];
        else even += planets[i];
        t = !t;
    }
    return (even == odd);
}

int getPlanetToDestroy(v<int> &planets) {
    v<int> even(sz(planets) + 1), odd(sz(planets) + 1);
    _for(i, sz(planets)) {
        even[i + 1] = even[i], odd[i + 1] = odd[i];
        if (i & 1) odd[i + 1] += planets[i];
        else even[i + 1] += planets[i];
    }
    _for(i, sz(planets)) {
        int e1 = even[i] + odd[sz(planets)] - odd[i + 1], o1 = odd[i] + even[sz(planets)] - even[i + 1];
        debug(i, e1, o1)
        if (e1 == o1) return i + 1;
    }
    return -1;
}

void solve(void) {
    int n; cin >> n;
    v<int> arr(n);
    _for(i, n) cin >> arr[i];
    cout << getPlanetToDestroy(arr);
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