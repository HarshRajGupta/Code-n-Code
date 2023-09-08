#include <iostream>
#include <vector>

using namespace std;

int countSubsetsWithSum(vector<int>& arr, int N, int X) {
    vector<vector<int>> dp(N + 1, vector<int>(X + 1, 0));

    for (int i = 0; i <= N; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= X; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j) {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[N][X];
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = countSubsetsWithSum(arr, N, X);
    cout << (result) << endl;

    return 0;
}
