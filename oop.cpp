#include <bits/stdc++.h>
#include <vector>
using namespace std;
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
   public:
	int fun(int n, vector<int> people, vector<char> status) {
		int MAX = 0, curr = 0;
		map<int, int> mp;
		for(int i = 0; i < n; ++i) {
			if (status[i] == '+') {
				if (mp[people[i]] == 0) {
					mp[people[i]] = 1;
					curr++;
				} else {
					return -1;
				}
			} else if (mp[people[i]] != 1) {
				return -1;
			} else {
				mp[people[i]] = 0;
				curr--;
			}
			MAX = max(MAX, curr);
		}
		return MAX;
	}
	void test() {
		vector<int> a= {1, 2, 1};
		vector<char> b = {'+', '+', '-'};
		cout << fun(3, a, b);
	}
	Solution() {
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif