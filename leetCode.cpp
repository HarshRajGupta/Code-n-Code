#include <bits/stdc++.h>
using namespace std;

void check();
class Solution {
#ifndef debug
#define debug(...)
#endif

#define ll long long
    template <class T> using v = std::vector<T>;
    template <class T> using xHeap = std::priority_queue<T>;
    template <class T> using nHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define _for(i, n) for(int64_t i = 0; i < (int64_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int64_t i = n; i >= 0; --i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
public:
    /* function */
    void test() {
        check();
    }
};

void check() {
    cout << 90;
}

#ifndef ONLINE_JUDGE
#include "leetcode.h"
#endif