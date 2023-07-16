#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "sse4", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__ signed main(){preCompute();signed t;cin>>t;while(t--)solve(),cout<<'\n';return 0;}
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)

template<class T>using v = vector<T>;
template<class T>using maxHeap = priority_queue<T>;
template<class T>using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int uB(const std::vector<int> &arr, const int t, int l = 0, int r = -1) {
    if (r == -1) r = (arr.size() - 1);
    if (t < arr[l]) return l;
    if (t > arr[r]) return r + 1;
    int ans = r + 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] <= t) l = (mid + 1);
        else ans = mid, r = (mid - 1);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    v<int> arr(n);
    foreach(i, arr) cin >> i;
    auto a = arr;
    sort(all(arr));
    _for(i, n) {
        cout << n - uB(arr, a[i]) << ' ';
    }
}

static void preCompute() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush();
}

/**
 * @ScratchPad
 */

__MAIN__