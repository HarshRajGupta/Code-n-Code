#include <bits/stdc++.h>

#include <functional>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	int i = 0;
	bool canDo(vector<int>& nums, int target) {
		int sum = 0;
		for (i = 0; i < nums.size(); i++) {
			if (nums[i] <= target)
				sum += nums[i];
			else
				break;
		}
		debug(nums, sum, target, i);
		return sum >= target;
	}

   public:
	int minOperations(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int ans = 0;
		while (!canDo(nums, target)) {
			if (i == nums.size()) return -1;
			nums[i] >>= 1;
			nums.push_back(nums[i]);
			sort(nums.begin(), nums.end());
			debug(nums);
			++ans;
		}
		return ans;
	}
	void test() {
		{
			vector<int> a = {1, 32, 1, 2};
			cout << minOperations(a, 12) << endl;
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