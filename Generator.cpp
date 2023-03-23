#include <bits/stdc++.h>
using namespace std;

#define int long long
#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)

class Solution {
public:
    void test() {
        srand(time(0));
        int n = 1e6;
        vector<int> arr(n);
        _for(i, n) arr[i] = rand();
        _for(i, n) cout << arr[i];
    }
};

#ifdef __TEST__
__TEST__
#endif