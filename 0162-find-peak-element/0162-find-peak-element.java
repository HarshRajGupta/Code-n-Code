class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length;
        while(l < r) {
            int mid = (l + r) >> 1;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                r = mid - 1;
            } else if (mid < nums.length - 1 && nums[mid + 1] > nums[mid]) {
                l = mid + 1;
            } else {
                return mid;
            }
        }
        return l;
    }
}