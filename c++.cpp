#ifdef ONLINE_JUDGE
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __RUN
#define __RUN solve()
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
    v<v<int>> mp(n, v<int>(2)), ans(n, v<int>(2));
    _for(i, n) {
        cin >> arr[i];
        mp[i] = {arr[i], i};
    }
    sort(all(mp));
    int prev = 0, MAX = 0;
    _for(i, n) {
        if (arr[i] <= MAX) continue;
        MAX = arr[i];
        while (prev < n && mp[prev][0] < MAX) {
            ans[mp[prev][1]][0] = i;
            ++prev;
        }
    }
    prev = 0, MAX = 0;
    bw(i, n - 1) {
        if (arr[i] <= MAX) continue;
        MAX = arr[i];
        while (prev < n && mp[prev][0] < MAX) {
            ans[mp[prev][1]][1] = i;
            ++prev;
        }
    }
    _for(i, n) {
        if (ans[i][0] > i || arr[ans[i][0]] <= arr[i]) cout << "-1 ";
        else cout << arr[ans[i][0]] << ' ';
        if (ans[i][1] < i || arr[ans[i][1]] <= arr[i]) cout << "-1\n";
        else cout << arr[ans[i][1]] << ln;
    }
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