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

class Solution {
public:
	int kItemsWithMaximumSum(int numOnes, int numZeros, int numNeg, int k) {
		int ans = 0;
		ans += min(numOnes, k);
		k -= min(numOnes, k);
		k -= min(numZeros, k);
		ans -= min(k, numNeg);
		return ans;
	}
	void test(void) {
		cout << kItemsWithMaximumSum(1, 2, 3, 3);
		/* test */
	}
};

#ifdef __TEST__
__TEST__
#endif