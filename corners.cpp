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

int count(v<v<pair<int, int>>> &arr, v<int> &ak, int pos, int x) {
    int ct = 0;
    _for(i, sz(arr)) {
        int mark = 1;
        _for(j, sz(arr[i])) {
            if ((arr[i][j].ft > pos && arr[i][j].ft < pos + x) || (arr[i][j].sd > pos && arr[i][j].sd < pos + x) || (arr[i][j].ft <= pos && arr[i][j].sd >= pos + x)) {
                mark = 0;
                ak[i]++;
            }
        }
        if (mark)
            ct++;
    }
    return ct;
}

void solve(void) {
    int n, k, x, d, m; cin >> n >> k >> x >> d >> m;
    v<v<pair<int, int>>> arr(n);
    _for(i, m) {
        int p, a, b; cin >> p >> a >> b;
        arr[p - 1].push_back({a, b});
    }
    int MAX = m;
    _for(i, d - x) {
        v<int> ak(n);
        int cnt = count(arr, ak, i, x), cancel = 0;
        if (cnt >= k) {
            cout << 0;
            return;
        }
        debug(i, cnt)
        sort(all(ak));
        _for(j, k) {
            cancel += ak[j];
        }
        MAX = min(MAX, cancel);
    }
    cout << MAX;
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