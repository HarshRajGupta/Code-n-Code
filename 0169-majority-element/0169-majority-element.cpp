class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0, cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (cnt == 0) ele = nums[i];
            if (nums[i] == ele) ++cnt;
            if (nums[i] != ele) --cnt;
        }
        return ele;
    }
};