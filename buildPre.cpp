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
		for (int i = log2(target); i >= 0; --i) {
			if (target & (1 << i)) {
				if (canDo(bitCount, i, 1))
					perform(bitCount, i, 1);
				else {
					int j = i + 1;
					while (j < bitCount.size() && bitCount[j] == 0) j++;
					if (j == bitCount.size()) return -1;
					for (int k = j; k > i; --k) {
						bitCount[k]--;
						bitCount[k - 1] += 2;
						++ans;
					}
				}
			}
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