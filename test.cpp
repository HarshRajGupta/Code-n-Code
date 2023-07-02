#include <bits/stdc++.h>
using namespace __gnu_debug;

#ifndef debug
#define debug(...)
#endif

struct SegmentTreeNode {
    int minVal;
    int maxVal;
};

class SegmentTree {
    std::vector<SegmentTreeNode> tree;
    int n;
    void buildTree(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node].minVal = arr[start];
            tree[node].maxVal = arr[start];
        } else {
            int mid = (start + end) >> 1;
            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);
            tree[node].minVal = min(tree[2 * node + 1].minVal, tree[2 * node + 2].minVal);
            tree[node].maxVal = max(tree[2 * node + 1].maxVal, tree[2 * node + 2].maxVal);
        }
    }
    pair<int, int> query(int node, int start, int end, int left, int right) {
        if (start > right || end < left)
            return make_pair(INT_MAX, INT_MIN);
        if (start >= left && end <= right)
            return make_pair(tree[node].minVal, tree[node].maxVal);
        int mid = (start + end) / 2;
        pair<int, int> leftResult = query(2 * node + 1, start, mid, left, right);
        pair<int, int> rightResult = query(2 * node + 2, mid + 1, end, left, right);
        return make_pair(min(leftResult.first, rightResult.first), max(leftResult.second, rightResult.second));
    }

public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }

    pair<int, int> findMinMax(int left, int right) {
        if (left < 0 || right >= n || left > right)
            return make_pair(INT_MAX, INT_MIN);
        return query(0, 0, n - 1, left, right);
    }
};

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        int r = 0;
        SegmentTree segmentTree(nums);
        for (int i = 0; i < nums.size(); i++) {
            auto [MIN, MAX] = segmentTree.findMinMax(i, r);
            for (int j = r + 1; j < nums.size(); j++) {
                MIN = min(MIN, nums[j]);
                MAX = max(MAX, nums[j]);
                if (abs(MAX - MIN) > 2) {
                    r = j - 1;
                    break;
                }
            }
            ans += (r - i + 1);
        }
        return ans;
    }
    void test() {
        /* test */
    }
};

/**
 * @ScratchPad
 */

#ifdef __TEST__
__TEST__
#endif