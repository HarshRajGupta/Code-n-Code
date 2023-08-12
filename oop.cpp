#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
   public:
    int ans(string s) {
    	vector<int> a(s.size() + 1), b(s.size() + 1);
    	for(int i = 0; i < s.size(); ++i) {
    		a[i+1] = a[i];
    		b[i+1] = b[i];
    		if (s[i] == 'a') {
	 			a[i+1]++;
	 		} else {
	 			b[i+1]++;
	 		}
    	}
    	int ans = 0;
    	for(int i = 0; i < s.size(); ++i) {
    		if (s[i] == 'b') {
    			ans += a[i];
    		}
    	}
    	return ans;
    }
    void test() {
        cout << ans("ababa");
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