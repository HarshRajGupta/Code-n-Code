#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
    map<string, map<int, int>> cache;
    bool isPunishable(string s, int pos, int sum) {
        if (sum < 0)
            return false;
        if (cache[s][sum] == -1)
            return false;
        if (cache[s][sum] == 1)
            return true;
        if (pos == s.size()) {
            return sum == 0;
        }
        for (int i = 1; i <= min((int)s.size() - pos, (int)log10(sum + 2) + 1); ++i) {
            if (isPunishable(s, pos + i, sum - stoi(s.substr(pos, i))))
                return cache[s][sum] = 1;
        }
        cache[s][sum] = -1;
        // debug(s, sum)
        return false;
    }
    string intToString(int n) {
        string s;
        while (n) {
            s += n % 10 + '0';
            n /= 10;
        }
        reverse(s.begin(), s.end());
        // debug(n, s)
        return s;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int z = i * i;
            if (isPunishable(intToString(z), 0, i)) {
                ans += z;
                cout << i << ' ';
            }
        }
        return ans;
    }
    void test() {
        cout << punishmentNumber(379) << endl;
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif