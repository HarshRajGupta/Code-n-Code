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

#include <algorithm>
#include <cmath>
#include <vector>

std::vector<std::pair<int, int>> divide_into_pairs_with_min_abs_diff(const std::vector<int>& arr) {
    // Sort the array in non-descending order
    std::vector<int> sorted_arr = arr;
    std::sort(sorted_arr.begin(), sorted_arr.end());

    // Initialize the result vector
    std::vector<std::pair<int, int>> pairs;

    // Iterate through the sorted array and add pairs
    for (size_t i = 0; i < sorted_arr.size() - 1; i += 2) {
        pairs.emplace_back(sorted_arr[i], sorted_arr[i + 1]);
    }

    // If there is an odd number of elements, add the first (n - 1) / 2 pairs
    // if (sorted_arr.size() % 2 != 0) {
    //     for (size_t i = 0; i < (sorted_arr.size() - 1) / 2; ++i) {
    //         pairs.emplace_back(sorted_arr[i], sorted_arr[sorted_arr.size() - i - 1]);
    //     }
    // }

    return pairs;
}


void solve(void) {
    v<int> arr = {3, -5, 6, -5, 3};
    auto t = divide_into_pairs_with_min_abs_diff(arr);
    debug(t)
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