class Solution 
{ 
    public int countSubstrings(String s) {
        int ans = s.length();
         int[][] arr = new int[s.length()][s.length()];
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