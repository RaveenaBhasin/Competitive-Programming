class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res(numRows);     //Create an empty dynamic array
        for(int i = 0; i < numRows; i++){    //For every column
            res[i].resize(i+1);              //Resize the row size
            res[i][0] = res[i][i]=1;         //Initialise the first and last element as 1
            for(int j = 1; j < i; j++){      //Linearly traverse from 1st column to 2nd last column
                res[i][j] = res[i-1][j-1] + res[i-1][j];    //Adding element of previous row
            }
        }
        return res;
    }
};
//T.C : O(numRows^2)    S.C : O(numRows^2)