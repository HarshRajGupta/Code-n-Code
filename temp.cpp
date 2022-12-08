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

int diff(string &s, int l, int r, char c) {
    int count = 0;
    for (int i = l ; i <= r ; ++i) {
        if (s[i] != c)
            count++;
    }
    return count;
}

int movesCount(string &s, int l, int r, char c) {
    debug(s, l, r, c)
    // if (l >= r - 1)
    //     return diff(s, l, r - 1, c);
    if (l >= r)
        return INT_MAX;
    if (r - l == 2) {
        return min(diff(s, l, l, c) + diff(s, r - 1, r - 1, c + 1), diff(s, l, l, c + 1) + diff(s, r - 1, r - 1, c));
    }
    if (r - l == 1) {
        return diff(s, l, l, c);
    }
    int L = diff(s, l, (r / 2) - 1, c), R = diff(s, (r / 2), r - 1, c);
    debug(l, r, c, L, R)
    return min(L + movesCount(s, (r / 2), r, c + 1), R + movesCount(s, l, (r / 2) , c + 1));
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    cout << movesCount(s, 0, n, 'a');
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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