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

long long equi (int n, vector<int> &a) {
    int even = 0, odd = 0, MAX = 0;
    for (auto &i : a) {
        if (i & 1) ++odd;
        else ++even;
        MAX = max(MAX, i);
    }
    if (odd & 1 && even & 1) {
        return -1;
    } else if (odd & 1) {
        if (!(MAX & 1)) ++MAX;
        long long ans = even / 2;
        for (auto &i : a) {
            if (i & 1) {
                ans += (MAX - i) / 2;
            } else {
                ans += (MAX - (i + 1)) / 2;
            }
        }
        debug(ans, odd, even, MAX)
        return ans;
    } else if (even & 1) {
        if (MAX & 1) ++MAX;
        long long ans = odd / 2;
        for (auto &i : a) {
            if (!(i & 1)) {
                ans += (MAX - i) / 2;
            } else {
                ans += (MAX - (i + 1)) / 2;
            }
        }
        debug(ans, odd, even, MAX)
        return ans;
    } else {
        if (MAX & 1) {
            long long ans = even / 2;
            for (auto &i : a) {
                if (i & 1) {
                    ans += (MAX - i) / 2;
                } else {
                    ans += (MAX - (i + 1)) / 2;
                }
            }
            debug(ans, odd, even, MAX)
            return ans;
        } else {
            long long ans = odd / 2;
            for (auto &i : a) {
                if (!(i & 1)) {
                    ans += (MAX - i) / 2;
                } else {
                    ans += (MAX - (i + 1)) / 2;
                }
            }
            debug(ans, odd, even, MAX)
            return ans;
        }
    }
}

long long equi2 (int n, vector<int> &a) {
    int even = 0, odd = 0, MAX = 0;
    for (auto &i : a) {
        if (i & 1) ++odd;
        else ++even;
        MAX = max(MAX, i);
    }
    long long ans = 0;
    if (odd & 1 && even & 1)
        return -1;
    if ((odd & 1 && !(MAX & 1)) || (even & 1 && MAX & 1))
        ++MAX;
    if (odd & 1)
        ans += even / 2;
    if (even & 1)
        ans += odd / 2;
    for (auto &i : a) {
        ans += (MAX - i) / 2;
    }
    debug(odd, even, MAX)
    return ans;
}

void solve(void) {
    int n; cin >> n;
    v<int> a(n);
    foreach(i, a) cin >> i;
    int one = equi(n, a), two = equi2(n, a);
    if (one != 2) {
        debug(one, two, a)
    }
}

bool preCompute(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush(); return 0;
}

__MAIN__

/*
 * @ScratchPad
*/