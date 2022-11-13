class Solution
{
    public:
        vector<int> partitionLabels(string s)
        {
            vector<vector < int>> posi(26), preCompute(s.size(), vector<int> (26));
            vector<int> prev(26), lastPos(26), res;
            for (int i = 0; i < s.size(); ++i)
            {
                posi[s[i] - 'a'].push_back(i);
                prev[s[i] - 'a']++;
                preCompute[i] = prev;
                lastPos[s[i]-'a'] = i;
            }
            string t = s;
            int pos = 0, cnt = 0, MAX = 0;
            while(pos < s.size()) {
                int MAX = max(MAX, lastPos[s[pos]-'a']);
                pos++;
                cnt++;
                cout << pos << " "<< MAX << '\n';
                if (MAX < pos) {
                    res.push_back(cnt);
                    cnt = 0;
                }
            }
            return res;
        }
};