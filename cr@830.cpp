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

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    v<int> zero(n + 1), one(n + 1);
    _for(i, n) {
        zero[i + 1] = zero[i];
        if (s[i] == '0') zero[i + 1]++;
    }
    bw(i, n - 1) {
        one[i] = one[i + 1];
        if (s[i] == '1') one[i]++;
    }
    debug(zero, one)
    int ct = 0;
    bw(i, n - 2) {
        if (s[n - 1] == '1') break;
        if (s[i + 1] == '0' && s[i] == '1') {
            ct++;
            break;
        }
    }
    bool oneF = false;
    if (s[n - 1] == '1') oneF = true;
    bw(i, n - 2) {
        if (s[i] == '1' && s[i + 1] == '0' && oneF) ct += 2;
        if (s[i] == '1') oneF = true;
    }
    cout << ct;
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