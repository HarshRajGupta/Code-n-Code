#include <bits/stdc++.h>
using namespace std;

const long long f = 1e5 + 7;
const long long n = 1e9 + 7;
const long long e = 1e18 + 1;

void generate() {
    int n = 100; cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        cout << rand() % 10 << ' ';
    }
    cout << '\n';
}

signed main() {
    srand(time(0));
    int testCase = 10; cout << testCase << endl;
    while (testCase--) generate();
    return 0;
}