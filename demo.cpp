#include <iostream>
#include <vector>
#include <climits>

std::vector<std::pair<int, int>> precomputeMinMax(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<std::pair<int, int>> precomputedMinMax(n);

    // Initialize the precomputedMinMax array
    for (int i = 0; i < n; i++) {
        precomputedMinMax[i].first = INT_MAX;  // Initialize minimum to maximum value
        precomputedMinMax[i].second = INT_MIN; // Initialize maximum to minimum value
    }

    // Precompute the minimum and maximum values for each subarray
    for (int i = 0; i < n; i++) {
        int currentMin = arr[i];
        int currentMax = arr[i];
        for (int j = i; j < n; j++) {
            currentMin = std::min(currentMin, arr[j]);
            currentMax = std::max(currentMax, arr[j]);
            precomputedMinMax[j].first = std::min(precomputedMinMax[j].first, currentMin);
            precomputedMinMax[j].second = std::max(precomputedMinMax[j].second, currentMax);
        }
    }

    return precomputedMinMax;
}

std::pair<int, int> findMinMax(const std::vector<std::pair<int, int>>& precomputedMinMax, int left, int right) {
    return std::make_pair(precomputedMinMax[right].first, precomputedMinMax[left].second);
}

int main() {
    std::vector<int> arr = {0, 3, 5, 8, 1, 2, 6};
    std::vector<std::pair<int, int>> precomputedMinMax = precomputeMinMax(arr);

    // Example queries
    std::pair<int, int> result1 = findMinMax(precomputedMinMax, 1, 4);
    std::pair<int, int> result2 = findMinMax(precomputedMinMax, 2, 6);

    std::cout << "Minimum and Maximum of subarray [1, 4]: " << result1.first << ", " << result1.second << std::endl;
    std::cout << "Minimum and Maximum of subarray [2, 6]: " << result2.first << ", " << result2.second << std::endl;

    return 0;
}
