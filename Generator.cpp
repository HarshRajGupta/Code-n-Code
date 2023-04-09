#include <bits/stdc++.h>
// 107 211 997 2111 10007 20011 100003 200003 1000003 10000019
struct testCase {
    static const long long MOD = 1e9 + 7, L = 200003;
#define r ((1ll * (rand() % rand()) * (rand() % rand())) % 1000000007 / (rand() % rand()))
// #define r (1ll * (rand() % rand()) * (rand() % rand()) % 1000000007)
// #define r (1ll * rand() * (rand() % rand()) * (rand() % rand()) % 1000000007)
// #define r (1ll * (rand() % rand()) * (rand() % rand()) * (rand() % rand()))
    testCase() {
        std::cout << std::fixed << std::setprecision(16);
    }
    void generatePair(unsigned long long MOD = 18446744073709551615ull) {
        std::cout << r << ' ' << r << std::endl;
    }
    void generateArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (rand() & 1 ? -1ll : 1ll) * r << ' ';
        std::cout << std::endl;
    }
    void generatePositiveArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << r << ' ';
        std::cout << std::endl;
    }
    void generatePermutation(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        std::vector<int> v(n); for (size_t i = 0; i < n; ++i) v[i] = i + 1;
        std::random_shuffle(v.begin(), v.end());
        for (size_t i = 0; i < n; ++i) std::cout << v[i] << ' ';
        std::cout << std::endl;
    }
    void generateUniqueArray(size_t n = rand() % L + 1) {
        size_t N = n * (long long)((sqrt(n) <= 11 ? rand() % 11 : sqrt(n)) / (sqrt(sqrt(n)) <= 2 ? 2 : sqrt(rand() % (int)sqrt(n)))) % 400009;
        if (N <= n) N += n;
        debug(N)
        std::cout << n << '\n';
        std::vector<int> v(N), arr;
        for (size_t i = 0; i < N; ++i) v[i] = i + 1;
        std::random_shuffle(v.begin(), v.end());
        for (size_t i = 0; i < n; ++i) {
            auto it = v.begin() + rand() % v.size();
            arr.push_back(*it);
            v.erase(it);
        }
        std::random_shuffle(arr.begin(), arr.end());
        for (size_t i = 0; i < n; ++i) std::cout << arr[i] << ' ';
        std::cout << std::endl;
    }
    void generateBinaryArray(size_t n = rand() % L + 1) {
        std::cout << n << '\n';
        while (n--) std::cout << (rand() & 1) << ' ';
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
    void generateMatrix(size_t n = rand() % L + 1, const int m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) {
            for (int i = 0; i < m; ++i) std::cout << (rand() & 1 ? -1 : 1) * r << ' ';
            std::cout << std::endl;
        }
    }
    void generatePositiveMatrix(size_t n = rand() % L + 1, const int m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) {
            for (int i = 0; i < m; ++i) std::cout << r << ' ';
            std::cout << std::endl;
        }
    }
    void generateBinaryMatrix(size_t n = rand() % L + 1, const int m = rand() % L + 1) {
        std::cout << n << ' ' << m << '\n';
        while (n--) {
            for (int i = 0; i < m; ++i) std::cout << (rand() & 1);
            std::cout << std::endl;
        }
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
        generateUniqueArray(100000);
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
        int t = 1; std::cout << t << '\n';
        while (t--) generateTestCase();
    }
};

#ifdef __TEST__
__TEST__
#endif