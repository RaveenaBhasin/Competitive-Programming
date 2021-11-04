class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
//Idea is to create a row and column vector to store if they contain any zero and use that to put zeros
        int n = matrix.size();
        int m = matrix[0].size();
        vector<bool>row(n);
        vector<bool>col(m);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]==0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(row[i]==true or col[j]==true){
                    matrix[i][j]=0;
                }
            }
        }
    }
};
/*T.C: O(n*m + n*m)    S.C: O(n+m)
          |     |
    traversing  putting 0's*/