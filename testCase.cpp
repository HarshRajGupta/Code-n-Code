#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 100;
    vector<int> arr(n);
    int x = abs(rand()) % 100000000, y = 10;
    for (int i = 0; i < n; ++i) {
        arr[i] = (x+ (abs(rand()) % y));
    }
    int l = abs(rand()) % n, r = abs(rand()) % n;
    while (l == r) {
        l = abs(rand()) % n, r = abs(rand()) % n;
    }
    cout << n << "\n";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    cout <<  "\n" << arr[l] << " " << arr[r] << "\n";
}

signed main(int argc, char const *argv[]) {
    int testCase = 1000;
    cout << 1000 << "\n";
    // srand(time(NULL));
    while (testCase--)
        solve();
    return 0;
}