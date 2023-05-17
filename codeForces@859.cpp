#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__ ios_base::sync_with_stdio(0);cin.tie(0);int t;cin>>t;while(t--)solve(),cout<<'\n';return 0;
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)
#define bw(i, n) for(int32_t i = n; i >= 0; --i)

template <class T> using v = std::vector<T>;
template <class T> using maxHeap = std::priority_queue<T>;
template <class T> using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve(void) {
    int n; cin >> n;
    v<int> arr(n);
    _for(i, n) cin >> arr[i];
    sort(all(arr));
    if (arr[0] != 1) {
        cout << "NO";
        return;
    }
    int maxSum = 1;
    rep(i, 1, n) {
        if (maxSum < arr[i]) {
            cout << "NO";
            return;
        }
        maxSum += arr[i];
    }
    cout << "YES";
}

signed main(void) {__MAIN__}