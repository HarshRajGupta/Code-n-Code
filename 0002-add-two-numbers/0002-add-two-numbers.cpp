/**
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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l2 == NULL)
            return l1;
        if (l1 == NULL)
            return l2;
        ListNode* res = new ListNode((l1->val+l2->val)%10), *list;
        list = res;
        int carry = (l1->val+l2->val)/10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 != NULL || l2 != NULL || carry != 0) {
            res->next = new ListNode(carry);
            res = res->next;
            if (l1 != NULL) {
                res->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                res->val += l2->val;
                l2 = l2->next;
            }
            carry = res->val/10;
            res->val %= 10;
        }
        return list;
    }
};