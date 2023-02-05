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

int res(const vector<int>& nums, int k) {
    xHeap<pair<int, int>> mp;
    for (int i = 0; i < nums.size(); ++i) {
        mp.push({nums[i], i});
    }
    int left = nums.size() - (k + k - 1);
    vector<int> visited(nums.size());
    for (int i = 0; i < left; ++i) {
        visited[mp.top().second] = 1;
        mp.pop();
    }
    debug(visited)
    int p = 0, MAX = 0;
    while (p < nums.size()) {
        if (visited[p]) {
            ++p;
        } else {
            MAX = max(MAX, nums[p]);
            p += 2;
        }
    }
    return MAX;
}

void solve(void) {
    cout << res({2,7,9,3,1}, 2);
}

signed main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}