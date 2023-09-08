#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubsetsWithSum(vector<int>& arr, int N, int X) {
    unordered_map<int, int> dp;
    dp[0] = 1;
    int count = 0, currentSum = 0;

    for (int i = 0; i < N; ++i) {
        currentSum += arr[i];
        if (dp.find(currentSum - X) != dp.end()) {
            count += dp[currentSum - X];
        }
        dp[currentSum]++;
    }

    return count;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = countSubsetsWithSum(arr, N, X);
    cout << result << endl;

    return 0;
}
