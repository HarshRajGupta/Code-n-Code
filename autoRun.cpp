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
// #define N std::cout << "NO";

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

class Solution {
public:
    long long maximumMultiple(int N, int A[]) {
        // code here
        maxHeap maxi, ans;
        minHeap mini, pos, neg;
        for (int i = 0; i < N; ++i) {
            if (A[i] < 0) neg.push(A[i]);
            else pos.push(A[i]);
        }
        for (int i = 0; i < N / 2; ++i) {
            debug(i, pos, neg, maxi, mini)
            int m = neg.empty() || pos.empty();
            if (m == 0) {
                ans.push(pos.top() * neg.top());
                pos.pop();
                neg.pop();
            }
            else {
                while (!pos.empty()) {
                    maxi.push(pos.top());
                    mini.push(pos.top());
                    pos.pop();
                }
                while (!neg.empty()) {
                    maxi.push(-1*neg.top());
                    mini.push(-1*neg.top());
                    neg.pop();
                }
                ans.push(maxi.top() * mini.top());
                maxi.pop();
                mini.pop();
            }
        }
        return ans.top();
        // int64_t MAX = mini.top();
        // while(!mini.empty()) {
        //     MAX = max(mini.top(), MAX);
        //     mini.pop();
        // }
        // return MAX;
    }
};
void solve(void) {
    /* Code */
    Solution a;
    cout << a.maximumMultiple(16, new int[16] { 0, -9, 13, 18, -1, 3, -17, 9, -13, 7, 6, -11, 6, -4, 13, -5});
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