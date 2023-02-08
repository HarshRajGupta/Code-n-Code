#ifndef __FAST_IO
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __RUN
#define __RUN solve(), std::cout << '\n'
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

template <class T> using v = std::vector<T>;
template <class T> using xHeap = std::priority_queue<T>;
template <class T> using nHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define _for(i, n) for(int64_t i = 0; i < (int64_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int64_t i = n; i >= 0; --i)

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
    int n; cin >> n;
    v<int> arr(n);
    _for(i, n) cin >> arr[i];
    sort(all(arr));
    int MAX = INT_MAX, MIN = INT_MAX;
    debug(arr)
    for (auto i = arr.begin(); i != arr.end(); ++i) {
        for (auto j = arr.begin() + n - 1; j != i; --j) {
            int mid = (*i + *j) / 2;
            auto l = lower_bound(i + 1, j, mid - 1), r = upper_bound(i + 1, j, mid + 1);
            if ( r != j) ++r;
            for (auto t = l; t != j && t != r; ++t) {
                MAX = min(MAX, abs(*i + *j - 2 * (*t)));
            }
        }
    }

    _for(i, n) {
        for (int j = n - 1; j > i + 1; --j) {
            for (int k = i + 1; k < j; ++k) {
                MIN = min(MIN, abs(arr[i] + arr[j] - 2 * arr[k]));
            }
        }
    }
    if (MIN != MAX) cout << "NO";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs; cin >> tCs;
    for (uint32_t tC = 0; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}