/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int listSize(ListNode* head) {
        int sz = 0;
        for(auto i = head; i != NULL; i = i->next)
        sz++;
        return sz;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = listSize(head), pos = 1;
        if (sz-n == 0) {
            return head->next;
        }
        for(auto i = head; i != NULL; i = i->next) {
            if (pos == sz-n) {
                i->next = i->next->next;
                return head;
            }
            pos++;
        }
        return head;
    }
};