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

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), MAX = nums[nums.size() - 1];
    set<int> mini;
    for (int i = n - 1; i >= 0; --i) {
        mini.insert(nums[i]);
        if (nums[i] < MAX) {
            auto t = mini.upper_bound(nums[i]);
            debug(*t)
            nums[i] = *t;
            mini.erase(t);
            debug(mini)
            for (auto j : mini) {
                nums[++i] = j;
            }
            return;
        }
        MAX = max(MAX, nums[i]);
    }
    debug(mini)
    int i = 0;
    for (auto j : mini) {
        nums[i++] = j;
    }
}
void solve(void) {
    v<int> m = {5, 1, 1};
    nextPermutation(m);
    for (auto i : m) {
        cout << i << " ";
    }
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