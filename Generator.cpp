#include <bits/stdc++.h>
// 107 211 997 2111 10007 20011 100003 200003 1000003 10000019
#define r ((1ll * (rand() % rand()) * (rand() % rand())) % 1000000007 / (rand() % rand()))
// #define r (1ll * (rand() % rand()) * (rand() % rand()) % 1000000007)
// #define r (1ll * rand() * (rand() % rand()) * (rand() % rand()) % 1000000007)
// #define r (1ll * (rand() % rand()) * (rand() % rand()) * (rand() % rand()))
struct testCase {
    static const long long MOD = 1e9 + 7, L = 200003;
    void generatePair(unsigned long long MOD = 18446744073709551615ull) {
        std::cout << r % MOD << ' ' << r % MOD << std::endl;
        fflush(stdout);
    }
    void generateArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (rand() & 1 ? -1ll : 1ll) * r << ' ';
        std::cout << std::endl;
        fflush(stdout);
    }
    void generatePositiveArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << r << ' ';
        std::cout << std::endl;
        fflush(stdout);
    }
    void generatePermutation(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        std::vector<int> v(n); for (size_t i = 0; i < n; ++i) v[i] = i + 1;
        std::random_shuffle(v.begin(), v.end());
        for (const int &i : v) std::cout << i << ' ';
        std::cout << std::endl;
        fflush(stdout);
    }
    void generateUniqueArray(size_t n = rand() % L + 1) {
        size_t N = n * (n < 100 ? (rand() % 7) + 3 : sqrt(rand() % n + (n >> (int)log10(n)))) / (sqrt(sqrt(rand() % n + (n >> 1))));
        debug(N)
        while (N <= (n << 1)) N = (N + (rand() % n)) % 400009;
        std::cout << n << '\n';
        int arr[400009];
        for (size_t i = 0; i < N; ++i) arr[i] = i + 1;
        std::random_shuffle(arr, arr + N);
        // for (const int &i : v) std::cout << i << ' ';
        std::cout << std::endl;
        fflush(stdout);
    }
    void generateBinaryArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (rand() & 1) << ' ';
        std::cout << std::endl;
        fflush(stdout);
    }
    void generateLowerString(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (char)('a' + rand() % 26);
        std::cout << std::endl;
        fflush(stdout);
    }
    void generateUpperString(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (char)('A' + rand() % 26);
        std::cout << std::endl;
        fflush(stdout);
    }
    void generateBinaryString(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (rand() & 1);
        std::cout << std::endl;
        fflush(stdout);
    }
    void generateMatrix(size_t n = rand() % L + 1, const int m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) {
            for (int i = 0; i < m; ++i) std::cout << (rand() & 1 ? -1 : 1) * r << ' ';
            std::cout << '\n';
        }
        fflush(stdout);
    }
    void generatePositiveMatrix(size_t n = rand() % L + 1, const int m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) {
            for (int i = 0; i < m; ++i) std::cout << r << ' ';
            std::cout << '\n';
        }
        fflush(stdout);
    }
    void generateBinaryMatrix(size_t n = rand() % L + 1, const int m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) {
            for (int i = 0; i < m; ++i) std::cout << (rand() & 1);
            std::cout << '\n';
        }
        fflush(stdout);
    }
};

class Solution : private testCase {
    void generateTestCase(void) {
        /* generate test case */
        // std::cout << r << '\n';
        // generatePair();
        // generateArray();
        // generatePositiveArray();
        // generatePermutation();
        // generateUniqueArray(10);
        int t = r;
        std::cout << t << ' ' << log10(t);
        // generateBinaryArray();
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
        int t = rand() % 211; std::cout << t << '\n';
        while (t--) generateTestCase();
    }
};

#ifdef __TEST__
__TEST__
#endif