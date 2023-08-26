#include <bits/stdc++.h>
#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
   public:
    int solve(vector<int> &a, vector<int> &b) {
    	int ans = 0;
    	for(int i = 0; i < a.size(); ++i) {
    		ans = max(5 * a[i] + 2 * b[i], ans);
    	}
    	return ans;
    }
    void test() {
        {
        	vector<int> a = {
        		1, 2, 3
        	}, b = {
        		3, 2, 1
        	};
        	
        	auto ans = solve(a, b);
        	cout << ans;
        }
    }
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif