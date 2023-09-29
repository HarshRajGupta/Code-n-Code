class Solution {
    boolean canEat(int[] piles, int k, int h) {
        for(int i : piles) {
            h -= (i/k);
            if (i%k != 0) --h;
        }
        return h >= 0;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int l = 1, r = 1000000007, ans = 1000000007;
        while(l <= r) {
            int mid = (l+r) >> 1;
            if (canEat(piles, mid, h)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
}