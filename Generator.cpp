#include <bits/stdc++.h>
using namespace std;

#ifndef OFFLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse","sse2","sse3","ssse3","sse4","popcnt","abm","mmx","avx","avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        cout << "hello world" << endl;
        return nullptr;
    }
    void test(void) {
        /* test */
        reverseList(nullptr);
    }
};

#ifdef __TEST__
__TEST__
#endif