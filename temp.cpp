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
#define __RUN solve()
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

int ans(const int n, int m) {
    int prev = n;
    debug(n, m)
    _for(i, m) {
        int res = 0;
        while (prev) {
            res += prev % 10;
            prev /= 10;
        }
        prev = res;
    }
    return prev;
}
void solve() {
    int n, q; cin >> n >> q;
    int arr[n];
    v<int> val(n + 1, 0), netVal(n + 1);
    _for(i, n) {cin >> arr[i];}
    int x = n, y = 0;
    while (q--) {
        int qu; cin >> qu;
        if (qu == 1) {
            int l, r; cin >> l >> r;
            val[l - 1]++;
            val[r]--;
            x = min(x, l - 1);
            y = max(y, r);
        } else {
            int ind, moves = 0; cin >> ind;
            debug(ind)
            rep(i, x, y + 1) {
                moves += val[i];
                val[i] = 0;
                netVal[i] += moves;
            }
            cout << ans(arr[ind - 1], netVal[ind - 1]) << ln;
            x = n, y = 0;
        }
    }
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