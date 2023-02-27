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
    int n, s; cin >> n >> s;
    map<int, v<int>> mp;
    v<int> arr(n);
    _for(i, n) {
        cin >> arr[i];
        mp[arr[i]].push_back(i + 1);
    }
    bool done = false;
    debug(mp)
    sort(all(arr));
    _for(i, n) {
        if (arr[i] > n / 2) break;
        if (arr[i] * 2 == n && sz(mp[arr[i]]) > 1) {
            cout << mp[arr[i]][0] << ' ' << mp[arr[i]][1];
            done = true;
            break;
        } else if (sz(mp[n - arr[i]]) > 0) {
            cout << mp[arr[i]][0] << ' ' << mp[n - arr[i]][0];
            done = true;
            break;
        }
    }
    if (!done) cout << "IMPOSSIBLE";
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