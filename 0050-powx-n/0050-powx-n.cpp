class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if (n > 0) {
            while(n) {
                if (n&1) {ans *= x;}
                n /= 2;
                x *= x;
            }
            return ans;
        }
        n = abs(n);
        while(n) {
            if (n&1) {ans *= x;}
            n /= 2;
            x *= x;
        }
        return 1/ans;
    }
};