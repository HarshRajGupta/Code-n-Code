#include <bits/stdc++.h>

#include <functional>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	bool canDo(vector<int>& nums, int pos, int cnt) {
		if (pos == nums.size() || pos < 0) return cnt == 0;
		if (nums[pos] >= cnt) {
			return true;
		} else {
			return canDo(nums, pos - 1, (cnt - nums[pos]) * 2);
		}
	}
	void perform(vector<int>& nums, int pos, int cnt) {
		if (pos == nums.size() || pos < 0) return;
		if (nums[pos] >= cnt) {
			nums[pos] -= cnt;
		} else {
			perform(nums, pos - 1, (cnt - nums[pos]) * 2);
			nums[pos] = 0;
		}
	}

   public:
	int minOperations(vector<int>& nums, int target) {
		vector<int> bitCount(33);
		for (auto& i : nums) {
			bitCount[log2(i)]++;
		}
		int ans = 0;
		debug(bitCount);
		while (target) {
			long long z = 0;
			int i = 0;
			for (i = 0; z < target && i < 33; ++i) {
				z += ((1LL << i) * bitCount[i]);
				debug(z, target, i, bitCount[i]);
			}
			if (z < target) return -1;
			for (int j = i - 1; j > log2(target); --j) {
				bitCount[j]--;
				bitCount[j - 1] += 2;
				++ans;
			}
			debug(bitCount, target, ans, i, z);
			perform(bitCount, log2(target), 1);
			target >>= 1;
		}
		return ans;
	}
	void test() {
		{
			vector<int> a = {1, 1, 1, 1, 32};
			cout << minOperations(a, 6) << endl;
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