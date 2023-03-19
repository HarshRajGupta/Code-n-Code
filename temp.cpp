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
#define __RUN uint32_t tCs; cin >> tCs; for(uint32_t tC = 0; tC++ < tCs; solve(), std::cout << '\n');
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

void solve() {
    /* Code */
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __START
    __START
#endif
    __RUN
#ifdef __END
    __END
#endif
    return 0;
}