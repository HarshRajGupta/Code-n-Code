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
#define __RUN solve(), std::cout << '\n'
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

v<int> longestGoodSequence(vector<int>& array) {
    int n = sz(array);
    // We will keep track of the current good sequence using a stack.
    // The stack will store the indices of the good sequence.
    vector<int> stack;
    _for(i, n) {
        // If the current element is a 1, we can always add it to the good sequence.
        if (array[i] == 1) {
            stack.push_back(i);
        } else {
            // If the current element is a 0, we need to check whether it is part of a good sequence.
            // If it is, we will add it to the good sequence. Otherwise, we will discard it.
            int cnt_ones = 0, cnt_zeros = 0;
            for (int j = i; j < n; j++) {
                if (array[j] == 1) {
                    cnt_ones++;
                } else {
                    cnt_zeros++;
                }
                if (cnt_ones - cnt_zeros == j - i) {
                    stack.push_back(i);
                    break;
                }
            }
        }
    }
    return stack;
}

void solve() {
    /* Code */
    int n; cin >> n;
    v<int> arr(n);
    _for(i, n) cin >> arr[i];
    auto ans = longestGoodSequence(arr);
    cout << sz(ans) << ln;
    _for(i, sz(ans)) cout << ans[i] << " ";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs = 1u;
    cin >> tCs;
    for (uint32_t tC = 0u; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}