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
#define __RUN std::cout << "Case #" << tC << ": ", solve(), std::cout << '\n'
#endif

const unsigned long long MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, n) for (auto i = a; i < n; ++i)
#define bw(i, n) for (int i = n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(void) {
    int n; cin >> n;
    v<pair<string, int>> ada(n);
    v<pair<int, int>> charles(n);
    _for(i, n) {
        string s;
        int d, u;
        cin >> s >> d >> u;
        ada[i].ft = s;
        ada[i].sd = u;
        charles[i].ft = d;
        charles[i].sd = u;
    }
    sort(all(ada));
    sort(all(charles));
    // reverse(all(charles));
    debug(ada)
    debug(charles)
    int res = 0;
    _for(i, n) {
        if (ada[i].sd == charles[i].sd)
            res++;
    }
    cout << res;
}

signed main(const signed argc, const char **argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    int tCs; cin >> tCs;
    for (int tC = 0; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}