class NumMatrix {
    vector<vector<int>>res;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        res.assign(matrix.size(), vector<int>(matrix[0].size()+1, 0));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                res[i][j+1] = res[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1; i <= row2; i++){
            ans += res[i][col2+1] - res[i][col1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */