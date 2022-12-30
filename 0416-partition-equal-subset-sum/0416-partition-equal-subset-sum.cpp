class Solution {
    int sum = 0;
    
public:
    bool canPartition(vector<int>& nums) {
        for(int i : nums)
            sum += i;
        if (sum&1)
            return false;
        sum /= 2;
        set<int> a = {0};
        for(int i = 0; i < nums.size(); ++i) {
            auto b = a;
            for(int j : a) {
                if (j + nums[i] > sum) {
                    break;
                }
                if (j + nums[i] == sum) {
                    return true;
                }
                b.insert(j + nums[i]);
            }
            a = b;
        }
        return false;
    }
};