#include <bits/stdc++.h>
using namespace std;

int minIndex(const int startTime, const vector<int> &free) {
    int MIN = 0;
    for (unsigned int i = 0; i < free.size(); ++i) {
        if (free[i] <= startTime)
            return i;
        if (free[i] < free[MIN])
            MIN = i;
    }
    return MIN;
}

int mostBooked(int n, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    vector<int> room(n, 0), free(n, 0);
    for (auto i : meetings) {
        int pos = minIndex(i[0], free);
        if (free[pos] <= i[0])
            free[pos] = i[1];
        else
            free[pos] += i[1] - i[0];
        ++room[pos];
    }
    int MAX = 0;
    for (int i = 0; i < n; ++i) {
        if (room[i] > room[MAX])
            MAX = i;
    }
    return MAX;
}

void solve() {
    vector<vector<int>> s = {{18, 19}, {3, 12}, {17, 19}, {2, 13}, {7, 10}};
    cout << mostBooked(4, s);
}

signed main(int argc, char const *argv[]) {
    int testCase;
    cin >> testCase;
    while (testCase--)
        solve();
    return 0;
}