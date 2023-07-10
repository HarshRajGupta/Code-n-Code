#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

class DisjointIntervals {
    int N = 12;
    set<int> parentList;
    vector<int> parent, rank;
public:
    DisjointIntervals() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush();
        parent = vector<int>(N, -1);
        // iota(parent.begin(), parent.end());
        rank = vector<int>(N);
    }

    int find(int val) {
        if (parent[val] == val)
            return val;
        parentList.erase(val);
        rank[val] = 0;
        return parent[val] = find(parent[val]);
    }

    void addInteger(int val) {
        debug(val, parentList, parent)
        if (val && parent[val - 1] != -1) {
            parent[val] = find(val - 1);
        } else {
            parentList.insert(val);
            parent[val] = val;
        }
        ++rank[parent[val]];
        if (parent[val + 1] != -1) {
            parent[val + 1] = parent[val];
            rank[parent[val]] += rank[parent[val + 1]];
            rank[parent[val + 1]] = 0;
        }
    }
    vector<vector<int>> getDisjointIntervals() {
        debug(rank, parentList, parent)
        vector<vector<int>> res;
        int prev = -1;
        for (auto &i : parentList) {
            if (prev < i) {
                res.push_back({i, prev = i - 1 + rank[i]});
            }
        }
        return res;
    }
};

class Solution {
public:
    /* function */
    void test() {
        int t; cin >> t;
        while (t--) {
            auto dsu = new DisjointIntervals();
            int q; cin >> q;
            while (q--) {
                int t; cin >> t;
                if (t == 1) {
                    int a; cin >> a;
                    dsu->addInteger(a);
                } else {
                    auto ans = dsu->getDisjointIntervals();
                    for (auto &i : ans) for (auto &j : i) cout << j << ' ';
                    cout << '\n';
                }
            }
        }
    }
    Solution() {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif