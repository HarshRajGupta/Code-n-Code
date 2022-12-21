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

// #define int long long
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


int fun(const v<int> &arr, const v<v<int>> &bit, int x, int in, int val) {
    int XOR1 = 0, XOR2 = 0;
    _for(i, 8) {
        if (bit[x + 1][i] % 2)
            XOR1 += (1 << i);
        if ((bit[arr.size()][i] - bit[x + 1][i]) % 2)
            XOR2 += (1 << i);
    }
    if (in - 1 <= x) {
        // debug(XOR1, XOR1 ^ arr[in - 1], XOR1 ^ arr[in - 1]^val)
        XOR1 = ((XOR1 ^ arr[in - 1])^val);
    }
    else {
        // debug(XOR2, XOR2 ^ arr[in - 1], XOR2 ^ arr[in - 1]^val)
        XOR2 = ((XOR2 ^ arr[in - 1])^val);
    }
    int S1 = (XOR1 | XOR2), S2 = (XOR1 & (~(XOR2)));
    debug(!XOR2)
    return S1 - S2;
}

void solve(void) {
    int n, q; cin >> n >> q;
    v<int> arr(n);
    v<v<int>> bit(n + 1, v<int>(8));
    _for(i, n) {
        cin >> arr[i];
        int t = arr[i], j = 0;
        bit[i + 1] = bit[i];
        while (t) {
            bit[i + 1][j] += (t % 2);
            t /= 2;
            ++j;
        }
    }
    debug(bit)
    while (q--) {
        int in, val; cin >> in >> val;
        int MAX = 0;
        _for(i, n) {
            int x = fun(arr, bit, i, in, val);
            debug(x, i, q)
            MAX = max(MAX, fun(arr, bit, i, in, val));
        }
        cout << MAX << ln;
    }
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