#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

vector<int> fact(27, 1), invFact(27 + 7);
const int invMod(int n, const int MOD = 1e9 + 7) {
    int ans = 1, expo = MOD - 2; n %= MOD;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        expo >>= 1;
    }
    return ans;
}

const int MOD = 1e9 + 7;
void preCom() {
    invFact[0] = invFact[1] = invMod(1);
    for (int i = 2; i <= 26; ++i) {
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
        invFact[i] = invMod(fact[i]);
    }
    debug(fact)
}

int nCr(int n, int r) {
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p % MOD;
}
class Solution {


public:
    int ans(string s, int k) {
        vector<int> arr(26);
        for (auto &i : s) {
            ++arr[i - 'a'];
        }
        sort(arr.begin(), arr.end(), greater<int>());
        set<int, greater<int>> a;
        map<int, int> mp;
        for (auto &i : arr) {
            ++mp[i];
            a.insert(i);
        }
        int ans = 1, ele = k;
        for (auto &i : a) {
            debug(ans, i, mp[i], ele)
            if (!i) break;
            if (mp[i] <= ele) {
                for (int j = 0; j < mp[i]; ++j) {
                    ans = (ans * 1ll * i) % MOD;
                }
                ele -= mp[i];
            } else {
                debug(nCr(mp[i], ele))
                ans = (ans * 1ll * nCr(mp[i], ele)) % MOD;
                break;
            }
        }
        return ans;
    }
    void test() {
        preCom();
        string z = "abcdefghijjj";
        cout << ans(z, 8);
    }
    Solution() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif