#include <iostream>
#include <vector>
#include <climits>

struct SegmentTreeNode {
    int minVal;
    int maxVal;
};

class SegmentTree {
private:
    std::vector<SegmentTreeNode> tree;
    int n;

    void buildTree(const std::vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node].minVal = arr[start];
            tree[node].maxVal = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, 2 * node + 1, start, mid);
            buildTree(arr, 2 * node + 2, mid + 1, end);
            tree[node].minVal = std::min(tree[2 * node + 1].minVal, tree[2 * node + 2].minVal);
            tree[node].maxVal = std::max(tree[2 * node + 1].maxVal, tree[2 * node + 2].maxVal);
        }
    }

    std::pair<int, int> query(int node, int start, int end, int left, int right) {
        // If the current segment is outside the query range
        if (start > right || end < left)
            return std::make_pair(INT_MAX, INT_MIN);

        // If the current segment is completely inside the query range
        if (start >= left && end <= right)
            return std::make_pair(tree[node].minVal, tree[node].maxVal);

        // If the current segment partially overlaps with the query range
        int mid = (start + end) / 2;
        std::pair<int, int> leftResult = query(2 * node + 1, start, mid, left, right);
        std::pair<int, int> rightResult = query(2 * node + 2, mid + 1, end, left, right);
        return std::make_pair(std::min(leftResult.first, rightResult.first), std::max(leftResult.second, rightResult.second));
    }

public:
    SegmentTree(const std::vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }

    std::pair<int, int> findMinMax(int left, int right) {
        if (left < 0 || right >= n || left > right)
            return std::make_pair(INT_MAX, INT_MIN);
        return query(0, 0, n - 1, left, right);
    }
};

int main() {
    std::vector<int> arr = {0, 3, 5, 8, 1, 2, 6};
    SegmentTree segmentTree(arr);

    // Example queries
    std::pair<int, int> result1 = segmentTree.findMinMax(1, 4);
    std::pair<int, int> result2 = segmentTree.findMinMax(2, 6);

    std::cout << "Minimum and Maximum of subarray [1, 4]: " << result1.first << ", " << result1.second << std::endl;
    std::cout << "Minimum and Maximum of subarray [2, 6]: " << result2.first << ", " << result2.second << std::endl;

    return 0;
}
