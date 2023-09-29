class Solution 
{ 
    int[][] arr = new int[1007][1007];
    boolean isPalindrome(String s, int l, int r) {
		// System.out.println(l + " " + r);
		if (l >= r || l >= s.length() || r < 0)
			return true;
		if (arr[l][r] != 0)
			return arr[l][r] == 1;
		if (s.charAt(l) != s.charAt(r)) {
			arr[l][r] = -1;
			return false;
		}
		if (isPalindrome(s, l + 1, r - 1)) {
			arr[l][r] = 1;
			return true;
		} else {
			arr[l][r] = -1;
			return false;
		}
	}
    public int countSubstrings(String s) {
        int ans = s.length();
        // for (int i = 0; i < s.length(); ++i) {
		// 	for (int j = i + 1; j <= s.length(); ++j) {
		// 		if (isPalindrome(s, i, j - 1)) {
		// 			++ans;
		// 		}
		// 	}
		// }
        for(int i = 0; i < s.length() - 1; ++i) {
            arr[i][i] = 1;
            if (s.charAt(i) == s.charAt(i + 1)) {
                arr[i][i + 1] = 1;
                ++ans;
            }
        }
        for(int i = 2; i < s.length(); ++i) {
            for(int j = 0; j < s.length() - i; ++j) {
                if (s.charAt(j) == s.charAt(j + i) && (arr[j + 1][j + i - 1] == 1)) {
                    ++ans;
                    arr[j][j + i] = 1;
                }
            }
        }
		return ans;
    }
} 