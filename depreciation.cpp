#include <bits/stdc++.h>
using namespace std;

long double power(long double n, int expo) {
    long double ans = 1;
    while (expo) {
        if (expo & 1) ans = (ans * n);
        n = (n * n);
        expo >>= 1;
    }
    return ans;
}

long double deprecatedValue(long long lifeTime, long long time, const long double E, long double value = 100) {
    static unordered_map<long long, unordered_map<long long, long double>> dp;
    if (dp[lifeTime][time])
        return dp[lifeTime][time];

    if (time) value = deprecatedValue(lifeTime - 1, time - 1, E, value);
    long double l = 0.000000001, r = 1;
    while ((r - l) > 0.0000001) {
        long double mid = (r + l) / 2.0;
        if (power(mid, lifeTime) > E)
            r = mid - 0.0000001;
        else
            l = mid + 0.0000001;
    }
    if (abs(power(l, lifeTime) - E) > abs(power(r, lifeTime) - E))
        value *= (1 - (abs(r * 100 - 100)) / 100.0);
    else
        value *= (1 - (abs(l * 100 - 100)) / 100.0);
    return dp[lifeTime][time] = value;
}

long double depreciationRate (long long timeRemaining, long double currentValue, const long double E) {
    long double l = 0.000000001, r = 1;
    while ((r - l) > 0.0000001) {
        long double mid = (r + l) / 2.0;
        if (power(mid, timeRemaining) > E) r = mid - 0.0000001;
        else l = mid + 0.0000001;
    }
    if (abs(power(l, timeRemaining) - E) > abs(power(r, timeRemaining) - E)) {
        return currentValue - currentValue * (1 - (abs(r * 100 - 100)) / 100.0);
    }
    return currentValue - currentValue * (1 - (abs(l * 100 - 100)) / 100.0);
}

/*  Future Value = Current Value * (1 - Rate)^time   */

int main() {
    long double time = 100, currentValue = 100, E = 0.0000001, salvage = 00;
    for (long  i = 0.0; i <= time; i += 1) {
        auto rate = depreciationRate(time - i, currentValue - salvage, E), predictedValue = deprecatedValue(time, i, E, 100 - salvage) + salvage;
        currentValue -= rate;
        debug(i, rate, predictedValue, currentValue)
        if (currentValue * 10000 >= 1)cout << "(" << i << ',' << currentValue << ")\n";
        if (rate * 10000 >= 1) cout << "(" << i << ',' << rate << ")\n";

    }
    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

long double power(long double n, int expo) {
    long double ans = 1;
    while (expo) {
        if (expo & 1) ans = (ans * n);
        n = (n * n);
        expo >>= 1;
    }
    return ans;
}

long double deprecatedValue(long long lifeTime, long long time, const long double E) {
    static unordered_map<long long, unordered_map<long long, long double>> dp;
    if (dp[lifeTime][time])
        return dp[lifeTime][time];

    long double value = 100;
    if (time)
        value = deprecatedValue(lifeTime - 1, time - 1, E);
    long double l = 0.000000001, r = 1;
    while ((r - l) > 0.0000001) {
        long double mid = (r + l) / 2.0;
        if (power(mid, lifeTime) > E)
            r = mid - 0.0000001;
        else
            l = mid + 0.0000001;
    }
    if (abs(power(l, lifeTime) - E) > abs(power(r, lifeTime) - E))
        value *= (1 - (abs(r * 100 - 100)) / 100.0);
    else
        value *= (1 - (abs(l * 100 - 100)) / 100.0);
    return dp[lifeTime][time] = value;
}

long double depreciationRate (long long timeRemaining, long double currentValue, const long double E) {
    long double l = 0.000000001, r = 1;
    while ((r - l) > 0.0000001) {
        long double mid = (r + l) / 2.0;
        if (power(mid, timeRemaining) > E) r = mid - 0.0000001;
        else l = mid + 0.0000001;
    }
    if (abs(power(l, timeRemaining) - E) > abs(power(r, timeRemaining) - E)) {
        return currentValue - currentValue * (1 - (abs(r * 100 - 100)) / 100.0);
    }
    return currentValue - currentValue * (1 - (abs(l * 100 - 100)) / 100.0);
}

Future Value = Current Value * (1 - Rate)^time

int main() {
    long double time = 100, val = 100, E = 0.1;
    for (long  i = 0.0; i <= time; i += 1) {
        auto x = depreciationRate(time - i, val, E), y = deprecatedValue(time, i, E);
        val -= x;
        cout << i << "  ->  " << x << " -> " << val  << "  ->  " << y << '\n';
    }
    return 0;
}

*/