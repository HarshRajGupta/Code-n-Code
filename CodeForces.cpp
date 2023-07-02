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

void maxSum(vector<int> &arr) {
    sort(all(arr), greater<int>());
    int sum = 0;
    foreach (i, arr) {
        sum += i;
        i = sum;
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n);
    vector<int> a(n);
    foreach(i, a) {cin >> i; --i;}
    set<int> s;
    _for(i, n) {
        int temp; cin >> temp;
        arr[a[i]].push_back(temp);
        s.insert(a[i]);
    }
    foreach (i, s) {
        maxSum(arr[i]);
    }
    _for(i, n) {
        int ans = 0;
        vector<int> eraseThese;
        foreach (j, s) {
            if (sz(arr[j]) < (i + 1)) {
                eraseThese.push_back(j);
                continue;
            } else {
                ans += arr[j][sz(arr[j]) - (sz(arr[j]) % (i + 1)) - 1];
            }
        }
        foreach (j, eraseThese) {
            s.erase(j);
        }
        // debug(i, s, ans, arr);
        cout << ans << ' ';
    }
}

void preCompute() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush();
}

/**
 * @ScratchPad
 */

__MAIN__