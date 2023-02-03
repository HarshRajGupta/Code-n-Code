#include <bits/stdc++.h>
using namespace std;

void generate() {
    int n = (1e5) * 5, m = 1e3; cout << n << '\n';
    for (int i = 0; i < n; i++) {
        if (rand() % 2)
            cout << (rand() % m) << ' ';
        else cout << (rand() % m) * -1 << ' ';
    }
}

signed main() {
#ifdef __TAG1
    __TAG1
#endif
    srand(time(0));
    int testCase = 0; std::cout << testCase << '\n';
    while (testCase--) generate(), std::cout << '\n';
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}