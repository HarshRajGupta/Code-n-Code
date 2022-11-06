class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(long long i = 0; i < (1ll<<nums.size()); ++i) {
            vector<int> t;
            for(int j = 0; j < nums.size(); ++j) {
                if (i&(1ll<<j)) {
                    t.push_back(nums[j]);
                }
            }
            res.push_back(t);
        }
        return res;
    }
};