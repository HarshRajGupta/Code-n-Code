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

std::vector<int32_t> allPrimes;
std::vector<bool> sieve(int32_t n = 10000007) {
	std::vector<bool> isPrime(n + 1, true);
	isPrime[0] = false, isPrime[1] = false;
	for (int32_t i = 2; (i * i) <= n; ++i) {
		if (isPrime[i]) {
			allPrimes.push_back(i);
			for (int j = (i * i); j <= n; j += i) isPrime[j] = false;
		}
	}
	return isPrime;
}

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
	bool primeSubOperation(vector<int>& nums) {
		int32_t n = nums.size();
		std::vector<bool> isPrime = sieve();
		int ind = lB(allPrimes, nums[0]);
		if (ind != -1) {
			nums[0] -= allPrimes[ind];
		}
		for (int i = 1; i < n; ++i) {
			int diff = nums[i] - nums[i - 1];
			if (diff <= 1) return false;
			ind = lB(allPrimes, diff);
			if (ind != -1) {
				debug(allPrimes[ind], diff)
				nums[i] -= allPrimes[ind];
			}
		}
        debug(nums)
		return true;
	}
	void test(void) {
		vector<int> a = {998,2};
		cout << primeSubOperation(a) << endl;
	}
};

#ifdef __TEST__
__TEST__
#endif