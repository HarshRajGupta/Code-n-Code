//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int MAX = 0;
    int ans(vector<int> &arr, vector<vector<int>> &dp, int prev = 0, int pos = 0, int sum = 0) {
        if (pos == arr.size()) {
            MAX = max(MAX, sum);
            return sum;
        }
        if (dp[pos][prev] != -1) {
            return dp[pos][prev];
        }
        if (prev == 0 || arr[pos] > arr[prev - 1]) {
            return dp[pos][prev] = max(ans(arr, dp, prev, pos + 1, sum), ans(arr, dp, pos + 1, pos + 1, sum + arr[pos]));
        }
        return dp[pos][prev] = ans(arr, dp, prev, pos + 1, sum);
    }
public:
    int maxSumIS(int arr[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        vector<int> Arr(n);
        for (int i = 0; i < n; ++i) Arr[i] = arr[i];
        ans(Arr, dp);
        return MAX;
    }
};

//{ Driver Code Starts.
int main()
{


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];



        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";

    }
    return 0;
}


// } Driver Code Ends