#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
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

v<int> oddLog = {
    0,
    1,
    10,
    200,
    2000,
    30000,
    300000,
    4000000,
    40000000,
    500000000,
    5000000000
};

v<int> evenLog = {
    0,
    0,
    1,
    10,
    200,
    2000,
    30000,
    300000,
    4000000,
    40000000,
    500000000,
    5000000000
};
void solve() {
    int a, b; cin >> a >> b;
    int firstDigit = (a / ((int)pow(10, (int)log10(a))));
    int CountOfB  = (firstDigit + 1) * (evenLog[log10(a)]);
    if (firstDigit >= b && (((int)log10(a)) & 1)) {
        CountOfB += (int)pow(10, (int)log10(a));
    }
    rep(i, 1, 9) {
        int temp = (firstDigit + 1) * (oddLog[log10(a)]);
        if (firstDigit >= i && (((int)log10(a)) & 1)) {
            CountOfB += (int)pow(10, (int)log10(a));
        }
    }
}

signed main() {
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