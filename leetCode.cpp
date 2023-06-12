#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>> mat) {
        for (int i = 0; i < arr.size(); ++i) {
            int z = i;
            while (arr[z] > 0) {
                debug(z)
                arr[arr[z] - 1] = (z + 1) * -1;
                z = arr[z] - 1;
            }
        }
        debug(arr)
        return 0;
    }
    void test() {
        std::vector<int> v = {1, 3, 4, 2};
        firstCompleteIndex(v, {});
    }
};

#ifdef __TEST__
__TEST__
#endif