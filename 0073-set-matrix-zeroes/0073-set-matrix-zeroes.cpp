class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
       vector<int> rows(m.size()), cols(m[0].size());
        for(int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[0].size(); ++j) {
                if (m[i][j] == 0) {
                    rows[i] = cols[j] = 1;
                }
            }
        }
        for(int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[0].size(); ++j) {
                if (rows[i] || cols[j]) {
                    m[i][j] = 0;
                }
            }
        }
    }
};