class Solution {
    string mp[8] = {
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    vector<string> allStr(const string &digits, int pos, vector<string> &ans) {
        if (pos == digits.size())
            return ans;
        vector<string> res;
        for(auto s : ans) {
            for(auto i : mp[digits[pos]-'2']) {
                
                res.push_back(s+i);
            }
        }
        return allStr(digits, pos+1, res);
    }
public:
    vector<string> letterCombinations(const string &digits) {
        if (digits.size() == 0)
            return vector<string>(0);
        vector<string> res = {""};
        return allStr(digits, 0, res);
    }
};