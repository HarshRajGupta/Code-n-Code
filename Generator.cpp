#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__ ios_base::sync_with_stdio(0);cin.tie(0);signed t;cin>>t;while(t--)solve(),cout<<'\n';return 0;
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = std::vector<T>;
template<class T>using maxHeap = std::priority_queue<T>;
template<class T>using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

void solve(void) {
    int n; cin >> n;
    v<int> pos, neg, ans;
    _for(i, n) {
        int t; cin >> t;
        if (t > 0) pos.push_back(t);
        else neg.push_back(t);
    }
    sort(all(pos));
    sort(all(neg));
    debug(pos, neg)
    int MAX = pos[pos.size() - 1] - neg[0];
    int i = 0, j = 0, sum = 0, sm = 0;
    while (i < sz(pos) && j < sz(neg)) {
        debug(sum, ans)
        if (sum <= 0) {
            sum += pos[i];
            sm += pos[i];
            if (abs(sm) >= MAX) {
                cout << "NO";
                return;
            }
            ++i;
            ans.push_back(pos[i]);
        } else {
            sum += neg[j];
            ans.push_back(neg[j]);
            sm += neg[j];
            if (abs(sm) >= MAX) {
                cout << "NO";
                return;
            }
            if (sm < 0) sm = 0;
            ++j;
        }
        debug(ans, sum, sm)
    }
    cout << "YES\n";
    debug(ans)
    _for(i, ans.size()) cout << ans[i] << ' ';
}

signed main(void) {__MAIN__}