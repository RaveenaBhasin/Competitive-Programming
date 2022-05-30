class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 1 << 31 && divisor == -1)
            return INT_MAX;
        bool sign = true;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            sign = false;
        }
        long a = dividend, b = divisor;
        a = abs(a), b = abs(b);
        long res = 0;
        while(a - b >= 0){
            int count = 0;
            while(a - (b << 1 << count) >= 0){
                count++;
            }
            res += 1 << count;
            a -= b << count;
        }
        if(sign)
            return res;
        
        return -res;
    }
};