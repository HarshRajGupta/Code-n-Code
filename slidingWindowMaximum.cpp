#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
	bool add(int val) {
		auto pos = this;
		while (pos->next != nullptr) {
			cout << pos->val << ' ';
			pos = pos->next;
		}
		cout << pos->val << endl;
		pos->next = new ListNode(val);
		return true;
	}
};

void __PRINT_VARIABLE(ListNode *x) {
	std::cerr << '[';
	unsigned int f = 0;
	for (ListNode *i = x; i != nullptr; i = i->next, ++f) {
		if (f) std::cerr << ", ";
		std::cerr << i->val;
	}
	std::cerr << ']';
}

#ifndef debug
#define debug(...)
#endif

class Solution {
   public:
	void test() {
		auto head = new ListNode(10);
		head->add(20);
		head->add(30);
		debug(head)
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