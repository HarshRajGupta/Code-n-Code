#include <bits/stdc++.h>
using namespace std;

vector<int> dist(1005);

class Solution {
    int dist[100005], pushed[100005];
    queue<int> visitMe;
    map<int, vector<int>> mp;

    void bfs(vector<int>& arr, int pos) {
        if (pos == arr.size() - 1) {
            while (!visitMe.empty()) visitMe.pop();
            return;
        }
        if (pos > 0 && !pushed[pos - 1]) {
            pushed[pos - 1] = 1;
            dist[pos - 1] = min(dist[pos - 1], dist[pos] + 1);
            visitMe.push(pos - 1);
        }
        if (pos < arr.size() && !pushed[pos + 1]) {
            pushed[pos + 1] = 1;
            dist[pos + 1] = min(dist[pos + 1], dist[pos] + 1);
            visitMe.push(pos + 1);
        }
        for (auto i : mp[arr[pos]]) {
            if (!pushed[i]) {
                pushed[i] = 1;
                dist[i] = min(dist[i], dist[pos] + 1);
                visitMe.push(i);
            }
        }
    }
public:
    int minJumps(vector<int> arr) {
        for (int i = 0; i < arr.size(); ++i) {
            dist[i] = 1e5;
            mp[arr[i]].push_back(i);
        }
        dist[0] = 0;
        pushed[0] = 1;
        visitMe.push(0);
        while (!visitMe.empty()) {
            int visiting = visitMe.front();
            visitMe.pop();
            bfs(arr, visiting);
        }
        return dist[arr.size() - 1];
    }
};

void solve(void) {
    Solution __S;
    cout << __S.minJumps({80, -86, 40, 12, 40, -98, 12, -86, -79, -4, -79, 71, 44, -43, -9, -88, 88, -43, 31, 4, 71, -86, 55, -9, -65});
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