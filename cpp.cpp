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
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = std::vector<T>;
template<class T>using maxHeap = std::priority_queue<T>;
template<class T>using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int power(int n, int expo, int m) {
    int ans = 1;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n);
        if (ans > m) return ans;
        n = (n * 1ll * n);
        expo >>= 1;
    }
    return ans;
}

int NthRoot(int n, int m) {
    int l = 1, r = m, ans = m;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (power(mid, n, m) < m) l = mid + 1;
        else r = mid - 1, ans = mid;
    }
    return (power(ans, n, m) == m ? ans : -1);
}

void solve(void) {
    /* Code */
    cout << NthRoot(2, 1e8);
}

signed main(void) {__MAIN__}