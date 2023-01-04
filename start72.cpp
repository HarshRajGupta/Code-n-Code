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

int pz(const int k, const int n) {
    int res = 1;
    _for(i, n) res *= k;
    return res;
}

bool tp(const int k, int n) {
    int l = log(n) / log(k), res = 1;
    _for(i, l) res *= k;
    if (res == n) return true;
    return false;
}

bool powerSum(v<int> &arr, const int k, int n, map<int, int> np) {
    debug(n)
    if (np[n]) return false;
    np[n] = 1;
    if (n == 0) return true;
    int z = log(abs(n)) / log(k);
    if (z >= sz(arr)) {
        np[n] = 0;
        return false;
    }
    if (n > 0) {
        if (tp(k, n)) {
            if (arr[z] <= 0) {
                arr[z]++;
                np[n] = 0;
                return true;
            }
            np[n] = 0;
            return false;
        }
        auto t1 = arr, t2 = arr;
        if (t1[z] <= 0ll) {
            t1[z]++;
            if (powerSum(t1, k, n - pz(k, z), np)) {
                arr = t1;
                np[n] = 0;
                return true;
            }
        }
        if (z + 1 >= sz(arr)) {
            np[n] = 0;
            return false;
        }
        if (t2[z + 1] <= 0) {
            t2[z + 1]++;
            if (powerSum(t2, k, n - pz(k, z + 1), np)) {
                arr = t2;
                np[n] = 0;
                return true;
            }
        }
        np[n] = 0;
        return false;
    } else {
        int m = n * -1;
        if (tp(k, m)) {
            if (arr[z] >= 0) {
                arr[z]--;
                np[n] = 0;
                return true;
            }
            np[n] = 0;
            return false;
        }
        auto t1 = arr, t2 = arr;
        if (t1[z] >= 0) {
            --t1[z];
            if (powerSum(t1, k, n + pz(k, z), np)) {
                arr = t1;
                np[n] = 0;
                return true;
            }
        }
        if (z + 1 >= sz(arr)) {
            np[n] = 0;
            return false;
        }
        if (t2[z + 1] >= 0) {
            t2[z + 1]--;
            if (powerSum(t2, k, n + pz(k, z + 1), np)) {
                arr = t2;
                np[n] = 0;
                return true;
            }
        }
        np[n] = 0;
        return false;
    }
    np[n] = 0;
    return false;
}

void solve() {
    int n, k, s; cin >> n >> k >> s;
    v<int> arr(n);
    map<int, int> np;
    if (powerSum(arr, k, s, np)) {
        _for(i, n) cout << arr[i] << " ";
    } else {
        cout << -2;
    }
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