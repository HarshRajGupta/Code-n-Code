class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {
            vector < int> posi(26, -1);
            for(int i = 0; i < s.size(); ++i) {
                posi[s[i]-'a'] = i;
            }
            int r = 0, p = -1;
            vector<int> ans;
            for(int i = 0; i < s.size(); ++i) {
                r = max(r, posi[s[i]-'a']);
                if (r == i) {
                    ans.push_back(r-p);
                    p = r;
                }
            }
            return ans;
        }
};