#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1e9 + 1, -1);

int ans(int n) {
    // if (n == 1 || n <= 0) return 0;
    if (dp[n] != -1) return dp[n];
    if (n % 6 == 0) return dp[n] = min(ans(n / 2), ans(n / 3)) + 1;
    if (n % 3 == 0) return dp[n] = min(ans(n / 3) + 1, ans(n / 2) + 2);
    if (n % 2 == 0 && (n - 1) % 3 == 0) return dp[n] = min(ans(n / 2) + 1, ans(n / 3) + 2);
    if (n % 2 == 0 && (n - 2) % 3 == 0) return dp[n] = min(ans(n / 2) + 1, ans(n / 3) + 3);
    if ((n - 1) % 6 == 0) return dp[n] = min(ans(n / 2), ans(n / 3)) + 2;
    return dp[n] = ans(n - 1) + 1;
}

void solve() {
    int n; cin >> n;
    cout << ans(n);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    dp[1] = 0, dp[0] = 0;
    uint32_t tCs; cin >> tCs;
    for (uint32_t tC = 0; tC++ < tCs; solve(), std::cout << '\n');
    return 0;
}