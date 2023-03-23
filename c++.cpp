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

void mergeSort(v<int> &arr, int i , int j) {
    if (i >= j) return;
    int mid = (i + j) / 2;
    mergeSort(arr, i, mid);
    mergeSort(arr, mid + 1, j);
    int p1 = i, p2 = mid + 1;
    v<int> tmp;
    while (p1 <= mid && p2 <= j) {
        if (arr[p1] < arr[p2]) {
            tmp.push_back(arr[p1++]);
        } else {
            tmp.push_back(arr[p2++]);
        }
    }
    while (p1 <= mid) tmp.push_back(arr[p1++]);
    while (p2 <= j) tmp.push_back(arr[p2++]);
    _for(i, tmp.size()) arr[i + p1] = tmp[i];
}

void solve(void) {
    int n = 1e6;
    std::vector<int> arr(n);
    _for(i, n) arr[i] = rand();
    // mergeSort(arr, 0, n-1);
}

signed main(void) {__SOLVE__}