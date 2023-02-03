// #include <bits/stdc++.h>
// using namespace std;

// void generate() {
//     int n = (1e5) * 2, m = 1e3; cout << n  << ' ' << n << '\n';
//     for (int i = 0; i < n; i++) {
//         cout << (rand() % m) << ' ';
//     }
//     for (int i = 0; i < n; ++i) {
//         if (i & 1) {
//             cout << "2 " << rand() % n << '\n';
//         } else cout << "1 1 " << n << '\n';
//     }
// }

// signed main() {
// #ifdef __TAG1
//     __TAG1
// #endif
//     srand(time(0));
//     int testCase = 1; std::cout << testCase << '\n';
//     while (testCase--) generate(), std::cout << '\n';
// #ifdef __TAG2
//     __TAG2
// #endif
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int sum_of_digits[MAXN];
bool vis[MAXN];

int main() {
    int t, n, q;
    cin >> t >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int num = a[i];
        while (num > 9) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        sum_of_digits[i] = num;
    }
    while (q--) {
        int t, l, r;
        cin >> t >> l;
        if (t == 1) {
            cin >> r;
            for (int i = l - 1; i < r; i++) {
                if (!vis[i]) {
                    vis[i] = true;
                    a[i] = sum_of_digits[i];
                }
            }
        } else {
            cout << a[l - 1] << endl;
        }
    }
    return 0;
}
