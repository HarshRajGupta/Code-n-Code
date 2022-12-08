class Solution {
    vector<int> visit;
     bool palindrome(string &s, vector<vector<int>> &pre, int &pos, int &len)
    {
        int odd = 0;
        for (auto i : visit)
        {
            if (((pre[pos + len][i] - pre[pos][i]) & 1) && odd)
                return false;
            if ((pre[pos + len][i] - pre[pos][i]) & 1)
                odd = 1;
        }
        string str = s.substr(pos, len);
        for(int i = 0; i < len/2; ++i) {
            if (str[i] != str[len-1-i])
            return false;
        }
        return true;
    }

public:
    string longestPalindrome(string s)
    {
        vector<vector<int>> preCompute(s.length() + 1, vector<int>(257, 0));
        set<int> chars;
        for (int i = 0; i < s.size(); i++)
        {
            chars.insert(s[i] +128);
            preCompute[i + 1] = preCompute[i];
            preCompute[i + 1][s[i] +128]++;
        }
        for(auto i : chars) {
            visit.push_back(i);
        }
        int len = 1, pos = 0;
        for(int i = 0; i < s.size(); i++) {
            for(int j = len+1; j < s.size()-i+1; ++j) {
                if (palindrome(s, preCompute, i, j))
                    pos = i, len = j;
            }
        }
        return s.substr(pos, len);
    }
};