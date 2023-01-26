#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

#ifndef __RUN
#define __RUN solve(), std::cout << '\n'
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

// #define int long long
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
v<int> fx(MOD), gx(MOD), dx(MOD);

void pre() {
    fx[1] = 0, gx[1] = 1;
    rep(i, 2, sz(dx)) {
        if (i & 1) {
            fx[i] = fx[i / 2];
            gx[i] = 2 * gx[i / 2];
        } else {
            fx[i] = fx[i / 2] + 1;
            gx[i] = 2 * gx[i / 2] + 1;
        }
        dx[i] = fx[i] + gx[i];
    }
}

void solve() {
    /* Code */
    // debug(dx)
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs = 1u;
    cin >> tCs;
    for (uint32_t tC = 0u; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}