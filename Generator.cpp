#include <bits/stdc++.h>
using namespace std;

#define _int long long
#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
const uint64_t MOD = 1e9 + 7;

class Solution {
public:
    void test(void) {
        time_t *t = new time_t;
        cout << (time(t)%MOD)*(time(t)%MOD) << endl;
        int n = 10;
        std::vector<int> arr(n);
        _for(i, n) arr[i] = rand();
        debug(arr)
    }
};

#ifdef __TEST__
__TEST__
#endif