#include <bits/stdc++.h>
using namespace std;

#define _int long long
#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
const uint64_t MOD = 1e9 + 7, mod = 998244353;

class Solution {
public:
    void test(void) {
        srand(time(0));
        // int r = ((rand() % mod)*(rand() % MOD)%rand())*rand();
        // srand(time(new long(r)));
        if (rand() & 1) {
            srand(time(new long(rand())));
            srand(time(new long(rand()/rand())));
        } else {
            srand(time(new long(rand()+rand())));
            srand(time(new long(rand()*rand())));
        }
        int n = 10;
        std::vector<int> arr(n);
        _for(i, n) arr[i] = rand()*rand();
        debug(arr)
    }
};

#ifdef __TEST__
__TEST__
#endif