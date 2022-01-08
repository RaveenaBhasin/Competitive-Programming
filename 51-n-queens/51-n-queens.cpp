class Solution {
public:
    bool isRowValid(int currRow, vector<vector<char>>&grid, int n){
        for(int j = 0; j < n; j++){
            if(grid[currRow][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    bool isColValid(int currCol, vector<vector<char>>&grid, int n){
        for(int i = 0; i < n; i++){
            if(grid[i][currCol] == 'Q'){
                return false;
            }
        }
        return true;
    }
    
    bool areDiagValid(int currRow, int currCol, vector<vector<char>>&grid, int n){
        int i, j;
        i = currRow, j = currCol;
        while(i >= 0 && j >= 0){   //Firat Diagonal
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--;
            j--;
        }
        i = currRow, j = currCol;
        while(i >= 0 && j < n){   //Second Diagonal
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--;
            j++;
        }
        i = currRow, j = currCol;
        while(i < n && j >= 0){   //Third diagonal
            if(grid[i][j] == 'Q'){
                return false;
            }
            i++;
            j--;
        }
        i = currRow, j = currCol;
        while(i < n && j < n){    //Fourth diagonal
            if(grid[i][j] == 'Q'){
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
    
    bool isValid(int currRow, int currCol, vector<vector<char>>grid, int n){
        return isRowValid(currRow, grid, n) && isColValid(currCol, grid, n) && areDiagValid(currRow, currCol, grid, n);
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
    
    void nQueens(vector<vector<char>>&grid, int currRow, int n, vector<vector<string>>&ans){
        //Base case: reached to the end of the grid
        if(currRow == n){ 
            vector<string>tempAns = populate(grid, n);
            ans.push_back(tempAns);
            return;
        }
        //else We can place queen at any place in the row
        for(int currCol = 0; currCol < n; currCol++){
            if(isValid(currRow, currCol, grid, n)){
                grid[currRow][currCol] = 'Q';
                nQueens(grid, currRow + 1, n, ans);
                grid[currRow][currCol] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>grid(n, vector<char>(n, '.'));
        nQueens(grid, 0, n, ans);
        return ans;
    }
};