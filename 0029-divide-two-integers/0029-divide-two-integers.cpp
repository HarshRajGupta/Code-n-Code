class Solution
{
    public:
        int divide(long long dividend, long long d)
        {
            if (d == 1)
                return dividend;
            if (d == -1)
            {
                if (dividend == -2147483648)
                    return 2147483647;
                return -1 * dividend;
            }
            int sign = 1;
            if (((abs(dividend) != dividend) && (d == abs(d))) || ((abs(dividend) == dividend) && (d != abs(d))))
                sign = -1;

            dividend = abs(dividend);
            d = abs(d);

            if (dividend == d)
                return sign * 1;
            if (dividend < d)
                return 0;

           	// cout << sign << " " << dividend << " " << d << " ";
            long long res = 0, p = 1, m = d, prev = 0;
            while (dividend > m)
            {
                res = p;
                prev = m;
                m *= 2;
                p *= 2;
            }
           	// cout << res << endl;

            return sign *(divide(dividend - prev, d) + res);
        }
};