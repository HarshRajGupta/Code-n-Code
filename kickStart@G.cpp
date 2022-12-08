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

// #include <bits/stdc++.h>
// using namespace std;
int deleteProducts(const vector<int> &ids, int m) {
    map<int, int> mp;
    for (uint i = 0;  i < ids.size(); ++i) mp[ids[i]]++;
    vector<int> store;
    for (auto i : mp) {
        store.push_back(i.second);
    }
    debug(mp)
    sort(store.begin(), store.end());
    reverse(store.begin(), store.end());
    // debug(store)
    int ans = 0;
    debug(m, sz(ids) - m)
    m = sz(ids) - m;
    // debug(m)
    for (int i = 0; i < sz(store) && m > 0; ++i) {
        ans++;
        m -= store[i];
    }
    return ans;
}

void solve(void) {
    /* Code */
    int n, m; cin >> n;
    v<int> arr(n);
    _for(i, n) cin >> arr[i];
    cin >> m;
    cout << deleteProducts(arr, m);
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