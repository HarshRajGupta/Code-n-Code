#include <bits/stdc++.h>
using namespace std;

#ifndef OFFLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

const int lB(const std::vector<int> &arr, const int &t) {
	if (t > arr[arr.size() - 1])
		return (arr.size() - 1);
	else if (t <= arr[0])
		return -1;
	int l = 0, r = (arr.size() - 1), ans = - 1;
	while (l <= r) {
		int mid = ((l + r) / 2);
		if (arr[mid] >= t)
			r = (mid - 1);
		else
			ans = mid, l = (mid + 1);
	}
	return ans;
}

class Solution {
public:
	vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
		sort(nums.begin(), nums.end());
		vector<long long> ans, prefixSum(nums.size() + 1);
		for (int i = 0; i < nums.size(); ++i) {
			prefixSum[i + 1] = prefixSum[i] + nums[i];
		}
		for (int i = 0; i < queries.size(); ++i) {
			int idx = lB(nums, queries[i]);
			ans.push_back((queries[i] * (idx + 1) - prefixSum[idx + 1]) + (prefixSum[nums.size()] - prefixSum[idx + 1] - (queries[i]*nums.size() - idx - 1)));
		}
		debug(ans);
		return ans;
	}
	void test(void) {
		/* test */
	}
};

#ifdef __TEST__
__TEST__
#endif