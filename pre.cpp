#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> p(n);
    map<int, int> pos; // maps each element in p to its position
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int moves = 0;
    for (int i = 0; i < m - 1; i++) {
        int cur_pos = pos[a[i]];
        int next_pos = pos[a[i + 1]];
        int distance = next_pos - cur_pos;
        if (distance > d) {
            moves += distance - 1;
        }
    }
    cout << moves << endl;
    return 0;
}