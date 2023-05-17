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
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next || !head->next->next) return head;
        ListNode *odd, *even, *codd, *ceven, *it = head;
        int pos = 1;
        while (it) {
            if (pos) {
                if (odd) {
                    codd->next = it;
                    codd = codd->next;
                }
                else {
                    odd = codd = it;
                }
            } else {
                if (even) {
                    ceven->next = it;
                    ceven = ceven->next;
                } else {
                    even = ceven = it;
                }
            }
            it = it->next;
        }
        codd->next = even;
        return odd;
    }
    void test() {
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif