#include <bits/stdc++.h>
using namespace std;

void generate() {
    int n = (rand() * rand() * 1ll) % (1000000000); cout << n;
    // for (int i = 0; i < n; i++) cout << rand() % n << ' ';
}

signed main() {
#ifdef __TAG1
    __TAG1
#endif
    srand(time(0));
    int testCase = 1000; std::cout << testCase << '\n';
    while (testCase--) generate(), std::cout << '\n';
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}