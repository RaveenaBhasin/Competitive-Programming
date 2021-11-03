class Solution {
public:
    double myPow(double x, int n) {
        //Keeping the value of n in another variable because in the algorithm the value of n will get destroyed
        long num = n;
        double res = 1.0;
        if(num < 0){
            num = -num;   //Making it a positive value
        }
        while(num > 0){   //Continuing the algorithm untill num becomes 0
            if(num % 2 == 1){  //Odd power
                res = res * x;
                num--;
            }
            else{   //Even power
                x = x * x;
                num = num/2;
            }
        }
        if(n<0){
            res = (double)(1.0)/(double)(res);
        }
        return res;
    }
};
//Time Complexity: O(logn) Space complexity: O(1)