#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3", "fast-math", "unroll-loops", "no-stack-protector", \
                         "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "sse4", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __SOLVE__
#define __SOLVE__   \
    signed main() { \
        solve();    \
        return 0;   \
    }
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)

template <class T>
using v = vector<T>;
template <class T>
using maxHeap = priority_queue<T>;
template <class T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int maxConcurrentJobs(vector<int> &jobStartTimes, vector<int> &jobEndTimes) {
	int ans = 0;
	map<int, int> mp;
	for (int i = 0; i < jobStartTimes.size(); i++) {
		mp[jobStartTimes[i]]++;
		mp[jobEndTimes[i] + 1]--;
	}
	int curr = 0;
	for (auto &i : mp) {
		curr += i.second;
		ans = max(ans, curr);
	}
	return ans;
}

void solve(void) {
    int n; cin >> n;
    v<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    	cout << maxConcurrentJobs(a, b) << endl;

}

/**
 * @ScratchPad
 */

__SOLVE__