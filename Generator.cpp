#include <bits/stdc++.h>
// 107 211 997 2111 10007 20011 100003 200003 1000003 10000019
#define pr ((rand() * (rand()%7+1) * (rand()%7+1) * 1ll % MOD)/ (rand()%7+1))
#define r (pr * (rand() & 1 ? -1 : 1))

std::bitset<2750177> isPrime; std::vector<int> primes;
const long long MOD = 1e9 + 7, L = 211;

class testCase {
public:
    static void preCompute(void) {
        isPrime[0] = isPrime[1] = 1;
        for (int i = 2; (i * i) <= 2750177; ++i) if (!isPrime[i]) for (int j = (i * i); j <= 2750177; j += i) isPrime[j] = true;
        for (int i = 2; i <= 2750177; ++i) if (!isPrime[i]) primes.push_back(i);
    }
    void generateArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << r << ' ';
        std::cout << std::endl;
    }
    void generatePositiveArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << pr << ' ';
        std::cout << std::endl;
    }
    void generateBinaryArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (rand() & 1) << ' ';
        std::cout << std::endl;
    }
    void generatePrimeArray(size_t n = rand() % L + 1, size_t z = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << primes[rand() % std::min(primes.size(), z)] << ' ';
        std::cout << std::endl;
    }
    void generateLowerString(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (char)('a' + rand() % 26);
        std::cout << std::endl;
    }
    void generateUpperString(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (char)('A' + rand() % 26);
        std::cout << std::endl;
    }
    void generateBinaryString(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (rand() & 1);
        std::cout << std::endl;
    }
    void generateMatrix(size_t n = rand() % L + 1, size_t m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) generateArray(m);
    }
    void generatePositiveMatrix(size_t n = rand() % L + 1, size_t m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) generatePositiveArray(m);
    }
    void generateBinaryMatrix(size_t n = rand() % L + 1, size_t m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) generateBinaryArray(m);
    }
};

class Solution : private testCase {
    void generateTestCase(void) {
        /* generate test case */
        // std::cout << pr << '\n';
        // std::cout << (pr * pr) % MOD << '\n';
        // std::cout << (pr * pr) % MOD << ' ' << (pr * pr) % MOD << '\n';
        // std::cout << (pr) % MOD << ' ' << (pr) % MOD << '\n';
        generateArray();
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
        // freopen("input.txt", "w", stdout);
        preCompute();
        if (1) {
            int t = rand() % L; std::cout << t << '\n';
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