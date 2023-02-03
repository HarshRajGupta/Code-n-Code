#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, a[1005];
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = 0, sum = 0, neg_count = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (a[i] < 0)
                neg_count++;
            if (neg_count % 2 == 0)
                ans = max(ans, sum);
            else
                sum = 0;
        }
        neg_count = 0;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (a[i] < 0)
                neg_count++;
            if (neg_count % 2 != 0)
                ans = max(ans, sum);
            else
                sum = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
