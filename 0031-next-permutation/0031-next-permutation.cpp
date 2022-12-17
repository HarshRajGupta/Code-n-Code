class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), MAX = nums[nums.size() - 1];
        multiset<int> mini;
        for (int i = n - 1; i >= 0; --i) {
            mini.insert(nums[i]);
            if (nums[i] < MAX) {
                auto t = mini.upper_bound(nums[i]);
                nums[i] = *t;
                mini.erase(t);
                for (auto j : mini) {
                    nums[++i] = j;
                }
                return;
            }
            MAX = max(MAX, nums[i]);
        }
        int i = 0;
        for (auto j : mini) {
            nums[i++] = j;
        }
    }
};