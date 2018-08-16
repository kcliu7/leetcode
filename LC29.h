class Solution {
public:
    int divide(int dividend, int divisor) {
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        if(m<n) return 0;
        while(m >= n){
            long long t = n, p = 1;
            while(m > (t<<1)){
                p <<= 1;
                t <<= 1;
            }
            m -= t;
            res += p;
        }
        res = (dividend < 0) ^ (divisor < 0) ? -res : res;
        return (res>INT_MAX) ? INT_MAX : res;
    }
};