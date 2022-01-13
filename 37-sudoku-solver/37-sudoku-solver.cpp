class Solution {
public:
    bool isValidCell(vector<vector<char>>&board, int currentRow, int currentCol, int currentVal){
        return isRowValid(board, currentRow, currentVal) && isColValid(board, currentCol, currentVal) && isValidSubgrid(board, currentRow, currentCol, currentVal);
    }
    
    bool isRowValid(vector<vector<char>>&board, int currentRow, int currentVal){
        for(int i = 0; i < 9; i++){
            if(board[currentRow][i] == char(currentVal + '0')){
                return false;
            }
        }
        return true;
    }
    
    bool isColValid(vector<vector<char>>&board, int currentCol, int currentVal){
        for(int i = 0; i < 9; i++){
            if(board[i][currentCol] == char(currentVal + '0')){
                return false;
            }
        }
        return true;
    }
    
    bool isValidSubgrid(vector<vector<char>>&board, int currentRow, int currentCol, int currentVal){
        int x = 3*(currentRow/3);
        int y = 3*(currentCol/3);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[x+i][y+j] == char(currentVal + '0')){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool sudokoSolver(vector<vector<char>>&board, int currentRow, int currentCol){
        if(currentRow == 9){
            return true;
        }
        int nextRowPos, nextColPos;
        if(currentCol == 9){
            nextRowPos = currentRow + 1;
            nextColPos = 0;
        }
        else{
            nextRowPos = currentRow;
            nextColPos = currentCol + 1;
        }
        if(board[currentRow][currentCol] != '.'){
            return sudokoSolver(board, nextRowPos, nextColPos);
        }
        for(int currVal = 1; currVal < 10; currVal++){
            if(isValidCell(board, currentRow, currentCol, currVal)){
                board[currentRow][currentCol] = char(currVal + '0');
                if(sudokoSolver(board, nextRowPos, nextColPos) == true){
                    return true;
                }
                board[currentRow][currentCol] = '.';
            }
        }
        return false; 
    }
    void solveSudoku(vector<vector<char>>& board) {
        sudokoSolver(board, 0, 0);
        return;
    }
};