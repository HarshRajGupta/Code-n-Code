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
    // map<int, map<int, int>> zp;
    if (k == 0 || nums.size() == 0) return 0;
    if (k == 1 && nums.size() == 1) return nums[0];
    xHeap<pair<int, int>> mpp;
    for (int i = 0; i < nums.size(); ++i) {
        mpp.push({nums[i], i});
    }
    int left = nums.size() - (k + k - 1);
    vector<int> visited(nums.size());
    for (int i = 0; i < left; ++i) {
        visited[mpp.top().second] = 1;
        mpp.pop();
    }
    // debug(visited)
    int p = 0, MAX = 0;
    while (p < nums.size()) {
        // mp.clear();
        int l = p, r = p;
        vector<int> z;
        while (l < nums.size() && visited[l]) {
            ++l;
            ++r;
        }
        while (r < nums.size() && visited[r] == 0) {
            z.push_back(nums[r]);
            ++r;
        }
        p = r;
        MAX = max(MAX, res(z, (z.size() + 1) / 2));
        // MAX = max(MAX, ans(z, (z.size() + 1) / 2, 0, 0));
    }
    return MAX;
}

void solve(void) {
    cout << res({2, 7, 9, 3, 1}, 2);
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