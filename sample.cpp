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

int binarySearch(std::vector<int> arr, int target) {
    int l = 0, r = (arr.size() - 1);
    if (r == -1)
        return -1;
    while (l < r) {
        int mid = ((l + r) / 2);
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            r = (mid - 1);
        else
            l = (mid + 1);
    }
    return ((arr[l] == target) ? l : ((arr[r] == target) ? r : -1));
}

v<int> p;
std::map<int, bool> seive(int n = 100007) {
    debug(n)
    std::map<int, bool> prime;
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    for (int i = 2; (i * i) <= n; ++i) {
        if (isPrime[i]) {
            p.push_back(i);
            prime[i] = true;
            for (int j = (i * i); j <= n; j += i) isPrime[j] = false;
        }
    }
    return prime;
}

void solve(void) {
    /* Code */
    auto prime = seive();
    int pos = 0, cnt = 0;
    for (auto i : prime) {
        if (i.ft != p[pos++]) {
            debug(i) cnt++;
        }
    }
    debug(p)
    cout << cnt << " " << sz(p);
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