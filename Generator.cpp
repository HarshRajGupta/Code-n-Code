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
    int m; cin >> m;
    v<v<int>> arr(m);
    map<int, int> mp;
    _for(i, m) {
        int n; cin >> n;
        v<int> a(n);
        _for(j, n) {
            cin >> a[j];
            mp[a[j]] = i;
        }
        arr[i] = a;
    }
    _for(i, m) {
        int n = sz(arr[i]);
        bool found = false;
        _for(j, n) {
            if (mp[arr[i][j]] == i) {
                cout << arr[i][j] << ' ';
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << ' ';
            return;
        }
    }
}

signed main(void) {__MAIN__}