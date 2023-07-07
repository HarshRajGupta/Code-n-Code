#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "sse4", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__ signed main(){preCompute();signed t;cin>>t;while(t--)solve(),cout<<'\n';return 0;}
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = vector<T>;
template<class T>using maxHeap = priority_queue<T>;
template<class T>using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

void solve() {
    int n, d, h; cin >> n >> d >> h;
    v<int> arr(n);
    foreach(i, arr) cin >> i;
    sort(all(arr), greater<int>());
    int prev = INT_MAX;
    long double ans = 0, area = (1.0 * d * 0.5 * h);
    debug(area)
    _for(i, n) {
        debug(arr[i], prev)
        if (arr[i] + h <= prev) {
            ans += area;
        } else {
            long double ratio =  h / (1.0 * (arr[i] + h - prev));
            ans += (area - (area / (ratio * ratio)));
        }
        prev = arr[i];
    }
    cout <<  fixed << setprecision(8) <<ans;
}

void preCompute() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush();
}

/**
 * @ScratchPad
 */

__MAIN__