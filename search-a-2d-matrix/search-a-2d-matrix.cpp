class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        if(matrix.empty()){
            return false;
        }
        int start = 0, end = m*n - 1; 
        while(start <= end){
            int mid = start + (end - start)/2; 
            int i = matrix[mid/n][mid%n];       
            if(target == i){
                return true;
            }
            if(target > i){
                start = mid + 1;
            }
            if(target < i){
                end = mid - 1;
            }
        }
        return false;
        
    }
};