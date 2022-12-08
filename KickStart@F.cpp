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
#define __RUN std::cout << "Case #" << tC << ": ", solve(), std::cout << '\n'
#endif

const unsigned long long MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, n) for (auto i = a; i < n; ++i)
#define bw(i, n) for (int i = n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void levelCalc(const v<v<int>> &tree, v<int> &levels, v<v<int>> &levelRec, int par, int pos) {
    if (levels[pos] != 0)
        return;
    levels[pos] = par + 1;
    levelRec[levels[pos]].push_back(pos);
    _for(i, sz(tree[pos])) {
        levelCalc(tree, levels, levelRec, levels[pos], tree[pos][i]);
    }
}

void solve(void) {
    int n, q; cin >> n >> q;
    v<v<int>> tree(n);
    _for(i, n-1) {
        int x, y; cin >> x >> y;
        tree[x - 1].push_back(y - 1);
        tree[y - 1].push_back(x - 1);
    }
    debug(tree)
    v<int> levels(n, 0);
    v<v<int>> levelRec(n+7);
    levelCalc(tree, levels, levelRec, 0, 0);
    _for(i, q) {
        int temp; cin >> temp;
    }
    int cap = 0, count = 0, i = 1;
    while (cap <= q && i <= n) {
        cap += sz(levelRec[i]);
        if (cap <= q)
            count += sz(levelRec[i]);
        i++;
    }
    cout << count;
}

signed main(const signed argc, const char **argv) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    int tCs; cin >> tCs;
    for (int tC = 0; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}