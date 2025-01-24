class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1)
            return 1.0;
        if(x==-1)
        {
            if(n%2==0)
            {
            cout<<\return\;
                return 1.0;
            }else return -1.0;

        }
        double result = 1.0;
        bool negative = false;
        long long n_long = n;
        if (n < 0) {
            n_long = -n_long;
            negative = true;
        }
        while (n_long > 0) {
            if (n_long % 2 == 1) {
                result *= x;
            }
            x *= x;
            n_long /= 2;
        }
        if (negative) {
            return 1.0 / result;
        } else
            return result;
    }
};