#ifdef ONLINE_JUDGE
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

void solve(void) {
    int n, m; cin >> n >> m;
    multiset<int> a;
    _for(i, n) {
        int t; cin >> t;
        a.insert(t);
    }
    v<int> b(m), ans(m, -1);
    _for(i, m) cin >> b[i];
    _for(i, m) {
        if (sz(a) == 0) break;
        auto l = a.lower_bound(b[i]);
        debug(*l, a, b[i])
        if (*l <= b[i]) {
            ans[i] = *l;
            if (sz(a) == 1) break;
            a.erase(l);
        } else if (l != a.begin()) {
            --l;
            if (*l <= b[i]) {
                ans[i] = *l;
                if (sz(a) == 1) break;
                a.erase(l);
            }
        }
    }
    _for(i, m) cout << ans[i] << ln;
}

signed main(void) {
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