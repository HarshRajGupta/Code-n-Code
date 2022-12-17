class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i = 0; i < numRows; ++i) {
            vector<int> ele(i+1);
            ele[0] = 1;
            ele[i] = 1;
            for(int j = 0; j < i-1; ++j) {
                ele[j+1] = res[i-1][j] + res[i-1][j+1];
            }
            res[i] = ele;
        }
        return res;
    }
};