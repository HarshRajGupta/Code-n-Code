class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int slow = nums[0], fast = nums[0];
        // do {
        //     slow = nums[slow];
        //     fast = nums[nums[fast]];
        //     // cout << slow << " " << fast << endl;
        // } while(slow != fast);
        // fast = nums[0];
        // while(fast != slow) {
        //     slow = nums[slow];
        //     fast = nums[fast];
        // }
        // return fast;
        bitset<100007> a;
        for(int i : nums) {
            if(a[i]) return i;
            a[i] = 1;
        }
        return 0;
    }
};