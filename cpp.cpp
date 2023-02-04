#include <bits/stdc++.h>
using namespace std;


int ans(vector<string> pixels) {
    vector<int> row(pixels.size()), col(pixels[0].size());
    for (int i = 0; i < pixels.size(); ++i) {
        for (int j = 0; j < pixels[0].size(); ++j) {
            if (pixels[i][j] == '1') {
                ++row[i];
                ++col[j];
            }
        }
    }
    debug(row, col)
    int MAX = 0;
    for (int i = 0; i < pixels.size(); ++i) {
        for (int j = 0; j < pixels[0].size(); ++j) {
            MAX = max(MAX, abs((int)((int)row.size() + (int)col.size() - row[i] - col[j] - row[i] - col[j])));
        }
    }
    return MAX;
}

void solve() {
    int n; cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; ++i) {
        cin >> str[i];
    }
    cout << ans(str);
    // cout << 1;
    debug(str)
}

signed main() {
    int testCase; cin >> testCase;
    while (testCase--) solve();
    return 0;
}