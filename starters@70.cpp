#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

#ifndef __RUN
#define __RUN solve(), std::cout << '\n'
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int32_t i = (int32_t)n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m; cin >> n >> m;
    v<int> t(m), ty(m);
    _for(i, m) cin >> t[i];
    _for(i, m) cin >> ty[i];
    int score = 0, a = 0, b = 0;
    if (ty[0] == 1) {
        if (t[0] & 1) {
            a = (t[0] / 2) + 1;
            b = (t[0] / 2);
        } else {
            a = (t[0] / 2) + 1;
            b = (t[0] / 2) - 1;
        }
    }
    else {
        if (t[0] & 1) {
            a = (t[0] / 2);
            b = (t[0] / 2) + 1;
        } else {
            a = (t[0] / 2) - 1;
            b = (t[0] / 2) + 1;
        }
    }
    rep(i, 0, m) {
        if (ty[i] == 1) {
            if (a > b) score++;
            else {
                a = 0;
                b = 0;
            }
        } else {
            if (a < b) score++;
            else {
                a = 0;
                b = 0;
            }
        }
        if (a == b) a = 0, b = 0;
        if (i != m - 1) {
            int tot = t[i + 1] - t[i] + a + b, A = 0, B = 0, dif = (t[i + 1] - t[i]);
            if (ty[i + 1] == 1) {
                if (tot & 1) {
                    A = (tot / 2) + 1;
                    B = (tot / 2);
                } else {
                    A = (tot / 2) + 1;
                    B = (tot / 2) - 1;
                }
                if (A >= a && B >= b) {
                    a = A;
                    b = B;
                } else if (a > b) {
                    if (a - b == 1) {
                        if (dif & 1) {
                            a += dif / 2 + 1;
                            b += dif / 2;
                        } else {
                            a += dif / 2;
                            b += dif / 2;
                        }
                    } else if (a - b == 2) {
                        if (dif & 1) {
                            a += dif / 2;
                            b += dif / 2 + 1;
                        } else {
                            a += dif / 2;
                            b += dif / 2;
                        }
                    }
                }
                else {
                    if (b - a <= dif) continue;
                    int t = b - a;
                    a += t;
                    dif -= t;
                    if (dif & 1) {
                        a += dif / 2 + 1;
                        b += dif / 2;
                    } else {
                        a += dif / 2 + 1;
                        b += dif / 2 - 1;
                    }
                }
            } else {
                if (tot & 1) {
                    A = (tot / 2);
                    B = (tot / 2) + 1;
                } else {
                    A = (tot / 2) - 1;
                    B = (tot / 2) + 1;
                }
                if (A >= a && B >= b) {
                    a = A;
                    b = B;
                } else if (b > a) {
                    if (b - a == 1) {
                        if (dif & 1) {
                            b += dif / 2 + 1;
                            a += dif / 2;
                        } else {
                            a += dif / 2;
                            b += dif / 2;
                        }
                    } else if (b - a == 2) {
                        if (dif & 1) {
                            a += dif / 2 + 1;
                            b += dif / 2;
                        } else {
                            a += dif / 2;
                            b += dif / 2;
                        }
                    }
                }
            }
        }
    }
    cout << score;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs = 1u;
    cin >> tCs;
    for (uint32_t tC = 0u; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}