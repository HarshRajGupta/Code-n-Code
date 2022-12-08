#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __RUN
// #define __RUN std::cout << "Case #" << tC << ": ", solve(), std::cout << '\n'
#define __RUN solve(), std::cout << '\n'
#endif

const unsigned long long MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, n) for (auto i = a; i < n; ++i)
#define bw(i, n) for (int i = n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, x;
    cin >> n >> x;
    if (n <= x)
        cout << 1;
    else {
        int count = 0;
        while (n > x) {
            int power = log2(n);
            if (n > x && power == 0) {
                cout << -1;
                return;
            }
            if (power & 1)
                n -= 1 << power;
            else if (power > 0)
                n -= 1 << (power - 1);
            count++;
        }
        if (n != 0)
            count++;
        cout << count;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    int tCs;
    cin >> tCs;
    for (int tC = 0; tC++ < tCs; __RUN)
        ;
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}