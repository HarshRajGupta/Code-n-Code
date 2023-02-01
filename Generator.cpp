#include <bits/stdc++.h>
using namespace std;

void generate() {
    cout << "100\n";
    for (int i = 0; i < 10; ++i) {
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