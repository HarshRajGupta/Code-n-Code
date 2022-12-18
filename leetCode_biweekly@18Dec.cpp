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

class Solution {
    vector<int> p;
    vector<int> seive(int n) {
        vector<int> prime(n + 1, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                p.push_back(i);
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = 0;
                }
            }
        }
        return prime;
    }
public:
    int smallestValue(int n) {
        auto pr = seive(n);
        vector<int> cal(1e5 + 7, -1);
        int MIN = n;
        debug(p, pr)
        while (!pr[n]) {
            int t = n, s = 0;
            while (!pr[t]) {
                for (auto i : p) {
                    if (t % i == 0) {
                        t /= i;
                        s += i;
                        break;
                    }
                }
            }
            MIN = min(n, s + t);
            if (cal[s + t]) return MIN;
            cal[n] = 1;
            n = s + t;
        }
        return n;
    }
};

void solve(void) {
    /* Code */
    Solution s;
    cout << s.smallestValue(4);
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