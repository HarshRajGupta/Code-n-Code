#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

vector<int> fact(1e5 + 7, 1), invFact(1e5 + 7);
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
    for (int i = 2; i < 1e5 + 7; ++i) {
        fact[i] = fact[i] * fact[i - 1] % MOD;
        invFact[i] = invMod(fact[i]);
    }
}

const nCr(int n, int r) {
    if (n == r || r == 0) return 1;
    return (((fact[n] * fact[r]) % MOD) * invFact[n - r]) % MOD;
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
                    ans = (ans * i) % MOD;
                }
                ele -= mp[i];
            } else {
                debug(nCr(mp[i], ele))
                ans = (ans * nCr(mp[i], ele)) % MOD;
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