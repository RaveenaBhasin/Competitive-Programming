class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = matrix.size(), end = matrix[0].size();
        int i = 0, j = end-1;
        while(i < start && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            else if(target > matrix[i][j]){
                i++;  //increase the row index
            }
            else{
                j--;   // decrease the column index
            }
        }
        return false;

    }
};

