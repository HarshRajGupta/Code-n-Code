class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> inv(10007), partialSum(10007);
        set<int> sing;
        for(auto i: intervals) {
            partialSum[i[0]]++;
            partialSum[i[1]]--;
            if (i[0] == i[1]) sing.insert(i[0]);
        }
        int prev = 0;
        for(int i =0; i < 10007; ++i) {
            prev += partialSum[i];
            inv[i] = prev;
        }
        // for(int i : inv) cout << i << " ";
        vector<vector<int>> ans;
        for(int i = 0; i < 10007; ++i) {
            if (inv[i] > 0) {
                vector<int> e = {i};
                ++i;
                while(inv[i] != 0 && i < 10007) ++i;
                e.push_back(i);
                inv[i] = 1;
                // for(int i : e) cout << i << " ";
                // cout << endl;
                ans.push_back(e);
            }
        }
        for(auto i : sing) {
            if (inv[i] == 0) ans.push_back({i, i});
        }
        return ans;
    }
};