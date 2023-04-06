#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__ ios_base::sync_with_stdio(0);cin.tie(0);signed t;cin>>t;while(t--)solve(),cout<<'\n';return 0;
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = std::vector<T>;
template<class T>using maxHeap = std::priority_queue<T>;
template<class T>using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int ceil (const long double &n, const long double d = 1) {
    if (n > (d * ((int)(n / d))))
        return (n / d) + 1;
    return (n / d);
}

int ans(int &a, int &b, int &k) {
    return (k - 1 + ceil(a, k) + ceil(b, k));
}

void solve(void) {
    int a, b; cin >> a >> b;
    int res = 1e18;
    rep(k, 1, max(a, b) + 1) {
        int t = ans(a, b, k);
        if (res < t) break;
        res = t;
    }
    cout << res;
}

signed main(void) {__MAIN__}