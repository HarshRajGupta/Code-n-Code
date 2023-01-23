class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        for(int i = 0; i < m.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                int t = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = t;
            }
        }
        for(int i = 0; i < m.size(); ++i) {
            
            reverse(m[i].begin(), m[i].end());
        }
    }
};