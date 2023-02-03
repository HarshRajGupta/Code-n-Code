#ifndef __FAST_IO
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

template <class T> using v = std::vector<T>;
template <class T> using xHeap = std::priority_queue<T>;
template <class T> using nHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define _for(i, n) for(int64_t i = 0; i < (int64_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int64_t i = n; i >= 0; --i)

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int ans(v<v<int>> &mp, int ind, int n) {
    int res = 0;
    _for(i, 26) {
        if (mp[ind][i] > 0) ++res;
        if (mp[n - 1][i] - mp[ind][i] > 0) ++res;
    }
    return res;
}
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    v<v<int>> mp(n);
    int res = 0;
    v<int> prev(26);
    _for(i, n) {
        mp[i] = prev;
        mp[i][s[i] - 'a']++;
        prev[s[i] - 'a']++;
    }
    _for(i, n) {
        res = max(res, ans(mp, i, n));
    }
    cout << res;
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