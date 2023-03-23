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

void quickSort(const std::vector<int> &v) {
    if (v.size() <= 1) return;
    std::vector<int> left, right;
    int pivot = v[rand() % v.size()];
    for (int i = 1; i < v.size(); i++) {
        if (v[i] < pivot) left.push_back(v[i]);
        else right.push_back(v[i]);
    }
    quickSort(left);
    quickSort(right);
    std::vector<int> sorted;
    sorted.insert(sorted.end(), left.begin(), left.end());
    sorted.push_back(pivot);
    sorted.insert(sorted.end(), right.begin(), right.end());
}

void solve(void) {
    int n = 1e6;
    std::vector<int> arr(n);
    _for(i, n) arr[i] = rand();
    sort(all(arr));
}

signed main(void) {__SOLVE__}