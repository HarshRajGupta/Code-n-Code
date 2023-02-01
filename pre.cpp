#ifndef __FAST_IO
#pragma GCC optimize("O3", "Ofast", "unroll-loops", "omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
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


const int MAX_N = 100005;
const int p = 131;
const unsigned long long mod = 1e9 + 7;

unsigned long long power[MAX_N];
unsigned long long h1[MAX_N];
unsigned long long h2[MAX_N];

int countCommonSubstrings(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();
  int count = 0;

  // Compare all substrings of s1 with substrings of s2
  for (int i = 0; i < m; i++) {
    for (int len = 1; len <= m - i; len++) {
      string sub_s1 = s1.substr(i, len);
      for (int j = 0; j < n; j++) {
        for (int len2 = 1; len2 <= n - j; len2++) {
          string sub_s2 = s2.substr(j, len2);
          if (sub_s1 == sub_s2) {
            count++;
          }
        }
      }
    }
  }
  return count;
}

void solve() {
    int n, k; cin >> n >> k;
    string a, b; cin >> a >> b;
    priority_queue<pair<int, char>> h;
    set<char> z;
    _for(i, n) z.insert(a[i]);
    for (auto i : z) {
        int m = 0;
        _for(j, n) {
            if (a[j] == i && b[j] != i) ++m;
        }
        h.push({m, i});
    }
    while (k-- && !h.empty()) {
        auto ele = h.top();
        _for(i, n) {
            if (a[i] == ele.sd) a[i] = b[i];
        }
    }
    cout << countCommonSubstrings(a, b);
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