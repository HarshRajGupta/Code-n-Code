class Solution {
public:
    int countSubstrings(string s) {
        int ans = s.length();
        for(int i = 0; i < s.length(); ++i) {
            int l = i, r = i + 1;
            while(l >= 0 && r < s.length() && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
            l = i - 1; r = i + 1;
            while(l >= 0 && r < s.length() && s[l] == s[r]) {
                --l;
                ++r;
                ++ans;
            }
        }
        return ans;
    }
};