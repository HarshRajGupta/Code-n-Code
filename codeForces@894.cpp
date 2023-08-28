#include <iostream>
#include <vector>

std::vector<int> primeFactorization(int n) {
    std::vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int countNumbersWithNoCommonFactors(int x) {
    std::vector<int> factors = primeFactorization(x);
    int result = x; // Initialize result with x

    for (int factor : factors) {
        result = result * (factor - 1) / factor;
    }

    return result;
}

int main() {
    int x;
    std::cout << "Enter a number (x): ";
    std::cin >> x;

    int result = countNumbersWithNoCommonFactors(x);
    std::cout << "Count of numbers less than " << x << " with no common factors: " << result << std::endl;

    return 0;
}
