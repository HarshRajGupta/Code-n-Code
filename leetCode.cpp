#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>> mat) {
        for (int i = 0; i < arr.size(); ++i) {
            int x = i, y = arr[i];
            while (y > 0) {
                int X = arr[x], Y = arr[arr[x] - 1];
                arr[arr[x] - 1] = (x + 1) * -1;
                x = X, y = Y;
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