#ifdef ONLINE_JUDGE
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#ifndef __RUN
#define __RUN solve(), std::cout << '\n'
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

template <class T> using v = std::vector<T>;
template <class T> using xHeap = std::priority_queue<T>;
template <class T> using nHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define _for(i, n) for(int64_t i = 0; i < (int64_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int64_t i = n; i >= 0; --i)

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
// const long long MOD = 1e9 + 7;
int ans(vector<int> &A) {

    vector<long long> prefixSum(A.size() + 1), suffixSum(A.size() + 1);
    for (int i = 0; i < A.size(); ++i) {
        prefixSum[i + 1] = prefixSum[i] + A[i];
    }
    // debug(suffixSum, A)
    for (int i = A.size() - 1; i >= 0; --i) {
        suffixSum[i] = suffixSum[i + 1] + A[i];
        // debug(suffixSum[i], suffixSum[i + 1], A[i])
    }
    long long l1 = 1, l3 = A.size() - 1;
    for (int i = 2; i < A.size() - 1; ++i) {
        if (prefixSum[l1] < prefixSum[i]) l1 = i;
    }
    for (int i = A.size() - 2; i > l1 - 1; --i) {
        if (suffixSum[l3] < suffixSum[i]) l3 = i;
    }
    long long l2 = A[l1], s = 0;
    if (l1 > 1 || l3 < A.size() - 1) l2 = 0;
    for (int i = l1; i < l3; ++i) {
        s += A[i];
        l2 = max(l2, s);
        if (s < 0) s = 0;
    }
    debug(l1, l2, l3, prefixSum, suffixSum)
    return (prefixSum[l1] + l2 + suffixSum[l3] + MOD) % MOD;
}

int pp(v<int> &A) {
    auto arr = A;
    for (int i = 0; i < arr.size(); ++i) arr[i] *= -1;
    debug(arr)
    long long s = 0, l = -1, m1 = 0, m2 = 0;
    priority_queue<int> p;
    p.push(0); p.push(0);

    for (int i = 1; i < arr.size() - 1; ++i) {
        s += arr[i];
        m1 = max(s, m1);
        // debug(m1)
        if (s < 0) {
            s = 0;
            p.push(m1);
            m1 = 0;
        }
    }
    p.push(m1);
    long long ss = 0;
    for (int i = 0; i < A.size(); ++i) {
        ss += A[i];
        // ss %= MOD;
    }
    debug(p, ss)
    ss += p.top(); p.pop();
    ss += p.top();
    return (ss + MOD) % MOD;
}

int po(v<int> A) {
    vector<long long> pre(A.size() + 1), suf(A.size() + 1);
    for (int i = 0; i < A.size(); ++i) {
        pre[i + 1] = pre[i] + A[i];
    }
    for (int i = A.size() - 1; i >= 0; --i)
        suf[i] = suf[i + 1] + A[i];
    long long l1 = 1, l3 = A.size() - 1, s = 0;
    debug(l3)
    long long s2 = 0, l = l1, r = l1, MAX = 0, lMAX = 0, rMAX = 0;
    while (l1 < l3 - 1 && A[l1] > 0) {
        ++l1;
    }
    while (l3 > l1 && A[l3 - 1] > 0) {--l3;}
    debug(l1, l3)
    for (int i = l1; i < l3; ++i) {
        debug(A[i], s)
        s2 += A[i];
        if (s2 < 0) {s2 = 0; l = i + 1;}
        ++r;
        if (s2 >= MAX) {
            lMAX = l;
            rMAX = r;
            MAX = s2;
        }
    }
    // debug(l3)
    // if (lMAX == l1 && rMAX - lMAX >= 2) l1 = 0;
    // if (rMAX == l3 && rMAX - lMAX >= 2) l3 = A.size();
    for (int i = l1; i <= lMAX; ++i) {
        // debug(l3)
        if (pre[l1] < pre[i]) l1 = i;
    }
    for (int i = l3; i >= rMAX; --i) {
        // debug(l3)
        if (suf[l3] < suf[i]) l3 = i;
    }
    debug(l1, MAX, l3, pre, suf, suf[l3], pre[l1])
    return (pre[l1] + suf[l3] + MAX + MOD) % MOD;
}

void solve() {
    /* Code */
    v<int> a = { -1, 5, 5, 5, 5 , 5 };
    cout << po(a);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    uint32_t tCs; cin >> tCs;
    for (uint32_t tC = 0; tC++ < tCs; __RUN);
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}