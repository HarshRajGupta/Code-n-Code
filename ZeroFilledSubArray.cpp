#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifndef debug
#define debug(...)
#endif

#define _for(i, n) for(int32_t i = 0; i < (int32_t)n; ++i)

class Solution {
public:
	bool isMatch(string &s, string &p, int i = 0, int j = 0) {
		if (i == s.size()) return true;
		if (j == p.size()) return false;
		if (p[j] == '.') return isMatch(s, p, i + 1, j + 1);
		if (isMatch(s, p, i, j + 1)) return true;
		if (p[j] == '*' && j != 0 && i != 0) {
			while (s[i] == p[j - 1] || p[j - 1] == '.') {
				if (isMatch(s, p, i + 1, j + 1)) return true;
				i++;
			}
		}
		if (s[i] == p[j]) return isMatch(s, p, i + 1, j + 1);
		return (s, p, i, j + 1);
	}
	void test() {
		/* test */
	}
};

#ifdef __TEST__
__TEST__
#endif