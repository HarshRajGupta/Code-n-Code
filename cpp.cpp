#include <iostream>
using namespace std;

const int MOD = 1000000007;

const long long invMod(long long n) {
    long long ans = 1, expo = MOD - 2; n %= MOD;
    while (expo) {
        if (expo & 1) ans = (ans * 1ll * n) % MOD;
        n = (n * 1ll * n) % MOD;
        expo >>= 1;
    }
    return ans;
}

int main() {
    long long a = 532634674575485LL;
    long long b = 143232634734LL;
    cout << a / b << ' ';
    cout << (a % MOD)*invMod(b) % MOD;
    return 0;
}
