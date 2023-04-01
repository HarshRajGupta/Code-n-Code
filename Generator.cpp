#include <bits/stdc++.h>
// 107 211 997 2111 10007 20011 100003 200003 1000003 10000019
#define pr ((rand() * (rand()%7+1) * (rand()%7+1) * 1ll % MOD)/ (rand()%7+1))
#define r (pr * (rand() & 1 ? -1 : 1))

class Solution {
    const static long long MOD = 1e9 + 7, L = 211;
    void generateArray(int n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%lld ", r); printf("\n");
    }
    void generatePArray(int n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%lld ", pr); printf("\n");
    }
    void generateBArray(int n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%d ", rand() & 1); printf("\n");
    }
    void generatePrimeArray(int n = rand() % L + 1) {
        int m = 10000019;
        std::vector<bool> isPrime(m + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; (i * i) <= m; ++i) if (isPrime[i]) for (int j = (i * i); j <= m; j += i) isPrime[j] = false;
        std::vector<int> primes;
        for (int i = 2; i <= m; ++i) if (isPrime[i]) primes.push_back(i);
        printf("%d\n", n); while (n--) printf("%d ", primes[rand() % primes.size()]); printf("\n");
    }
    void generateString(int n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%c", 'a' + rand() % 26); printf("\n");
    }
    void generateUString(int n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%c", 'A' + rand() % 26); printf("\n");
    }
    void generateBString(int n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%d", rand() & 1); printf("\n");
    }
    void generateMatrix(int n = rand() % L + 1, int m = rand() % L + 1) {
        printf("%d %d\n", n, m); while (n--) generateArray(m);
    }
    void generatePMatrix(int n = rand() % L + 1, int m = rand() % L + 1) {
        printf("%d %d\n", n, m); while (n--) generatePArray(m);
    }
    void generateBMatrix(int n = rand() % L + 1, int m = rand() % L + 1) {
        printf("%d %d\n", n, m); while (n--) generateBString(m);
    }

    void generateTestCase(void) {
        /* generate test case */
        // generateArray();
        // generatePArray();
        // generateBArray();
        generatePrimeArray();
        // generateString();
        // generateUString();
        // generateBString();
        // generateMatrix();
        // generatePMatrix();
        // generateBMatrix();
    }
public:
    void test(void) {
        int t = rand() % 7 + 1; printf("%d\n", t);
        while (t--) generateTestCase();
    }
};

#ifdef __TEST__
__TEST__
#endif