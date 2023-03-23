#include <bits/stdc++.h>
using namespace std;

#define _int long long
#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
const uint64_t MOD = 1e9 + 7, mod = 998244353;

class Solution {
public:
    void test(void) {
        srand(time(0));
        int n = 10;
        std::vector<int> arr(n);
        int _rand = ((((((rand() * rand()) % 998244353) + (rand() * (-1 * (rand() & 1)))) % 1000000007) / (rand()) + (rand() * (-1 * (rand() & 1))))) * ((rand() % rand()) + rand() % rand() + (rand() * (-1 * (rand() & 1))));
        srand(time(new long(_rand)));
        _rand = ((((((rand() * rand()) % 998244353) + (rand() * (-1 * (rand() & 1)))) % 1000000007) / (rand()) + (rand() * (-1 * (rand() & 1))))) * ((rand() % rand()) + rand() % rand() + (rand() * (-1 * (rand() & 1))));
        _for(i, n) arr[i] = _rand;
        debug(arr)
    }
};

#ifdef __TEST__
__TEST__
#endif