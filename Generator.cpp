#include <bits/stdc++.h>
using namespace std;

void generate() {
    int n = 10; cout << n << '\n';
    for (int i = 0; i < n; ++i) {
        cout << rand() % ((int)1e9 + 7) << ' ';
    }
    cout << '\n';
}

signed main() {
#ifdef __TAG1
    __TAG1
#endif
    srand(time(0));
    int testCase = 10; cout << testCase << endl;
    while (testCase--) generate();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}