#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3", "fast-math", "unroll-loops", "no-stack-protector", \
                         "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "sse4", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__                           \
    signed main() {                        \
        preCompute();                      \
        signed t;                          \
        cin >> t;                          \
        while (t--) solve(), cout << '\n'; \
        return 0;                          \
    }
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)

template <class T>
using v = vector<T>;
template <class T>
using maxHeap = priority_queue<T>;
template <class T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

vector<int32_t> allPrimes;
vector<bool> sieve(const int32_t n = 1000007) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false, isPrime[1] = false;
    for (int32_t i = 2; (i * i) <= n; ++i)
        if (isPrime[i])
            for (int j = (i * i); j <= n; j += i)
                isPrime[j] = false;
    for (int32_t i = 2; i <= n; ++i)
        if (isPrime[i])
            allPrimes.push_back(i);
    return isPrime;
}

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for (auto &i : allPrimes) {
        if (i * i > n) break;
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) mp[n]++;
    int ans = 1;
    for (auto &i : mp) {
        ans = ans * (i.second + 1) % MOD;
    }
    cout << ans;
}

static void preCompute() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.flush();
    sieve();
}

/**
 * @ScratchPad
 */

__MAIN__