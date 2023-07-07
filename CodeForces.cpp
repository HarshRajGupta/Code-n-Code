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
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = vector<T>;
template<class T>using maxHeap = priority_queue<T>;
template<class T>using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int N = 1e10 + 7;

map<int, bool> snowFlake;

void solve() {
    int n; cin >> n;
    if (snowFlake.find(n) != snowFlake.end())
        cout << "YES";
    else cout << "NO";
}


void preCompute() {
    for (int32_t i = 2; i * 1ll * i < N; ++i) {
        // if (snowFlake.find(i) != snowFlake.end()) continue;
        int prev = i * i, dec = N / i;
        for (int j = 1 + i + prev; j < N; j += prev) {
            snowFlake[j] = true;
            if ((dec - prev) < j) break;
            prev *= i;
        }
    }
    debug(snowFlake.size())
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

/**
 * @ScratchPad
 */

__MAIN__