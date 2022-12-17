class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int sum = 0, MAX = nums[0];
       for(int i: nums) {
           sum += i;
           MAX = max(MAX, sum);
           if (sum < 0) sum = 0;
       }
       return MAX;
    }
};