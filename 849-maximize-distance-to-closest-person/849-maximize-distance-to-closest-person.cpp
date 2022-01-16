class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int length = seats.size(), i = 0, j, res = 0;
        bool flag;
        while (i < length) {
            while (i < length && seats[i]){
                i++;
            }
            j = i + 1;
            while (j < length && !seats[j]){
                j++;
            }
            flag = i && j != length;
            res = max(res, (j - i + flag) / (1 + flag));
            i = j;
        }
        return res;
    }
};