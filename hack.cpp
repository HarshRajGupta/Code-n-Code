#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#ifndef __SOLVE__
#define __SOLVE__ ios_base::sync_with_stdio(0);cin.tie(NULL);solve();return 0;
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)
#define bw(i, n) for(int32_t i = n; i >= 0; --i)

template <class T> using v = std::vector<T>;
template <class T> using maxHeap = std::priority_queue<T>;
template <class T> using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int lB(const std::vector<int> &arr, const int t, int l = 0, int r = -1) {
    if (r == -1) r = (arr.size() - 1);
    if (arr[l] >= t) return l - 1;
    if (arr[r] < t) return r;
    int ans = l - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] >= t) r = (mid - 1);
        else ans = mid, l = (mid + 1);
    }
    return ans;
}

void solve(void) {
    int n, m; cin >> n >> m;
    v<int> a(n), prefixSum(n + 1);
    _for(i, n) cin >> a[i];
    sort(all(a));
    _for(i, n) prefixSum[i + 1] = prefixSum[i] + a[i];
    while (m--) {
        int x; cin >> x;
        int ans = lB(a, x);
        cout << (ans + 1)*x  - prefixSum[ans + 1] + prefixSum[n] - (n - ans - 1)*x << ' ';
    }
}

signed main(void) {__SOLVE__}