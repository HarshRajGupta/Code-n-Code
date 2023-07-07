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
    int n, m, h; cin >> n >> m >> h;
    v<pair<int, int>> rank(n);
    v<v<int>> arr(n, v<int>(m));
    foreach (i, arr) {
        foreach(j, i) cin >> j;
        sort(all(i));
    }
    debug(arr);
    _for(i, n) {
        int sum = 0, points = 0;
        _for (j, m) {
            if (sum + sum + arr[i][j] > h) {
                break;
            }
            sum = sum + sum + arr[i][j];
            ++points;
        }
        rank[i] = {points, i};
    }
    debug(rank)
    auto rudolf = rank[0];
    int ans = 1;
    _for(i, n) {
        if (rank[i].first > rudolf.first) {
            ++ans;
        } else if (rank[i].first == rudolf.first && rank[i].second < rudolf.second) {
            ++ans;
        }
    }
    cout << ans;
}

void preCompute() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush();
}

/**
 * @ScratchPad
 */

__MAIN__