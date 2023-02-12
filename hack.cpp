template <class T> using xHeap = std::priority_queue<T>;

class Solution {
    map<int, map<int, int>> mp;
    int ans(vector<int>& nums, int k, int p, int n) {
        if (k == 0) return p;
        if (n >= nums.size()) return INT_MAX;
        if (mp[n][p] != 0) return mp[n][p];
        if (nums.size() - n - k == k - 1) {
            int res = ans(nums, k - 1, max(p, nums[n]), n + 2);
            return mp[n][p] = res;
        }
        if (nums.size() - n - k >= k) {
            int res = min(ans(nums, k, p, n + 1), ans(nums, k - 1, max(p, nums[n]), n + 2));
            return mp[n][p] = res;
        }
        return INT_MAX;
    }
    int res(const vector<int>& nums, int k) {
        if (k == 0 || nums.size() == 0) return 0;
        if (k == 1 && nums.size() == 1) return nums[0];
        xHeap<pair<int, int>> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp.push({nums[i], i});
        }
        int left = nums.size() - (k + k - 1);
        vector<int> visited(nums.size());
        for (int i = 0; i < left; ++i) {
            visited[mp.top().second] = 1;
            mp.pop();
        }
        // debug(visited)
        int p = 0, MAX = 0;
        while (p < nums.size()) {
            int l = p, r = p;
            vector<int> z;
            while (l < nums.size() && visited[l]) {
                ++l;
                ++r;
            }
            while (r < nums.size() && visited[r] == 0) {
                ++r;
                z.push_back(nums[r]);
            }
            p = r;
            MAX = max(MAX, res(z, (z.size() + 1) / 2));
        }
        return MAX;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        // return ans(nums, k, 0, 0);
        return res(nums, k);
    }
};