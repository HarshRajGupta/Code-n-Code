class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size()-2; ++i) {
            for(int j = i+1; j < nums.size()-1; ++j) {
                int s = nums[i] + nums[j];
                for(int k = j+1; k < nums.size(); ++k) {
                    if (abs(s+nums[k] - t) < abs(ans - t)) {
                        ans = s + nums[k];
                        if (ans == t)
                            return t;
                    }
                }
            }
        }
        return ans;
    }
};