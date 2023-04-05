#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long mod_inv(long long a, long long m) {
    long long x, y;
    long long g = gcd(a, m, x, y);
    if (g != 1) {
        return -1;
    } else {
        return (x % m + m) % m;
    }
}

int main() {
    long long a = 532634674575485LL;
    long long b = 143232634734LL;

    long long inv_b = mod_inv(b, MOD);
    if (inv_b == -1) {
        cout << "Error: b is not invertible modulo MOD" << endl;
        return 0;
    }

    long long ans = ((a * inv_b) + MOD) % MOD;

    cout << ans << endl;

    return 0;
}
