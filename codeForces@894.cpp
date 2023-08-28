#include <iostream>

int phi(int n) {
    int result = n; // Initialize result with n

    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            result -= result / p;
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

int main() {
    int x;
    std::cout << "Enter a number (x): ";
    std::cin >> x;

    int result = phi(x);
    std::cout << "Count of numbers less than " << x << " with no common factors: " << result << std::endl;

    return 0;
}
