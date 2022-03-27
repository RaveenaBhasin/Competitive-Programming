class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int x = matrix[mid/n][mid%n];
            if(target == x){
                return true;
            }
            else if(target > x){
                low = mid + 1;
            }
            else if(target < x){
                high = mid - 1;
            }
        }
        return false;
    }
};