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
        minHeap mini;
        for (int i = 0; i < N; ++i) {
            maxi.push(A[i]);
            mini.push(A[i]);
        }
        int m = 0;
        for (int i = 0; i < N / 2; ++i) {
            int64_t minii = mini.top(), maxii = maxi.top();

            if (minii <= 0 && maxii > 0 || minii < 0 && maxii <= 0) {
                mini.pop();
                maxi.pop();
                ans.push(minii * maxii);
                // maxi.push(minii*maxii);
                //
                cout << minii << " " << maxii << endl;
                m = 0;
            } else  if (minii > 0 && maxii > 0) {
                mini.pop();
                maxii = mini.top();
                mini.pop();
                ans.push(minii * maxii);
                cout << minii << " " << maxii << endl;
                m = 1;
                // }
            } else {
                maxi.pop();
                minii = maxi.top();
                maxi.pop();
                ans.push(minii * maxii);
                cout << minii << " " << maxii << endl;
                m = 2;
            }
        }
        cout << m;
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
    cout << a.maximumMultiple(9, new int[8]{-11, 8, 10, 9, -19, -8, 19, -14});
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