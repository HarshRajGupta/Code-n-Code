#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

#ifndef __RUN
#define __RUN solve(), std::cout << '\n'
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

void solve() {
    int n; cin >> n;
    v<int> arr(n);
    set<int> p, q;
    v<int> P(n), Q(n);
    _for(i, n) {
        cin >> arr[i];
        p.insert(i + 1);
        q.insert(i + 1);
    }
    _for(i, n) {
        if (p.find(arr[i]) != p.end()) {
            P[i] = arr[i];
            p.erase(arr[i]);
        } else if (q.find(arr[i]) != q.end()) {
            Q[i] = arr[i];
            q.erase(arr[i]);
        } else {
            cout << "NO";
            return;
        }
    }
    debug(p, q)
    // _for(i, n) {
    //     if (P[i] == 0) {
    //         auto t = p.lower_bound(Q[i]);
    //         if (*t > Q[i]) {
    //             cout << "NO";
    //             return;
    //         }
    //         P[i] = *t;
    //         p.erase(t);
    //     } else {
    //         auto t = q.lower_bound(P[i]);
    //         if (*t > P[i]) {
    //             cout << "NO";
    //             return;
    //         }
    //         Q[i] = *t;
    //         q.erase(t);
    //     }
    // }
    cout << *p.lower_bound(5);
    cout << "YES\n";
    _for(i, n) cout << P[i] << ' ';
    cout << ln;
    _for(i, n) cout << Q[i] << ' ';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs = 1u;
    cin >> tCs;
    for (uint32_t tC = 0u; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}