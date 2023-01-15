#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...) ;
#endif

const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define int long long
#define ll long double

#define Y std::cout << "YES";
#define N std::cout << "NO";

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for(auto i = a; i < n; ++i)
#define bw(i, n) for(int32_t i = (int32_t)n; i >= 0; --i)

#define v std::vector
#define maxHeap std::priority_queue<int>
#define minHeap std::priority_queue<int, std::vector<int>, std::greater<int>>

#define ft first
#define sd second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

void __DEBU_VAR(vector<string> &s) { std::cerr << "\n}\n"; }

template <typename T, typename... V>
void __DEBU_VAR(vector<string> s, const T t, V... a) {
    cerr << *(--s.end()) << ' ';
    s.erase(--s.end());
    __PRINT_VARIABLE(t);
    if (sizeof...(a))
        std::cerr << ",  \n";
    __DEBUG_VAR(s, a...);
}

#define db(x...) {vector<string> words; string DEBUG_VAL = #x; string wd = ""; for(auto i : DEBUG_VAL) {if (i != ' ' && i != ',') wd.push_back(i); else if (i == ',') {words.push_back(wd); wd = "";}} words.push_back(wd);cout << wd; __DEBU_VAR(words, x);}

void solve(void) {
    db(1, 3, 5, 1)
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}