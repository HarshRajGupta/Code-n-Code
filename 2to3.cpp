#include <bits/stdc++.h>
using namespace std;

#ifndef debug
#define debug(...)
#endif

#define rep(i, a, n) for(int32_t i = a; i < (int32_t)n; ++i)

class Solution {
    string itos(int &n) {
        if (n == 0) return "0";
        string res;
        while (n) {
            res.push_back(n % 10 + '0');
            n /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
public:
    string removeDuplicates(string s, int k) {
        stack<string> stringHash;
        int count = 0;
        string res;
        for (auto &i : s) {
            if (stringHash.empty() || stringHash.top() != string(1, i)) {
                stringHash.push(itos(count));
                stringHash.push(string(1, i));
                count = 1;
            } else {
                ++count;
                if (count == k) {
                    stringHash.pop();
                    count = stoi(stringHash.top());
                    stringHash.pop();
                }
            }
        }
        stringHash.push(itos(count));
        while (!stringHash.empty()) {
            int count = stoi(stringHash.top());
            stringHash.pop();
            while (count--) {
                res += (stringHash.top());
            }
            if (!stringHash.empty()) stringHash.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
    void test() {

    }
};

#ifdef __TEST__
__TEST__
#endif