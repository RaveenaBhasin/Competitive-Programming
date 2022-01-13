class Solution {
public:
    bool isRowValid(int currentRow, vector<vector<char>>&grid, int n){
        for(int j = 0; j < n; j++){
            if(grid[currentRow][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    bool isColValid(int currentCol, vector<vector<char>>&grid, int n){
        for(int i = 0; i < n; i++){
            if(grid[i][currentCol] == 'Q'){
                return false;
            }
        }
        return true;
    }
    bool areDiagValid(int currentRow, int currentCol, vector<vector<char>>&grid, int n){
        int i, j;
        i = currentRow, j = currentCol;
        while(i >= 0 && j >= 0){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--; 
            j--;
        }
        i = currentRow, j = currentCol;
        while(i >= 0 && j < n){   //Second Diagonal
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }
        i = currentRow, j = currentCol;
        while(i < n && j >= 0){   //Third diagonal
            if(grid[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }
        i = currentRow, j = currentCol;
        while(i < n && j < n){    //Fourth diagonal
            if(grid[i][j] == 'Q'){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    bool isValid(int currentRow, int currentCol, int n, vector<vector<char>>grid){
        return isRowValid(currentRow, grid, n) && isColValid(currentCol, grid, n) && areDiagValid(currentRow, currentCol, grid, n);
    }
    vector<string>populate(vector<vector<char>>&grid, int n){
        vector<string>res;
        for(int currRow = 0; currRow < n; currRow++){
            string temp = "";
            for(int currCol = 0; currCol < n; currCol++){
                temp += grid[currRow][currCol];
            }
            res.push_back(temp);
        }
        return res;
    }
    void nQueens(vector<vector<char>>&grid, int currentRow, int n, vector<vector<string>>&ans){
        if(currentRow == n){
            vector<string>tempAns = populate(grid, n);
            ans.push_back(tempAns);
            return;
        }
        else{
            for(int currentCol = 0; currentCol < n; currentCol++){
                if(isValid(currentRow, currentCol, n, grid)){
                    grid[currentRow][currentCol] = 'Q';
                    nQueens(grid, currentRow + 1, n, ans);
                    grid[currentRow][currentCol] = '.';
                }
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>answer;
        vector<vector<char>>grid(n, vector<char>(n, '.'));
        nQueens(grid, 0, n, answer);
        return answer.size();
    }
};