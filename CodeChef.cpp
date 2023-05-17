#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x = 0, ListNode *next = NULL) : val(x), next(next) {}
    void traverse(function<void(int)> f = [](int x) {cout << x << ' ';}) {
        f(val);
        if (next) next->traverse(f);
    }
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next || !head->next->next) return head;
        ListNode *odd = NULL, *even = NULL, *codd = NULL, *ceven = NULL, *it = head;
        int pos = 1;
        while (it != NULL) {
            debug(it->val);
            const auto temp = it->next;
            if (pos) {
                if (codd != NULL) {
                    codd->next = it;
                    codd = codd->next;
                }
                else {
                    odd = codd = it;
                }
                pos = 0;
            } else {
                if (ceven != NULL) {
                    ceven->next = it;
                    ceven = ceven->next;
                } else {
                    even = ceven = it;
                }
                pos = 1;
            }
            it = temp;
        }
        ceven->next = NULL;
        if (codd) codd->next = even;
        return odd;
    }
    void test() {
        auto h = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
        h->traverse();
        auto res = oddEvenList(h);
        res->traverse();
    }
};

#ifdef __TEST__
__TEST__
#endif