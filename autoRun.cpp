class Solution {

    int xNotY(int x, int y, int n) {
        return ((n / x) - (n / ((x * y) / __gcd(x, y))));
    }
    int notXY(int x, int y, int n) {
        return (n - (n / x) - (n / y) + (n / ((x * y) / __gcd(x, y))));
    }

    int tot(int x, int y, int n, int u1, int u2) {
        int ans = notXY(x, y, n);
        if (u1 + u2 < ans) return 1;
        ans += min(u1, xNotY(y, x, n));
        ans += min(u2, xNotY(x, y, n));
        // debug(x, y, n, u1, u2, xNotY(x, y, n), xNotY(y, x, n), notXY(x, y, n), ans)
        if (u1 + u2 < ans) return 1;
        if (u1 + u2 > ans) return -1;
        return 0;
    }
public:
    int minimizeSet(int d1, int d2, int u1, int u2) {
        int l = 0, r = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2;
            int c = tot(d1, d2, mid, u1, u2);
            if (c == 1) {
                r = mid - 1;
            } else if (c == -1) {
                l = mid + 1;
            } else {
                r = mid;
                break;
            }
        }
        int ans = max(l, r);
        for (int i = ans - 1; i >= 1; --i) {
            int a = tot(d1, d2, i, u1, u2);
            if (a >= 0)
                ans = i;
            else break;
        }
        return ans;
    }
};