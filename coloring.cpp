// #ifndef __FAST_IO
// #pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
// #pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
// #endif

// #include <bits/stdc++.h>
// using namespace std;

// #ifndef debug
// #define debug(...) ;
// #endif

// #ifndef __RUN
// #define __RUN solve(), std::cout << '\n'
// #endif

// const uint64_t MOD = 1e9 + 7;
// const char ln = '\n';

// #define int long long
// #define ll long double

// #define Y std::cout << "YES";
// #define N std::cout << "NO";

// #define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
// #define rep(i, a, n) for(auto i = a; i < n; ++i)
// #define bw(i, n) for(int32_t i = (int32_t)n; i >= 0; --i)

// #define v std::vector
// #define maxHeap std::priority_queue<int>
// #define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

// #define ft first
// #define sd second
// #define sz(x) ((int)(x).size())
// #define all(x) (x).begin(), (x).end()

// void solve() {
//     int n, m, k; cin >> n >> m >> k;
//     v<int> arr(m);
//     minHeap ar;
//     _for(i, m) {
//         cin >> arr[i];
//         ar.push(arr[i]);
//     }
//     if (k > m) {
//         cout << "NO";
//         return;
//     }
//     while(!ar.empty()) {
//         int tp = ar.top();
//         v<int> s;
//         if (sz(ar) <= k-1) {
//             while(!ar.empty()) {
//                 if (ar.top() != 1) {
//                     N;
//                     return;
//                 }
//                 ar.pop();
//             }
//             break;
//         }
//         _for(i, k) {
//             int x = ar.top();
//             ar.pop();
//             if (x-tp > 0) s.push_back(x-tp);
//         }
//         for(int i : s) {
//             ar.push(i);
//         }
//     }
//     cout << "YES";
// }

// signed main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifdef __TAG1
//     __TAG1
// #endif
//     uint32_t tCs = 1u;
//     cin >> tCs;
//     for(uint32_t tC = 0u; tC++ < tCs; __RUN);
// #ifdef __TAG2
//     __TAG2
// #endif
//     return 0;
// }

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
    int n, m; cin >> n >> m;
    v<int> arr(n + m - 1);
    _for(i, n + m - 1) {
        cin >> arr[i];
    }
    sort(all(arr));
    int sum, p = n - 1; cin >> sum;
    if (p == 0) {
        cout << sum;
        return;
    }
    debug(arr, sum)
    bw(i, n + m - 2) {
        sum += arr[i];
        if (--p == 0) {
            cout << sum;
            return;
        }
    }
    cout << sum;
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