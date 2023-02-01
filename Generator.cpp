#include <bits/stdc++.h>
using namespace std;

void generate() {
    cout << "100\n";
    for (int i = 0; i < 100; ++i) {
        cout << rand() << ' ';
    }
    cout << '\n';
}

signed main() {
    int testCase = 10; cout << testCase << endl;
    while (testCase--) generate();
    return 0;
}