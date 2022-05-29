class Solution {
public:
    int numberOfSteps(int num) {
        return num ? log2(num) + __builtin_popcount(num) : 0;
    }
};
