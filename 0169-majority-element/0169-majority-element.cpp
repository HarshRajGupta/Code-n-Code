class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = 0, cnt = 0;
        for(int i : nums) {
            if (cnt == 0) ele = i;
            if (i == ele) cnt++;
            if (i != ele) cnt--;
        }
        return ele;
    }
};