#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
	ListNode *add(int val) {
		auto pos = this;
		while (pos->next != nullptr) pos = pos->next;
		return pos->next = new ListNode(val);
	}
	ListNode *operator[](int index) {
		auto pos = this;
		while (pos != nullptr && index--) pos = pos->next;
		return pos;
	}
	ListNode *operator+(int val) {
		auto pos = this;
		while (pos->next != nullptr) pos = pos->next;
		pos->next = new ListNode(val);
		return this;
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

// void __PRINT_VARIABLE(ListNode x) {
// 	std::cerr << '[';
// 	unsigned int f = 0;
// 	cout << x.val;
// 	for (ListNode *i = &x; i != nullptr; i = i->next, ++f) {
// 		if (f) std::cerr << ", ";
// 		std::cerr << i->val;
// 	}
// 	std::cerr << ']';
// }

#ifndef debug
#define debug(...)
#endif

class Solution {
   public:
	void test() {
		auto head = new ListNode(10);
		head = (*head) + 11;
		head = (*head) + 12;
		ListNode *t = (*head)[1];
		debug(head, t)
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