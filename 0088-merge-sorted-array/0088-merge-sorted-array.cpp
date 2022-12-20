class Solution {
    void shift(vector<int>& num, int index, int &aco) {
        for(int i = aco; i > index; --i) {
            num[i] = num[i-1];
        }
        aco++;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, s = m;
        while(i < m || j < n) {
            if (i < m && j < n) {
                if (nums1[i] > nums2[j]) {
                    shift(nums1, i, m);
                    nums1[i] = nums2[j++];
                    ++i;
                } else ++i;
            } else if (j < n) {
                shift(nums1, i, m);
                nums1[i] = nums2[j++];
                ++i;
            } else break;
        }
    }
};