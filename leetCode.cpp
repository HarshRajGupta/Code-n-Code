#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeGreatness(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = 0, ans = 0;
        while (i < n && j < n) {
            if (nums[j] > nums[i]) {
                ++i; ++j; ++ans;
            } else ++j;
        }
        return ans;
    }
};

void solve(void) {
    Solution __S;
    cout << __S.maximizeGreatness({7, 7, 7, 7, 7, 7, 7, 11});
}

signed main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifdef __TAG1
    __TAG1
#endif
    solve();
#ifdef __TAG2
    __TAG2
#endif
    return 0;
}