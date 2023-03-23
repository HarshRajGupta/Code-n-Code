#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define r (rand()*rand()%rand()*((rand()%2)?1:-1))

class Solution {
public:
    void test(void) {
        /* test */
        int t = (rand() * rand() % rand() * ((rand() & 1) ? 1 : -1));
        _for(i, 10) cout << r << ' ';
    }
};

#ifdef __TEST__
__TEST__
#endif