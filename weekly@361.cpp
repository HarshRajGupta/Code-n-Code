#include <bits/stdc++.h>
#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
	map<int, int> rem;
	int fun(vector<int> &cnt, map<int, int> &rev, int pos, int k, int modulo) {
		if (cnt[pos + 1] < k) return 0;
		if (cnt[pos + 1] == k) return rem[pos] = rev[1] + 1;
		return rem[pos] = rem[cnt[pos + 1] - modulo] + 1;
	}

   public:
	long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
		vector<int> cnt(nums.size() + 1, 0);
		map<int, int> rev;
		long long ans = 0, prev = 0;
		for (int i = 0; i < nums.size(); ++i) {
			cnt[i + 1] = cnt[i];
			if (nums[i] % modulo == k) {
				cnt[i + 1]++;
				rev[cnt[i + 1]] = i;
				prev = fun(cnt, rev, i, k, modulo);
			} else {
				ans += prev;
			}
		}
		return ans;
	}
	void test() {
		{
			vector<int> t = {3, 4, 2};
			int modulo = 2, k = 1;
			auto z = countInterestingSubarrays(t, modulo, k);
			debug(z);
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