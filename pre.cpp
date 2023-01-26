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

const uint64_t MOD = 1e4 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for(uint64_t i = 0; i < (uint64_t)n; ++i)
#define rep(i, a, n) for(uint64_t i = a; i < n; ++i)
#define bw(i, n) for(int32_t i = (int32_t)n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int tree[MOD * 4], fx[MOD], gx[MOD];
v<int> dx(MOD);

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = dx[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node * 2, start, mid);
    build(node * 2 + 1, mid + 1, end);
    tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}

void pre() {
    fx[1] = 0, gx[1] = 1, dx[1] = 1;
    rep(i, 2, MOD) {
        if (i & 1) {
            fx[i] = fx[i / 2];
            gx[i] = 2 * gx[i / 2];
        } else {
            fx[i] = fx[i / 2] + 1;
            gx[i] = 2 * gx[i / 2] + 1;
        }
        dx[i] = fx[i] + gx[i];
    }
    build(1, 1, MOD);
}


int query(int node, int start, int end, int l, int r) {
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2, ans = -1e9;
    if (l <= mid) ans = max(ans, query(node * 2, start, mid, l, r));
    if (r > mid) ans = max(ans, query(node * 2 + 1, mid + 1, end, l, r));
    return ans;
}

void solve() {
    /* Code */
    // debug(dx)
    int l, r;
    cin >> l >> r;
    cout << query(1, 1, MOD, l, r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    debug(dx)
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