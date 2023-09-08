#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int CountSubsetSum(vector<int>& arr, int val, int n) {
	int count = 0;
	vector<int> PresentState(val + 1, 0), LastState(val + 1, 0);
	PresentState[0] = LastState[0] = 1;
	if (arr[0] <= val) LastState[arr[0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= val; j++)
			PresentState[j] =
				((j >= arr[i]) ? LastState[j - arr[i]] : 0) + LastState[j];
		LastState = PresentState;
	}
	return PresentState[val];
}

int countSubsetsWithSum(vector<int>& arr, int N, int X) {
	vector<vector<int>> dp(N + 1, vector<int>(X + 1, 0));

	for (int i = 0; i <= N; ++i) dp[i][0] = 1;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= X; ++j) {
			if (arr[i - 1] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % MOD;
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

	int result = CountSubsetSum(arr, X, N);
	cout << result << endl;

	return 0;
}
