//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int func(int w, int pos, vector<vector<int>> &dp, int val[], int wt[]) {
        if ( w == 0 || pos < 0)
            return 0;

        if (dp[pos][w] != -1)
            return dp[pos][w];

        if (w >= wt[pos])
            return dp[pos][w] = max(func(w, pos - 1, dp, val, wt), func(w - wt[pos], pos - 1, dp, val, wt) + val[pos]);

        return dp[pos][w] = func(w, pos - 1, dp, val, wt);
    }
public:
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n, vector<int>(1e4 + 7));
        return func(W, n - 1, dp, val, wt);
    }
};

//{ Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;

    }
    return 0;
}
// } Driver Code Ends