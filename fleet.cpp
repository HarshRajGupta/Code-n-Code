#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        ++mp[m];
    }
    int ans = 0;
    for (auto i : mp) {
        int f = i.second;
        if (f == 1) {
            cout << -1 << '\n';
            return;
        }
        else if (f % 3 == 0) {
            ans += f / 3;
        } else if (f % 3 == 2) {
            ans += f / 3;
            ++ans;
        } else {
            ans += (f / 3);
            ++ans;
        }
    }
    cout << ans << '\n';
}

signed main() {
    int testCase; cin >> testCase;
    while (testCase--) solve();
    return 0;
}