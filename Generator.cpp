#include <bits/stdc++.h>
using namespace std;

void generate() {
    cout << rand();
}

signed main() {
#ifdef __TAG1
    __TAG1
#endif
    srand(time(0));
    int testCase = 10; cout << testCase << '\n';
    while (testCase--) generate(), cout << '\n';
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}