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

std::vector<int32_t> allPrimes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

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
		int ind = lB(allPrimes, nums[0]);
		if (ind != -1) {
			nums[0] -= allPrimes[ind];
		}
		debug(nums)
		for (int i = 1; i < n; ++i) {
			int diff = nums[i] - nums[i - 1];
			if (diff < 1) return false;
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
		// debug(allPrimes)
	}
};

#ifdef __TEST__
__TEST__
#endif