#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int32_t i = (int32_t)n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(void) {
    int  n; cin >> n;
    v<v<int>> arr(n);
    v<int> a;
    _for(i, n) {
        int s; cin >> s;
        v<int> e(s);
        _for(j, s) {
            cin >> e[j];
            a.push_back(e[j]);
        }
        arr[i] = e;
    }
    sort(all(a));
    debug(a)
    int split = 0;
    _for(i, n) {
        _for(j, sz(arr[i]) - 1) {
            if (++upper_bound(all(a), arr[i][j]) != a.end() || *(++upper_bound(all(a), arr[i][j])) != *(lower_bound(all(a), arr[i][j + 1]))) {
                split++;
                debug(arr[i][j], arr[i][j + 1])
            }
        }
    }
    cout << split << " " << n - 1 + split;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}