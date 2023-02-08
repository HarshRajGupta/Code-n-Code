#include <bits/stdc++.h>
using namespace std;

void generate() {
    int n = (1e3) * 5, m = 99999999;
    cout << n << '\n';
    for (int i = 0; i < n; ++i) cout << rand() % m << ' ';
    cout << '\n';
    // for (int i = 0; i < n; ++i) {
    //     if (i & 1) {
    //         cout << "2 " << rand() % n << '\n';
    //     } else cout << "1 1 " << n << '\n';
    // }
}

signed main() {
#ifdef __TAG1
    __TAG1
#endif
    srand(time(0));
    int testCase = 1; std::cout << testCase << '\n';
    while (testCase--) generate(), std::cout << '\n';
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}
