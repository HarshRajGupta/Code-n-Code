#include <bits/stdc++.h>
using namespace std;


// vector<int> primes;

set<int> prem(int A) {
    set<int> primes;
    vector<bool> isPrime(A+1);
    debug(isPrime.size(), A+1, isPrime);
    isPrime[0] = true;
    isPrime[1] = true;
    for(long long i = 2; i <=A; ++i) {
        if (isPrime[i] == false) {
            primes.insert(i);
            for(long long j = i; j*i <= A; ++j)
                isPrime[j*i] = true;
        }
    }
    return primes;
}

vector<int> primesum(int A) {
    auto primes = prem(A);
    debug(primes)
    for(auto i : primes) {
        cout << i << endl;
        if (primes.find(A-i) != primes.end()) {
            return {i, A-i};
        }
    }
    return {};
}


signed main(int argc, char const *argv[]) {
    debug(primesum(14));
    return 0;
}