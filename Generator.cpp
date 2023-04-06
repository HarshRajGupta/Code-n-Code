#include <bits/stdc++.h>
// 107 211 997 2111 10007 20011 100003 200003 1000003 10000019
#define pr ((rand() * (rand()%7+1) * (rand()%7+1) * 1ll % MOD)/ (rand()%7+1))
#define r (pr * (rand() & 1 ? -1 : 1))
std::bitset<2750177> isPrime; std::vector<int> primes;
class Solution {
    void static preCompute(void) {
        isPrime[0] = isPrime[1] = 1;
        for (int i = 2; (i * i) <= 2750177; ++i) if (!isPrime[i]) for (int j = (i * i); j <= 2750177; j += i) isPrime[j] = true;
        for (int i = 2; i <= 2750177; ++i) if (!isPrime[i]) primes.push_back(i);
    }
    const static long long MOD = 1e9 + 7, L = 211;
    void static generateArray(size_t n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%lld ", r); printf("\n");
    }
    void static generatePositiveArray(size_t n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%lld ", pr); printf("\n");
    }
    void static generateBinaryArray(size_t n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%d ", rand() & 1); printf("\n");
    }
    void static generatePrimeArray(size_t n = rand() % L + 1, size_t z = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%d ", primes[rand() % std::min(primes.size(), z)]); printf("\n");
    }
    void static generateLowerString(size_t n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%c", 'a' + rand() % 26); printf("\n");
    }
    void static generateUpperString(size_t n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%c", 'A' + rand() % 26); printf("\n");
    }
    void static generateBinaryString(size_t n = rand() % L + 1) {
        printf("%d\n", n); while (n--) printf("%d", rand() & 1); printf("\n");
    }
    void static generateMatrix(size_t n = rand() % L + 1, size_t m = rand() % L + 1) {
        printf("%d %d\n", n, m); while (n--) generateArray(m);
    }
    void static generatePositiveMatrix(size_t n = rand() % L + 1, size_t m = rand() % L + 1) {
        printf("%d %d\n", n, m); while (n--) generatePositiveArray(m);
    }
    void static generateBinaryMatrix(size_t n = rand() % L + 1, size_t m = rand() % L + 1) {
        printf("%d %d\n", n, m); while (n--) generateBinaryString(m);
    }

    void generateTestCase(void) {
        std::cout << pr << ' ' << pr << '\n';
        /* generate test case */
        // generateArray();
        // generatePositiveArray();
        // generateBinaryArray();
        // generatePrimeArray();
        // generateLowerString();
        // generateUpperString();
        // generateBinaryString();
        // generateMatrix();
        // generatePositiveMatrix();
        // generateBinaryMatrix();
    }
public:
    void test(void) {
        freopen("input.txt", "w", stdout);
        preCompute();
        if (1) {
            int t = rand(); std::cout << t << '\n';
            while (t--) generateTestCase();
        } else if (1) {
            printf("1\n");
            generateTestCase();
        } else {
            generateTestCase();
        }
    }
};

#ifdef __TEST__
__TEST__
#endif