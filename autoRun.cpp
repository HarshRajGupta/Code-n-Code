#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
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

int findNonMultiples(int arr[],
                     int n, int k)
{
    // Stores all unique multiples
    set<int> multiples;
    // Iterate the array
    for (int i = 0; i < n; ++i) {
        debug(i)
        if (multiples.find(arr[i])
                == multiples.end()) {

            for (int j = 1;
                    j <= k / arr[i]; j++) {
                multiples.insert(arr[i] * j);
            }
        }
    }

    // Returning only the count of
    // numbers that are not divisible
    // by any of the array elements
    return k - multiples.size();
}

// Function to count the total values
// in the range [L, R]
int countValues(int x, int y, int r) {
    int arr[] = {x, y};
    int n = 2;
    return findNonMultiples(arr, n, r);
}
int xNotY(int x, int y, int n) {
    int divX = n / x;
    int divLCM = n / ((x * y) / __gcd(x, y));
    return (divX - divLCM);
}
int notXY(int d, int c, int b) {
    int x = b / c;
    int y = b / d;
    int k = (c * d) / __gcd(c, d);
    int z = b / k;
    debug(b, x, y, k, z)
    return b + 1 - x - y + z;
}
int tot1(int x, int y, int n) {
    int ans = xNotY(x, y, n) + xNotY(y, x, n) + notXY(x, y, n);
    cout << n << " " << ans << " " << xNotY(x, y, n) << " " << xNotY(y, x, n) << " " << notXY(x, y, n) << endl;
    return ans;
}
int tot(int x, int y, int n) {
    int ans = xNotY(x, y, n) + xNotY(y, x, n) + notXY(x, y, n);
    // cout << n << " " << ans << " " << xNotY(x, y, n) << " " << xNotY(y, x, n) << " " << notXY(1, n, x, y) << endl;
    return ans;
}

int minimizeSet(int d1, int d2, int u1, int u2) {
    int l = 0, r = INT_MAX;
    while (l <= r) {
        int mid = (l + r) / 2;
        debug(l, r)
        int ans = tot1(d1, d2, mid);
        if (ans == u1 + u2) {
            l = mid;
            break;
        }
        else if (ans > u1 + u2) {
            r = mid - 1;
        } else l = mid + 1;
    }
    int ans = max(l, r);
    // cout << l << " " << r << endl;
    for (int i = ans - 1; i >= 1; --i) {
        // cout << i << endl;
        int a = tot(d1, d2, i);
        if (a >= u1 + u2)
            ans = i;
        else break;
    }
    return ans;
}
void solve(void) {
    /* Code */
    cout << minimizeSet(2, 4, 8, 2);
    // cout << 2;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}