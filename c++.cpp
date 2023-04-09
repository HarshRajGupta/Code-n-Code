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

void solve(void) {
    int n; cin >> n;
    v<v<int>> arr(2, v<int>(n));
    int p = 2 * n, q = 1;
    _for(i, n / 2) {
        if (i & 1) {
            arr[0][n - 1 - i] = p--;
            arr[1][i] = p--;
        } else {
            arr[0][i] = p--;
            arr[1][n - 1 - i] = p--;
        }
    }
    _for(i, n) {
        arr[!(i & 1)][i] = q++;
    }
    _for(i, n) cout << arr[0][i] << ' ';
    cout << ln;
    _for(i, n) cout << arr[1][i] << ' ';
}

signed main(void) {__MAIN__}