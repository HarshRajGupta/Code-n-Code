#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;

#define _for(i, n) for(int64_t i = 0; i < (int64_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int64_t i = n; i >= 0; --i)

template <class T> using v = std::vector<T>;
template <class T> using xHeap = std::priority_queue<T>;
template <class T> using nHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(void) {
    int n, m; cin >> n >> m;
    cout << n*m;
}

signed main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __START
    __START
#endif
    solve();
#ifdef __END
    __END
#endif
    return 0;
}