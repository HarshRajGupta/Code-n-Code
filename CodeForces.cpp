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
// #define __RUN std::cout << "Case #" << tC << ": ", solve(), std::cout << '\n'
#define __RUN solve(), std::cout << '\n'
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

void solve() {
    int x, y; cin >> x >> y;
    if (x >= y) {
        int a = y - 1, b = y;
        int c = (3 * x) - a - b;
        cout << a << " " << b << " " << c;
        return;
    }
    int c = y + 1, b = y;
    int a = (3 * x) - b - c;
    cout << a << " " << b << " " << c;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    int tCs;
    cin >> tCs;
    for (int tC = 0; tC++ < tCs; __RUN)
        ;
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}