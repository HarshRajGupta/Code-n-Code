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

int notXY(int a, int b, int c, int d) {
    int x = b / c - (a - 1) / c;
    int y = b / d - (a - 1) / d;
    int k = (c * d) / __gcd(c, d);
    int z = b / k - (a - 1) / k;
    debug(x, y, z, k)
    return b - a + 1 - x - y + z;
}

int findNonMultiples(int arr[],
                     int n, int k)
{
    // Stores all unique multiples
    set<int> multiples;

    // Iterate the array
    for (int i = 0; i < n; ++i) {

        // For finding duplicates
        // only once
        if (multiples.find(arr[i])
                == multiples.end()) {

            // Inserting all multiples
            // into the set
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
int countValues(int x, int y, int r){
    int arr[] = {x, y};
    int n = 2;
    return findNonMultiples(arr, n, r)
           - findNonMultiples(arr, n, 1);
}

void solve(void) {
    /* Code */
    cout << countValues(2, 4, 13);
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