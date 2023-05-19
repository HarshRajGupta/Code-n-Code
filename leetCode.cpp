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
#define __MAIN__ signed main() {preCompute(); signed t; cin >> t; while (t--)solve(), cout << '\n'; return 0;}
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

void solve(void) {
    int n; cin >> n;
    v<int> arr(n);
    int  N;
    _for(i, n) {
        cin >> arr[i];
        if (arr[i] == n) {
            N = i;
        }
    }
    if (N == n - 1) {
        int one = 0;
        for (int i = N - 1; i > 0; --i) {
            if (arr[i] < arr[0]) {
                one = i; break;
            }
        }
        for (int i = n - 1; i > one; --i) cout << arr[i] << " ";
        for (int i = 0; i <= one; ++i) cout << arr[i] << " ";
    } else if (N == 0) {
        _for(i, n) {
            if (arr[i] == n - 1) {
                N = i;
            }
        }
        for (int i = N; i < n; ++i) cout << arr[i] << " ";
        cout << arr[N - 1] << " ";
        for (int i = 0; i < N - 1; ++i) cout << arr[i] << " ";
    } else {
        int one = 0;
        for (int i = N - 2; i > 0; --i) {
            if (arr[i] < arr[0]) {
                one = i; break;
            }
        }
        for (int i = N; i < n; ++i) cout << arr[i] << " ";
        for (int i = N - 1; i > one; --i) cout << arr[i] << " ";
        for (int i = 0; i <= one; ++i) cout << arr[i] << " ";
    }
}

static bool preCompute(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush(); return 0;
}

__MAIN__