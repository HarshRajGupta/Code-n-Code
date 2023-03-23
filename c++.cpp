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

const int power(int n, int expo, int MOD = 1000000007) {
    int ans = 1; n %= MOD;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        expo >>= 1;
    }
    // return ans;
}

int alike(v<int> arr, v<int> &p) {
    int ans = arr[p[0]];
    debug(ans)
    _for(i, sz(arr)) {
        if (arr[p[i]] != ans) {
            return -1;
        }
        arr[i] = ans;
    }
    return ans;
}

void solve(void) {
    int n, m; cin >> n >> m;
    v<int> arr(n), p(n);
    _for(i, n) {
        cin >> p[i];
        --p[i];
    }
    _for(i, n) cin >> arr[i];
    int t = alike(arr, p);
    debug(t)
    if (t == -1) {
        cout << 0;
        return;
    }
    if (t) {
        int zeros = 0;
        _for(i, n) if (!arr[i]) ++zeros;
        debug(zeros)
        cout << power(m, zeros);
    } else {
        v<int> a(arr);
        _for(i, n) {
            if (arr[p[i]] == 0) {
                a[p[i]] = -1;
            }
            arr[i] = -1;
        }
        int zeros = 0;
        _for(i, n) if (a[i] == 0) ++zeros;
        cout << (power(m, zeros)*m) % MOD;
    }
}

signed main(void) {__MAIN__}
