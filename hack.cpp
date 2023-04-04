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
    v<int> arr(n - 1), b(n);
    _for(i, n - 1) cin >> arr[i];
    int i = 0, j = 0;
    while (i < n - 1 && j < n - 1) {
        debug(i, j, b)
        if (max(b[i], b[i + 1]) == arr[j]) {
            ++i; ++j;
            continue;
        }
        if (max(b[i], b[i - 1]) > arr[j]) {
            debug(b)
            b[++i] = arr[j];
        } else {
            b[i] = arr[j];
        }
        ++i; ++j;
    }
    // int done = 0;
    // b.push_back(arr[0]);
    // rep(i, 1, n - 1) {
    //     debug(i, b, arr[i])
    //     if (!done && max(b.back(), arr[i]) > arr[i - 1]) {
    //         b.push_back(0);
    //         done = 1;
    //     }
    //     b.push_back(arr[i]);
    // }
    // if (!done) b.push_back(0);
    // debug(b)
    // bw(i, n - 1) {
    //     if (max(b[i], b[i - 1]) > arr[i - 1]) {
    //         b[i - 1] = 0;
    //     }
    // }
    _for(i, sz(b)) cout << b[i] << ' ';
}

signed main(void) {__MAIN__}