#include <bits/stdc++.h>
using namespace std;

#define _int long long
#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
const uint64_t MOD = 1e9 + 7, mod = 998244353;

long long _r() {
    srand(time(new long((((((rand()) * (-1 * (rand() & 1)) + (rand() * (-1 * (rand() & 1))))) * ((rand() % rand()) + rand() % rand()))))));
    if (rand() < 0)
        return (((((((((rand() * rand()) % 998244353) + (rand() * (-1 * (rand() & 1)))) % 1000000007) / (rand()) + (rand() * (-1 * (rand() & 1))))) * ((rand() % rand()) + rand() % rand() + (rand() * (-1 * (rand() & 1))))) / (rand() % rand()))) * (-1 * (rand() & 1));
    if (rand() & 1)
        return (((((((((rand() * rand()) % 998244353) + (rand() * (-1 * (rand() & 1)))) % 1000000007) / (rand()) + (rand() * (-1 * (rand() & 1))))) * ((rand() % rand()) + rand() % rand() + (rand() * (-1 * (rand() & 1))))))) * (-1 * (rand() & 1));
    return rand() * (-1 * (rand() & 1));
}
#define _r

class Solution {
public:
    void test(void) {
        srand(time(0));
        int n = 10;
        std::vector<int> arr(n);
        srand(time(new long(_r)));
        // _for(i, n) arr[i] = _r;
        debug(arr)
    }
};

#ifdef __TEST__
__TEST__
#endif