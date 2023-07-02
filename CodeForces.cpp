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
    string s; cin >> s;
    int r = 0, ans = 0;
    multiset<char> ms;
    for (int i = 0; i < sz(s); ++i) {
        if (ms.empty()) {
            ms.insert(s[i]);
            r = i;
        } else if (ms.count('?') != ms.size()) {
            ans += sz(ms);
            ms.erase(ms.find(s[i]));
            continue;
        }
        int parity = -1;
        if (s[i] != '?')
            parity = s[i] - '0';

        for (int j = r + 1; j < sz(s); ++j) {
            if (s[j] != '?') {
                if (parity == -1)
                    parity = ((s[j] - '0') ^ ((j - i) & 1));
                else if (parity != ((s[j] - '0') ^ ((j - i) & 1)))
                    break;
            }
            ms.insert(s[j]);
            ++r;
        }
        debug(i, ms)
        ans += sz(ms);
        ms.erase(ms.find(s[i]));
    }
    cout << ans;
}

void preCompute() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush();
}

/**
 * @ScratchPad
 */

__MAIN__