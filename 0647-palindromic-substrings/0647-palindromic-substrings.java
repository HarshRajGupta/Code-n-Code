class Solution 
{ 
    int[][] arr = new int[1007][1007];
    boolean isPalindrome(String s, int l, int r) {
		// System.out.println(l + " " + r);
		if (l >= r || l >= s.length() || r < 0)
			return true;
		// if (arr[l][r] != 0)
		// 	return arr[l][r] == 1;
		if (s.charAt(l) != s.charAt(r)) {
			// arr[l][r] = -1;
			return false;
		}
		if (isPalindrome(s, l + 1, r - 1)) {
			// arr[l][r] = 1;
			return true;
		} else {
			// arr[l][r] = -1;
			return false;
		}
	}
    public int countSubstrings(String s) {
        int ans = 0;
        for (int i = 0; i < s.length(); ++i) {
			for (int j = i + 1; j <= s.length(); ++j) {
				if (isPalindrome(s, i, j - 1)) {
					++ans;
				}
			}
		}
		return ans;
    }
} 