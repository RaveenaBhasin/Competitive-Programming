class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int carry = a & b;
            a = a ^ b;
            b = (unsigned)carry << 1; //unsigned because left shift operator gives error for negative value
        }
        return a;
    }
};
