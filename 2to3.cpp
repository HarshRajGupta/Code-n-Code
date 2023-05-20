#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x = 0, TreeNode *left = NULL, TreeNode *right = NULL) : val(x), left(left), right(right) {}
};


class Solution {
public:
    /* function */
    void test() {
        // TreeNode *root = new TreeNode(1, new TreeNode(2, NULL, new TreeNode(5)), new TreeNode(3));
        // debug(root)
        auto head = new debug::ListNode(1, new debug::ListNode(2, new debug::ListNode(3, new debug::ListNode(4, new debug::ListNode(5)))));
        debug(head)
    }
};

#ifdef __TEST__
__TEST__
#endif