class Solution {
    void shift(vector<int>& num, int index, int &aco) {
        for(int i = aco; i > index; --i) {
            num[i] = num[i-1];
        }
        aco++;
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = 0, j = 0, s = m;
        // while(i < m || j < n) {
        //     if (i < m && j < n) {
        //         if (nums1[i] > nums2[j]) {
        //             shift(nums1, i, m);
        //             nums1[i] = nums2[j++];
        //             ++i;
        //         } else ++i;
        //     } else if (j < n) {
        //         shift(nums1, i, m);
        //         nums1[i] = nums2[j++];
        //         ++i;
        //     } else break;
        // }
        for(int i = 0; i < n; ++i) {
            nums1[i+m] = nums2[i];
        }
        for(int i = (n+m+1)/2; i > 1;) {
            for (int j = 0; j+i < (n+m); ++j) {
                if (nums1[j+i] < nums1[j]) {
                    int t = nums1[j];
                    nums1[j] = nums1[i+j];
                    nums1[i+j] = t;
                }
            }
            i = (i+1)/2;
        }
        for (int j = 0; j+1 < (n+m); ++j) {
                if (nums1[j+1] < nums1[j]) {
                    int t = nums1[j];
                    nums1[j] = nums1[1+j];
                    nums1[1+j] = t;
                }
            }
    }
};