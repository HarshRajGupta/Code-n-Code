#include <bits/stdc++.h>
using namespace std;

struct ListNode {
   public:
	int val;
	ListNode *next;
	ListNode(int x = 0, ListNode *next = nullptr) : val(x), next(next) {}
};

ListNode operator+(ListNode x, int y) {
	ListNode *X = &x;
	while (X->next != nullptr) X = X->next;
	X->next = new ListNode(y);
	return x;
}

void __PRINT_VARIABLE(ListNode *z) {
	std::cerr << '[';
	unsigned int f = 0;
	for (ListNode *i = z; i != nullptr; i = i->next, ++f) {
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
		(*head) + 112 + 11 + 12 + 20;
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