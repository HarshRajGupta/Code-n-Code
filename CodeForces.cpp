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

void solve() {
    v<string> s(3);
    foreach(i, s) cin >> i;
    debug(s)
    if ((s[0][0] == s[1][1] == s[2][2]) && (s[0][0] != '.')) {
        cout << s[0][0];
        return;
    }
    if ((s[0][2] == s[1][1] == s[2][0]) && (s[0][2] != '.')) {
        cout << s[0][2];
        return;
    }
    _for(i, 3) {
        debug(s[i][0], s[i][1], s[i][2])
        if ((s[i][0] == s[i][1] == s[i][2]) && (s[i][0] != '.')) {
            cout << s[i][0];
            return;
        }
        debug(s[0][i], s[1][i], s[2][i], (s[0][i] == s[1][i] == s[2][i]), (s[0][i] != '.') )
        if ((s[0][i] == s[1][i] == s[2][i]) && (s[0][i] != '.')) {
            cout << s[0][i];
            return;
        }
    }
    cout << "DRAW";
}

void preCompute() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush();
}

/**
 * @ScratchPad
 */

__MAIN__