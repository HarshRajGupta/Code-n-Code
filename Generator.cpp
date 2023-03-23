#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
const uint64_t MOD = 1e9 + 7;

class Solution {
public:
    void test(void) {
        srand(time(0));
        int n = 1e7;
        vector<int> arr(n);
        _for(i, n) arr[i] = rand();
        // _for(i, n) cout << arr[i] << ' ' ;
    }
};

#ifdef __TEST__
__TEST__
#endif