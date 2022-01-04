class Solution {
public:
    int bitwiseComplement(int n) {
        int complement = 1;
        while(complement < n){
            complement = (complement << 1) | 1;
        }
        return n^complement;
    }
};
