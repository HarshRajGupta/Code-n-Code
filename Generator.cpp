#include <bits/stdc++.h>
using namespace std;

#define _int long long
#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
const uint64_t MOD = 1e9 + 7;

class Solution {
public:
    void test(void) {
        long int *z = new long(INT_MAX);
        // time_t *t = time_t(z);
        cout << (time(new long(INT_MAX))%MOD)*(time(new long(INT_MIN))%MOD) << endl;
        int n = 10;
        std::vector<int> arr(n);
        _for(i, n) arr[i] = rand();
        debug(arr)
    }
};

#ifdef __TEST__
__TEST__
#endif