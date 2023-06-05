#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;
        ListNode* next = removeNodes(head->next);
        if (!next) {
            head->next = nullptr;
            return head;
        }
        if (head->val > next->val) {
            head->next = next;
            return head;
        }
        return next;
    }
    int celebrity(vector<vector<int> >& M, int n)
    {
        set<int> ans;
        for (int i = 0; i < n; i++)
            ans.insert(i);

        for (int p = 0; p < n; ++p)
        {
            for (int i = 0; i < n; i++) {
                if (i == p) continue;
                if (M[i][p] == 0)
                    ans.erase(i);
                if (M[i][p] == 1)
                    ans.erase(p);
                if (ans.empty())
                    break;
                debug(i, p, ans)
            }
        }
        if (!ans.empty()) return *ans.begin();
        return -1;
    }
    void test() {
        vector<vector<int>> m = {
            {0, 1, 0},
            {0, 0, 0},
            {0, 1, 0}
        };
        cout << celebrity(m, 3) << endl;
        /* test */
    }
};

#ifdef __TEST__
__TEST__
#endif