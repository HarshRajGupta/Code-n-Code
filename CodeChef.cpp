#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    vector<vector<int>> ans;
    void checkPath(TreeNode* root, vector<int> &path, int sum) {
        if (!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if (sum < 0) {
            path.pop_back();
            return;
        }
        if (!root->left && !root->right) {
            if (sum == 0) ans.push_back(path);
            path.pop_back();
            return;
        }
        checkPath(root->left, path, sum);
        checkPath(root->right, path, sum);
    }
    vector<vector<int>> fun(TreeNode* root, int s) {
        vector<int> path;
        checkPath(root, path, s);
        return ans;
    }
    void test() {
        auto root = new TreeNode(5, new TreeNode(4, new TreeNode(11, new TreeNode(7), new TreeNode(2))), new TreeNode(8, new TreeNode(13), new TreeNode(4, nullptr, new TreeNode(5))));
        debug(fun(root, 22));
    }
};

#ifdef __TEST__
__TEST__
#endif