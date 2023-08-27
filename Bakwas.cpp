#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
   public:
	int minOperations(vector<int>& nums, int target) {
		multiset<int> s;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				s.insert(1);
			} else
				s.insert(log2(nums[i]));
		}
		int cnt = 0;
		multiset<int> t;
		while (target) {
			if (target & 1) t.insert(cnt);
			target >>= 1;
			cnt++;
		}
		return 0;
	}
	void test() {
		{
			vector<int> a = {
				1, 2, 8
			};
			cout << minOperations(a, 7) << endl;
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