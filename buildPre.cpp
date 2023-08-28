#include <bits/stdc++.h>

#include <vector>
using namespace std;

vector<int32_t> allPrimes;
vector<bool> sieve(const int32_t n = 100007) {
	vector<bool> isPrime(n + 1, true);
	isPrime[0] = false, isPrime[1] = false;
	for (int32_t i = 2; (i * i) <= n; ++i)
		if (isPrime[i])
			for (int j = (i * i); j <= n; j += i) isPrime[j] = false;
	for (int32_t i = 2; i <= n; ++i)
		if (isPrime[i]) allPrimes.push_back(i);
	return isPrime;
}

vector<int> primeFactorization(int n) {
	vector<int> factors;
	for (auto &i : allPrimes) {
		if (i * i > n) break;
		while (n % i == 0) {
			n /= i;
			factors.push_back(i);
		}
	}
	return factors;
}

int countNumbersWithNoCommonFactors(int x) {
	vector<int> factors = primeFactorization(x);
	int result = x;
	for (int factor : factors) result = result * (factor - 1) / factor;
	return result;
}

vector<int> fun(vector<int> &a) {
	vector<bool> isPrime = sieve();
	vector<int> ans = a;
	for (int i = 0; i < a.size(); ++i) {
		ans[i] = countNumbersWithNoCommonFactors(a[i]);
	}
	return ans;
}

signed main(void) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a) cin >> i;
	auto ans = fun(a);
	for (auto &i : ans) cout << i << " ";
	return 0;
}